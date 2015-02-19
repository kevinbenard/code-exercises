/* 
 * A program that takes in a string and returns if it is made
 * up of unique characters. Acceptable characters are: a - z,
 * A - Z.
 *
 * Usage 1: ./unique_string "<string>"
 *          e.g: ./unique_string "bar" # returns 0 (TRUE)
 *          e.g: ./unique_string "foo" # returns 1 (FALSE)
 * Usage 2: ./unique_string "<string>" <expected_boolean>
 *          e.g: ./unique_string "foo" false # returns 0 (TRUE)
 *          e.g: ./unique_string "foo" true # returns 1 (FALSE)
 */
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "assert.h"
#include "string.h"

/* Converts a char into a number between 0 and 25 to
 * line up with the letters of the alphabet */
uint8_t charToNumber(char c) {
        uint8_t UPPER_BOUND_MIN = 65;
        uint8_t UPPER_BOUND_MAX = 90;
        uint8_t LOWER_BOUND_MIN = 97;
        uint8_t LOWER_BOUND_MAX = 122;
        uint8_t char_offset = 65;
        uint8_t out = 0;

        if (c >= UPPER_BOUND_MIN && c <= UPPER_BOUND_MAX) {
                char_offset = UPPER_BOUND_MIN;
        } else if (c >= LOWER_BOUND_MIN && c <= LOWER_BOUND_MAX){
                char_offset = LOWER_BOUND_MIN;
        } else {
                fprintf(stderr, "ABORTING! Character outside of "\
                                "accepted range!\n");
                exit(1);
        }

        out = (c - char_offset);

        return out;
}

/* Returns true if all characters in input string are unique,
 * false otherwise 
 */
bool is_unique(char* input_string, uint32_t len) {
        uint32_t count_array[26] = {0};
        uint8_t offset = 0;
        char c = 'A';
        bool out = true;

        for (uint8_t i = 0; i < len; ++i) {
                offset = charToNumber(input_string[i]);
                count_array[offset] += 1;

                if (count_array[offset] > 1) {
                        out = false;
                }
        }

        for (uint8_t i = 0; i < 26; ++i) {
                printf("%c:%d ", c, count_array[i]);
                c += 1;
        }
        printf("\n");
        if (out) {
                printf("%s is unique!\n", input_string);
        } else {
                printf("%s has duplicates!\n", input_string);
        }

        return out;
}

/* Same as is_unique, but without using any extra storage space */
bool is_unique_alt(char* input_string, uint32_t len) {
        uint32_t storage = 0;
        uint32_t offset = 0;
        bool out = true;

        for (uint32_t i = 0; i < len; ++i) {
                offset = charToNumber(input_string[i]);

                if ((storage & (1 << offset)) > 0) {
                        out = false;
                } else {
                        storage = storage | (1 << offset);
                }
        }

        return out;
}

/* Function to run and check the output */
bool expect(bool (*uniqueFunc)(char*, uint32_t), char* input_string, 
                uint32_t len, bool expected_output) {
        bool output = false;
        bool ret = false;

        /* If the length of the string is > 26 it has to have duplicates */
        if (len > 26) {
                printf("'%s' FAILS\n", input_string);
                ret = false;
        }

        output = (*uniqueFunc)(input_string, len);

        if (output == expected_output) {
                printf("'%s' PASSES\n", input_string);
                ret = true;
        } else {
                printf("'%s' FAILS\n", input_string);
                ret = false;
        }

        return ret;
}

/* Takes first parameter and tests if it has unique letters */
/* Returns 0 on success and 1 otherwise */
int main(int32_t argc, char** argv) {
        char* test_string = NULL;
        uint32_t len = 0;
        bool out = false;
        bool test = true;

        /* Just entered a string to test */
        if (argc == 2) {
                test_string = argv[1];
        /* Entered a string to test and an expected result (true/false) */
        } else if (argc == 3) {
                test_string = argv[1];
                if (strcmp(argv[2], "true") == 0) {
                        test = true;
                } else if (strcmp(argv[2], "false") == 0) {
                        test = false;
                } else {
                        fprintf(stderr, "Incorrect params!\n");
                        return 1;
                }
        /* Incorrect params */
        } else {
                fprintf(stderr, "Incorrect params!\n");
                return 1;
        }

        len = strlen(test_string);
        if (len > 0) {
                /* out = expect(is_unique, test_string, len, test); */
                out = expect(is_unique_alt, test_string, len, test);
        } else {
                return 1;
        }

        return out;
}
