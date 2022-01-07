/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
// =============================================================================
void concat_string(char result[], char str1[], int n1, char str2[], int n2);
// =============================================================================
int main()
{
    int i;
    char s1[SIZE] = {'H', 'E', 'L', 'L', 'O', ' '};
    char s2[SIZE] = {'W', 'O', 'R', 'L', 'D', '!'};
    char s3[SIZE + SIZE];

    concat_string(s3, s1, SIZE, s2, SIZE);

    for (i = 0; i < SIZE + SIZE; i++) {
        printf("%c ", s3[i]);
    }
    printf("\n");
}
// =============================================================================
void concat_string(char result[], char str1[], int n1, char str2[], int n2)
{
    int i, j;

    for (i = 0; i < SIZE; i++) {
        result[i] = str1[i];
    }

    for (j = 0; j < SIZE; j++) {
        result[i + j] = str2[j];
    }
}
