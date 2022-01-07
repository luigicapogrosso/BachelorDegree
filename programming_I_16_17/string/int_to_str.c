/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
// =============================================================================
int calculate_value(char str);
int calculate_newstring_size(char *str);
char *reverse(char *str);
// =============================================================================
int main()
{
    char str[] = "P-r_O:g_r_.A_M-M-A__z-i;O_N-E__1_";
    char *new_str;

    printf("La stringa è: %s\n", str);

    new_str = reverse(str);
    printf("La stringa ora è: %s\n", new_str);
}
// =============================================================================
char *reverse(char *str)
{
    int i = 0, s = 0, size = calculate_newstring_size(str);
    char c[3];
    char *return_string = (char *) malloc(sizeof(char) * size);

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            sprintf(c, "%i", calculate_value(str[i]));
        } else {
            c[0] = str[i];
            c[1] = '\0';
        }
        int j = 0;
        while (c[j] != '\0') {
            return_string[s] = c[j];
            s++;
            j++;
        }
        i++;
    }
    return_string[s] = '\0';

    return return_string;
}
// =============================================================================
int calculate_newstring_size(char *str)
{
    int single_char = 0, double_char = 0;

    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'i') {
            single_char++;
        } else if (*str >= 'j' && *str <= 'z') {
            double_char++;
        } else {
            single_char++;
        }
        str++;
    }

    return single_char + (2 * double_char);
}
// =============================================================================
int calculate_value(char str)
{
    if (str >= 'a' && str <= 'z') {
        int pos = 0;
        char temp = 'a';
        while (temp <= str) {
            pos++;
            temp++;
        }

        return pos;
    } else {
        int pos = 0;
        char temp = 'A';
        while (temp <= str) {
            pos++;
            temp++;
        }

        return pos;
    }
}
