CC = clang
CFLAGS = -Werror -Wall -pedantic -g

.PHONY: all clean

all: unique_string

unique_string: unique_string.c
	$(CC) $(CFLAGS) unique_string.c -o unique_string

clean:
	rm -f ./unique_string *.o
