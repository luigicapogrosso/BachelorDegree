/**
 * @file toolbox.c
 * @author Luigi Capogrosso
 * @date 18 Dec 2019
 * @copyright 2019 Luigi Capogrosso
 * @brief <brief>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "toolbox.h"

//==============================================================================
int32_t *get_user_input()
{
    char *string = get_str_of_32();

    int32_t *res = str_to_int_array(string);

    return res;
}
//==============================================================================
char *get_str_of_32()
{
    char *res = (char *) malloc((sizeof(char) * 32));

    do
    {
        printf("\n[LOG] Insert binary number [32]: ");
        scanf("%s", res);
    } while (strlen(res) != 32);

    return res;
}
//==============================================================================
int32_t *str_to_int_array(char *str)
{
    int32_t *res = (int32_t *) malloc(sizeof(int32_t) * 32);

    for (int i = 0; i < 32; i++)
    {
        res[i] = str[i] - 48;
    }

    return res;
}
//==============================================================================
void print_arr_of_int(int32_t *arr)
{
    for (int i = 0; i < 32; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
//==============================================================================
unsigned int convert_to_float_t_biased(int32_t *arr)
{
    unsigned res = 0;
    for (int i = 31; i >= 9; i--)
    {
        res = res + arr[i] * pow(2, 31 - i);
    }

    return res;
}
//==============================================================================
unsigned int convert_to_float_t_exponent(int32_t *arr)
{
    unsigned res = 0;
    for (int i = 8; i >= 1; i--)
    {
        res = res + arr[i] * pow(2, 8 - i);
    }

    return res;
}
//==============================================================================
unsigned int convert_to_float_t_sign(int32_t *arr)
{
    return arr[0];
}
//==============================================================================
