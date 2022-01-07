/**
 * @file float_t.h
 * @author Luigi Capogrosso
 * @date 18 Dec 2019
 * @copyright 2019 Luigi Capogrosso
 * @brief IEEE Standard 754 Floating Point Numbers definition.
 */

#ifndef FLOAT_T_H
#define FLOAT_T_H

#include <stdlib.h>

//==============================================================================
/**
 * @brief   Implementation based on Union Datatype in C and using the concept of
 *          Bit Fields.
 * @details Bit Fields are assigned when we don’t require the full memory that
 *          is usually allocated to some variables but we want to limit the
 *          amount of memory taken up by those variables. In C, members of a
 *          Union share the common memory space and taken we can access the
 *          members only one at a time.
 */
typedef union
{
    struct
    {
        unsigned int biased:23;
        unsigned int exponent:8;
        unsigned int sign:1;
    } values;
    float value;
} float_t;
//==============================================================================
/**
 * @brief   Calculate the allocated numbersof bytes of a float_t.
 * @return  float_t size.
 */
int16_t get_float_t_size();
//==============================================================================
/**
 * @brief   Function to convert real value to IEEE foating point representation.
 * @param   [in] num IEEE foating point custom representation.
 * @return  Prints the IEEE 754 representation of a float value (32 bits).
 */
void print_IEEE_754(float_t num);
//==============================================================================
/**
 * @brief   Function to convert a number to the binary representation.
 * @param   [in] <name> <parameter_description>
 * @return  Prints the binary representation of a number n up to i-bits.
 */
void print_bin(int bits, int n_bit);
//==============================================================================
#endif
