/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>

#define SIZE 81
// =============================================================================
void read_line1(char buffer[]);
void read_line2(char buffer[]);
// =============================================================================
int main()
{
    char line1[SIZE] = " ";
    char line2[SIZE] = " ";

    read_line1(line1);
    printf("La stringa 1 letta è: %s\n", line1);

    read_line2(line2);
    printf("La stringa 2 letta è: %s\n", line2);
}
// =============================================================================
void read_line1(char buffer[])
{
    int i = 0;
    char c;

    do {
        c = getchar();
        buffer[i] = c;
        i++;
    } while (c != '\n');

    buffer[i - 1] = '\0';
}
// =============================================================================
void read_line2(char buffer[])
{
    scanf("%80s", buffer);
}
