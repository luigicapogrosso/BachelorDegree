/**
 * @file float_t.c
 * @author Luigi Capogrosso
 * @date 18 Dec 2019
 * @copyright 2019 Luigi Capogrosso
 * @brief IEEE Standard 754 Floating Point Numbers implementation.
 */

#include <stdio.h>

#include "float_t.h"

//==============================================================================
int16_t get_float_t_size()
{
    return sizeof(float_t);
}
//==============================================================================
void print_IEEE_754(float_t num)
{
    print_bin(num.values.sign, 1);
    printf(" | ");

    print_bin(num.values.exponent, 8);
    printf(" | ");

    print_bin(num.values.biased, 23);
    printf("\n");
}
//==============================================================================
void print_bin(int bits, int n_bit)
{
    for (int i = (n_bit - 1); i >= 0; i--)
    {
        if (bits & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}
//==============================================================================
