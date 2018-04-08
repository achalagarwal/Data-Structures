/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2016, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
/* 
 * Simple HTTP GET that stores the web file in a local file
 
 Compile: gcc webread.c -lcurl -o mydownloader
 Execute: ./mydownloader
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"
#include <curl/curl.h>
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

int hasDoubleSlash(char* url){
    int i  = 0;
    while(url[i]!='\0'){
        if(url[i]=='/')
            if(url[i+1]=='/')
                return 1;
        i++;
    }
    return 0;
}

 char* completeUrl(char* suffix,char* prefix){
    if(hasDoubleSlash(suffix)==1)
        return suffix;
    int count = 0;
    while(prefix[count]!='\0'){
        count++;
    }
   /* int count2 = 0;
    while(suffix[count2]!='\0'){
        count2++;
    }
    //count2-50
    */
    char* url = (char*)malloc(sizeof(char)*(51+count));
    url[0] = '\0';
    url = strcat(url,prefix);
    url = strcat(url,suffix);
    return url;
   // return strcat(prefix,suffix);
}

int parseHTML(void* stream,char* pre){
    int a = fgetc((FILE*)stream);
    FILE* out = fopen("out.txt","w");
    int index = 0;
    int flag = 0;
    char* url = (char*)malloc(sizeof(char)*50);
    int pos= 0;
    char prefix[6] = "href=\"";
    while(a!=EOF){
        if(flag == 1){
            if(a==(int)'"'){
                url[pos] = '\0';
                pos = 0;
                flag = 0;
                if(hasDoubleSlash(url))
                    fprintf(out,"%s\n",url);
            }
            else{
                url[pos++] =(char)a;
            }
        }
        else if(index == 5){
            index = 0;
            flag = 1;
        }
        else if((char)a == prefix[index])
            index++;
        else
            index =0;
        a = fgetc((FILE*)stream);
    }
    fclose(out);
    return 1;
}

int main(void)
{
  CURL *curl_handle;
  static const char *webfilename = "mylocalfile";
  FILE *webfile;

  curl_global_init(CURL_GLOBAL_ALL);

  /* init the curl session */
  curl_handle = curl_easy_init();

  /* set URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_URL, "https://en.wikipedia.org/wiki/Main_Page");
  /* no progress meter please */
  //curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

  /* open the web file */
  webfile = fopen(webfilename, "wb");
  if(!webfile) {
    curl_easy_cleanup(curl_handle);
    return -1;
  }

  /* we want the body be written to this file handle instead of stdout */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, webfile);

  /* get it! */
  curl_easy_perform(curl_handle);
    
  /* close the web file */
  fclose(webfile);

  FILE* web = fopen("mylocalfile","r");
  printf("%d",parseHTML(web,"https://en.wikipedia.org/wiki/Main_Page\0"));
  fclose(web);

  Graph G = createGraph(10);
  Vertex root = addVertex(G,"https://en.wikipedia.org/wiki/Main_Page\0");
  web = fopen("out.txt","r");
  char* text = (char*)malloc(sizeof(char)*50);
  int a = fscanf(web,"%s",text);
  while(a!=EOF){
      Vertex child = addVertex(G,text);
      if(child!=NULL)
    G = addEdge(G,root,child);
    a = fscanf(web,"%s",text);
  }
  printf("%d\n",degree(G,root)); 
  /* cleanup curl stuff */
  fclose(web);
  curl_easy_cleanup(curl_handle);

  return 0;
}
