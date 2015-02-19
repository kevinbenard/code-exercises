#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "assert.h"
#include "string.h"

void swap(char* a, char* b) {
        char tmp = 'a';
        tmp = *a;
        *a = *b;
        *b = tmp;
}

char* reverse(char* input_string, uint8_t buf_size) {
        char* out_string = malloc(sizeof(char) * buf_size);
        uint32_t n = buf_size - 1;

        strncpy(out_string, input_string, buf_size);
        for (uint32_t i = 0; i < (buf_size/2); ++i) {
                swap(&out_string[i], &out_string[n-i]);
        }

        return out_string;
}

int main(int argc, char** argv) {
        char* test_string = argv[1];
        char* out_string = NULL;
        uint8_t buf_size = 0;

        buf_size = strlen(test_string);
        out_string = reverse(test_string, buf_size);
        printf("Out: %s\n", out_string);

        return 0;
}
