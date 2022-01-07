/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// =============================================================================
bool alphabetic(char c);
int count_word(char str[]);
// =============================================================================
int main()
{
    char text1[] = "Bene, si partee";
    char text2[] = "Meglio, ricominciamo ora dai!";

    printf("%s - parole = %i\n", text1, count_word(text1));
    printf("%s - parole = %i\n", text2, count_word(text2));
}
// =============================================================================
bool alphabetic(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    } else {
        return false;
    }
}
// =============================================================================
int count_word(char str[])
{
    int i, counter = 0;
    bool new_word = true;

    for (i = 0; str[i] != '\0'; i++) {
        if (alphabetic(str[i])) {
            if (new_word) {
                counter++;
                new_word = false;
            }
        } else {
            new_word = true;
        }
    }

    return counter;
}
