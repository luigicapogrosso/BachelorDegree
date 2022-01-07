/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
// =============================================================================
void concat_string(char result[], char str1[], char str2[]);
// =============================================================================
int main()
{
    char s1[] = "Programmazione ";
    char s2[] = {"1"};
    char s3[SIZE];

    concat_string(s3, s1, s2);

    printf("%s\n", s3);
}
// =============================================================================
void concat_string(char result[], char str1[], char str2[])
{
    int i, j;

    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }

    for (j = 0; str1[j] != '\0'; j++) {
        result[i + j] = str2[j];
    }
}
