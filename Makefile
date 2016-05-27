loop_read: loop_read.c
	gcc -std=c99 -W -Wall -g loop_read.c -o loop_read

clean:
	rm -rf loop_read.o loop_read
