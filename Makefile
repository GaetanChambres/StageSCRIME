read: read.c
	gcc -std=c99 -W -Wall -g read.c -o read

clean:
	rm -rf read.o read
