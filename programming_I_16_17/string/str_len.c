/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>

#define SIZE 14
// =============================================================================
int string_length(char string[]);
void string_copy(char *s1, char *s2);
// =============================================================================
int main()
{
    char s1[] = {'P','R','O','G','R','A','M','M','A','Z','I','O','N','E','\0'};
    char s2[] = {"Programmazione"};
    char *s3 = "Programmazione";
    char dest[SIZE];

    printf("La lunghezza di s1 è: %i\n", string_length(s1));
    printf("La lunghezza di s2 è: %i\n", string_length(s2));
    printf("La lunghezza di s3 è: %i\n", string_length(s3));

    printf("Sto copiando s1 in dest...\n");
    string_copy(s2, dest);
    printf("\"dest\": %s\n", dest);

}
// =============================================================================
int string_length(char string[])
{
    int lenght = 0;

    while (*string != '\0') {
        lenght++;
        string++;
    }

    return lenght;
}
// =============================================================================
void string_copy(char *s1, char *s2)
{
    int pos = 0;
    do {
        *(s2 + pos) = *(s1 + pos);
    } while (*(s1 + pos++) != '\0');
}
