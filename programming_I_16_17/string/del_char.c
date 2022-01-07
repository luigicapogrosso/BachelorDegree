/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */
// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// =============================================================================
int new_sizestring(char *s, char c);
char *remove_occurence(char *s, char c);
// =============================================================================
int main()
{
    char *string;
    char *new_string;

    string = "tutta statistica";
    printf("La stringa è: %s\n", string);
    new_string = remove_occurence(string, 't');
    printf("La nuova stringa è: %s\n", new_string);

    free(new_string);
}
// =============================================================================
char *remove_occurence(char *s, char c)
{
    int i = 0, j = 0;
    char *return_string = (char *) malloc(sizeof(char) * new_sizestring(s, c));

    while (s[i] != '\0') {
        if (s[i] != c) {
            return_string[j] = s[i];
            j++;
        }
        ++i;
    }
    return_string[j] = '\0';

    return return_string;
}
// =============================================================================
int new_sizestring(char *s, char c)
{
    int size, nof_occurence = 0;

    size = strlen(s);

    while (*s) {
        if (*s == c) {
            nof_occurence++;
        }
        s++;
    }

    return size - nof_occurence;
}
