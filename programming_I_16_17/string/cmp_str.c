/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 81
// =============================================================================
bool equal_string(char str1[], char str2[]);
// =============================================================================
int main()
{
    char strA[] = "Pippo";
    char strB[] = "Pluto";
    char str1[SIZE], str2[SIZE], str3[SIZE];

    printf("%i\n", equal_string(strA, strB));
    printf("%i\n", equal_string(strA, strA));
    printf("%i\n", equal_string(strA, "lalala"));

    printf("\n");

    printf("Enter text: \n");
    scanf("%80s%80s%80s", str1, str2, str3);
    printf("\nstr1 = %s, \nstr2 = %s, \nstr3 = %s\n", str1, str2, str3);
}
// =============================================================================
bool equal_string(char str1[], char str2[])
{
    int i = 0;

    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
        i++;
    }

    if (str1[i] == str2[i]) {
        return true;
    } else {
        return false;
    }
}
