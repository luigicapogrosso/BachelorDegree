/**
 * @file toolbox.h
 * @author Luigi Capogrosso
 * @date 18 Dec 2019
 * @copyright 2019 Luigi Capogrosso
 * @brief <brief>
 */

#ifndef TOOLBOX_H
#define TOOLBOX_H

//==============================================================================
/**
 * @brief <brief>
 * @return <return_description>
 */
int32_t *get_user_input();
//==============================================================================
/**
 * @brief <brief>
 * @return <return_description>
 */
char *get_str_of_32();
//==============================================================================
/**
 * @brief <brief>
 * @return <return_description>
 */
int32_t *str_to_int_array(char *str);
//==============================================================================
/**
 * @brief <brief>
 * @return <return_description>
 */
void print_arr_of_int(int32_t *arr);
//==============================================================================
/**
 * @brief <brief>
 * @param [in] <name> <parameter_description>
 * @return <return_description>
 */
unsigned int convert_to_float_t_biased(int32_t *arr);
//==============================================================================
/**
 * @brief <brief>
 * @param [in] <name> <parameter_description>
 * @return <return_description>
 */
unsigned int convert_to_float_t_exponent(int32_t *arr);
//==============================================================================
/**
 * @brief <brief>
 * @param [in] <name> <parameter_description>
 * @return <return_description>
 */
unsigned int convert_to_float_t_sign(int32_t *arr);
//==============================================================================
#endif
