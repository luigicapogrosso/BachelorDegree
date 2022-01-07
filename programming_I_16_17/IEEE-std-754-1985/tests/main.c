/**
 * @file main.c
 * @author Luigi Capogrosso
 * @date 18 Dec 2019
 * @copyright 2019 Luigi Caporgosso
 * @brief Test for conversion of 32 Bits Single Precision IEEE 754
 *        Floating Point Representation.
 */

#include <stdio.h>
#include <stdlib.h>

#include "float_t.h"
#include "toolbox.h"

//==============================================================================
int main(int argc, char const *argv)
{
    printf("\n[LOG] sizeof(float_t) = %d bytes\n", get_float_t_size());

    float f;
    printf("[LOG] Insert a floating point = ");
    scanf("%f", &f);

    float_t fc;
    fc.value = f;
    printf("\n[LOG] IEEE 754 rappresentation of %.4f is:\n", fc.value);
    print_IEEE_754(fc);

#if 0
    int *user_input = get_user_input();
    float_t num2;
    num2.values.sign = convert_to_float_t_sign(user_input);
    num2.values.exponent = convert_to_float_t_exponent(user_input);
    num2.values.biased = convert_to_float_t_biased(user_input);
    printf("[LOG] Float value of the given IEEE-754 representation is:%.4f\n",
           num2.value);
#endif

    return 0;
}
//==============================================================================
