/*
    MIT License
    Copyright (c) 2017 Luigi Capogrosso
*/

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
// =============================================================================
int string_to_int(char str[]);
// =============================================================================
int main() {
    printf("%i\n", string_to_int("254"));
    printf("%i\n", string_to_int("54"));
    printf("%i\n", string_to_int("4"));
}
// =============================================================================
int string_to_int(char str[]) {
    int i, int_value, result = 0;

    for (i = 0; str[i] != '\0'; i++) {
        int_value = str[i] - '0';
        result = result * 10 + int_value;
    }

    return result;
}
