#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "assert.h"
#include "string.h"

/* reverse takes in a string and reverses it.
 * e.g: ./reverse 'abc' # returns cba
 * e.g: ./reverse 'kevin' # returns nivek 
 */
void swap(char* a, char* b) {
        char tmp = *a;
        *a = *b;
        *b = tmp;
}

void reverse(char* input_string, uint8_t buf_size) {
        uint32_t n = buf_size - 1;

        for (uint32_t i = 0; i < (buf_size/2); ++i) {
                swap(&input_string[i], &input_string[n-i]);
        }
}

int main(int argc, char** argv) {
        char* test_string = NULL;
        uint8_t buf_size = 0;

        if (argc != 2) {
                printf("Incorrect params\n");
                return 1;
        }

        buf_size = strlen(argv[1]);

        if (buf_size > 0) {
                test_string = argv[1];
                reverse(test_string, buf_size);
                printf("%s\n", test_string);
        } else {
                printf("Incorrect params\n");
                return 1;
        }

        return 0;
}
