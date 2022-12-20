#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_list.h"

#define is_digit(c) (c >= '0' && c <= '9')

void s21_set_structLexeme(lexeme *result, lexeme_enum type, int priority,
                          int value);
void s21_calculation(lexeme **stackFunc, lexeme **stackNum);
void s21_priority(lexeme **stackNum, lexeme **stackFunc, lexeme tmp, double x);
void s21_printf_stack(lexeme *stack);
int s21_skip_space(char *str, char **end);
int s21_is_space(char c);
int s21_validator(char *str);

double s21_smart_calc(char *str, double x);

#endif  // SRC_S21_STRING_H_
