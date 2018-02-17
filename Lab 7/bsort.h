#ifndef LIST
#include"list.h"
#endif
struct bucket{
	List lists;
	};
typedef struct bucket* Bucket;
void add(Bucket b,int a);
Node rem(Bucket b);
Bucket createBucket();
struct bigBucket{
	Bucket buckets;
	};
typedef struct bigBucket* BBucket;
BBucket createBBucket();
Node remB(BBucket b);
void addB(BBucket b, int a);
	
