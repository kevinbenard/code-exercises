CC = clang
CFLAGS = -Werror -Wall -pedantic -g

.PHONY: all clean

all: unique_string reverse

unique_string: unique_string.c
	$(CC) $(CFLAGS) unique_string.c -o unique_string

reverse: reverse.c
	$(CC) $(CFLAGS) reverse.c -o reverse

clean:
	rm -f ./unique_string ./reverse *.o
