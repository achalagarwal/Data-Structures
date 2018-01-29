gcc -c queue.c -o queue.o -g
gcc -c multiq.c -o multiq.o -g
gcc -c driver.c -o driver.o -g
gcc queue.o multiq.o driver.o  -o run -g
./run

