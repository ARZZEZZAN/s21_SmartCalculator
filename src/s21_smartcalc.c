#include "s21_smartcalc.h"
/// @brief Parse lexemes(operations and functions).
/// @param lexem
/// @param I i = *I
/// @return
lexeme s21_parse_lexeme(char *lexem, char **end) {
  lexeme result = {0};
  int i = 0;
  if (lexem[i] == 'x') {
    s21_set_structLexeme(&result, X_LEXEME, 0, 0);
    i++;
  } else if (lexem[i] == '+') {
    s21_set_structLexeme(&result, PLUS_LEXEME, 1, 0);
    i++;
  } else if (lexem[i] == '-') {
    s21_set_structLexeme(&result, MINUS_LEXEME, 1, 0);
    i++;
  } else if (lexem[i] == '/') {
    s21_set_structLexeme(&result, DIV_LEXEME, 2, 0);
    i++;
  } else if (lexem[i] == '*') {
    s21_set_structLexeme(&result, MUL_LEXEME, 2, 0);
    i++;
  } else if (lexem[i] == '^') {
    s21_set_structLexeme(&result, POW_LEXEME, 3, 0);
    i++;
  } else if (lexem[i] == 'm' && lexem[i + 1] == 'o' && lexem[i + 2] == 'd') {
    s21_set_structLexeme(&result, MOD_LEXEME, 3, 0);
    i += 3;
  } else if (lexem[i] == 's' && lexem[i + 1] == 'i' && lexem[i + 2] == 'n') {
    s21_set_structLexeme(&result, SIN_LEXEME, 4, 0);
    i += 3;
  } else if (lexem[i] == 'c' && lexem[i + 1] == 'o' && lexem[i + 2] == 's') {
    s21_set_structLexeme(&result, COS_LEXEME, 4, 0);
    i += 3;
  } else if (lexem[i] == 't' && lexem[i + 1] == 'a' && lexem[i + 2] == 'n') {
    s21_set_structLexeme(&result, TAN_LEXEME, 4, 0);
    i += 3;
  } else if (lexem[i] == 'l' && lexem[i + 1] == 'o' && lexem[i + 2] == 'g') {
    s21_set_structLexeme(&result, LOG_LEXEME, 4, 0);
    i += 3;
  } else if (lexem[i] == 'l' && lexem[i + 1] == 'n') {
    s21_set_structLexeme(&result, LN_LEXEME, 4, 0);
    i += 2;
  } else if (lexem[i] == 'a' && lexem[i + 1] == 's' && lexem[i + 2] == 'i' &&
             lexem[i + 3] == 'n') {
    s21_set_structLexeme(&result, ASIN_LEXEME, 4, 0);
    i += 4;
  } else if (lexem[i] == 'a' && lexem[i + 1] == 'c' && lexem[i + 2] == 'o' &&
             lexem[i + 3] == 's') {
    s21_set_structLexeme(&result, ACOS_LEXEME, 4, 0);
    i += 4;
  } else if (lexem[i] == 'a' && lexem[i + 1] == 't' && lexem[i + 2] == 'a' &&
             lexem[i + 3] == 'n') {
    s21_set_structLexeme(&result, ATAN_LEXEME, 4, 0);
    i += 4;
  } else if (lexem[i] == 's' && lexem[i + 1] == 'q' && lexem[i + 2] == 'r' &&
             lexem[i + 3] == 't') {
    s21_set_structLexeme(&result, SQRT_LEXEME, 4, 0);
    i += 4;
  } else if (lexem[i] == '(') {
    s21_set_structLexeme(&result, LEFTScobe_LEXEME, -1, 0);
    i++;
  } else if (lexem[i] == ')') {
    s21_set_structLexeme(&result, RIGHTScobe_LEXEME, -1, 0);
    i++;
  }
  *end = (char *)&lexem[i];
  return result;
}
/// @brief Set struct with new values.
/// @param result
/// @param type
/// @param priority
/// @param value
/// @param i
void s21_set_structLexeme(lexeme *result, lexeme_enum type, int priority,
                          int value) {
  result->type = type;
  result->priority = priority;
  result->value = value;
}
/// @brief Operations with simple methods
/// @param num1
/// @param num2
/// @param type
/// @return Struct result.
lexeme s21_calculate_withOperations(double num1, double num2,
                                    lexeme_enum type) {
  lexeme result = {0};
  s21_set_structLexeme(&result, DIG_LEXEME, 0, 0);
  if (type == PLUS_LEXEME) {
    result.value = num1 + num2;
  } else if (type == MINUS_LEXEME) {
    result.value = num1 - num2;
  } else if (type == DIV_LEXEME) {
    result.value = num1 / num2;
  } else if (type == MUL_LEXEME) {
    result.value = num1 * num2;
  } else if (type == POW_LEXEME) {
    result.value = pow(num1, num2);
  } else if (type == MOD_LEXEME) {
    result.value = fmod(num1, num2);
  }
  return result;
}
/// @brief Operations with hard methods
/// @param num1
/// @param num2
/// @param type
/// @return Struct result.
lexeme s21_calculate_withFunctions(double num, lexeme_enum type) {
  lexeme result = {0};
  s21_set_structLexeme(&result, DIG_LEXEME, 0, 0);
  if (type == SIN_LEXEME) {
    result.value = sin(num);
  } else if (type == COS_LEXEME) {
    result.value = cos(num);
  } else if (type == SQRT_LEXEME) {
    result.value = sqrt(num);
  } else if (type == TAN_LEXEME) {
    result.value = tan(num);
  } else if (type == ASIN_LEXEME) {
    result.value = asin(num);
  } else if (type == ACOS_LEXEME) {
    result.value = acos(num);
  } else if (type == ATAN_LEXEME) {
    result.value = atan(num);
  } else if (type == LN_LEXEME) {
    result.value = log(num);
  } else if (type == LOG_LEXEME) {
    result.value = log10(num);
  } else if (type == UNARM_LEXEME) {
    result.value = num * (-1);
  } else if (type == UNARP_LEXEME) {
    result.value = +num;
  }
  return result;
}
/// @brief Перевод из строки в double
/// @param str Стартовая строка
/// @param end Указатель на последнее вхождение
/// @param numbur Число
/// @return 1 - ok 0 - error
int s21_string_to_double(char *str, char **end, double *number) {
  int flag = 1;
  double num = 0;
  int dot = 0;
  size_t i = 0;
  if (is_digit(str[i]) == 0) {
    if (str[i] == '.') {
      if (is_digit(str[i + 1]) == 0) {
        flag = 0;
      }
    } else {
      flag = 0;
    }
  }
  if (flag == 1) {
    for (;; i++) {
      if (is_digit(str[i]) == 0) {
        if (str[i] != '.') {
          break;
        }
      }
      if (str[i] == '.') {
        dot = 10;
      }
      if (dot == 0) {
        num = (num * 10) + (double)(str[i] - '0');
      } else if (str[i] != '.') {
        num += (double)(str[i] - '0') / dot;
        dot *= 10;
      }
    }
  }
  *end = (char *)&str[i];
  *number = num;
  return flag;
}
/// @brief Пропуск пробелов
/// @param str Стартовая строка
/// @param end Указатель на последнее вхождение
/// @return 1 - ok 0 - error
int s21_skip_space(char *str, char **end) {
  int i = 0;
  int flag = 0;
  while (s21_is_space(str[i]) == 1) {
    i++;
    flag = 1;
  }
  *end = (char *)&str[i];
  return flag;
}
int s21_is_space(char c) {
  int flag = 0;
  if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') ||
      (c == '\r')) {
    flag = 1;
  }
  return flag;
}
double s21_smart_calc(char *str, double x) {
  lexeme *numbers = NULL;
  lexeme *operations = NULL;
  lexeme tmp = {0};
  // parsing
  char *end = NULL;
  int i = 0;
  double value = 0.0;
  if (str[0] == '-' || str[0] == '+') {
    s21_push(&numbers, 0, DIG_LEXEME, 0);  //запуш нолек если унарный минус
  }
  while (i < (int)strlen(str)) {
    // printf("\nstack numbers:\n");
    // s21_printf_stack(numbers);
    // printf("\nstack operations:\n");
    // s21_printf_stack(operations);
    double value = 0;
    if (s21_skip_space(&str[i], &end)) {
      i += end - &str[i];
    } else if (s21_string_to_double(&str[i], &end, &value)) {
      s21_push(&numbers, value, DIG_LEXEME, 0);
      i += end - &str[i];
    } else {
      tmp = s21_parse_lexeme(&str[i], &end);
      i += end - &str[i];
      if (i > 1 && str[i - 2] == '(' &&
          (tmp.type == MINUS_LEXEME || tmp.type == PLUS_LEXEME)) {
        s21_push(&numbers, 0, DIG_LEXEME, 0);
      }
      s21_priority(&numbers, &operations, tmp, x);
    }
  }
  while (operations != NULL && numbers != NULL) {
    s21_calculation(&operations, &numbers);
  }
  lexeme resultt = s21_top(&numbers);
  value = resultt.value;
  // printf("\nresult = %lf\n", value);
  free(numbers);
  free(operations);
  return value;
}
void s21_priority(lexeme **stackNum, lexeme **stackFunc, lexeme tmp, double x) {
  lexeme topStack = {0};
  if (*stackFunc != NULL) {
    topStack = s21_top(stackFunc);
  } else {
    topStack.priority = -1;
  }
  if (tmp.type == X_LEXEME) {
    s21_push(stackNum, x, DIG_LEXEME, 1);
  } else if (tmp.type == LEFTScobe_LEXEME) {
    s21_push(stackFunc, 0, LEFTScobe_LEXEME, -1);
  } else if (tmp.priority > topStack.priority &&
             tmp.type != RIGHTScobe_LEXEME) {
    s21_push(stackFunc, 0, tmp.type, tmp.priority);
  } else if (tmp.priority <= topStack.priority &&
             tmp.type != RIGHTScobe_LEXEME && tmp.type != LEFTScobe_LEXEME) {
    s21_calculation(stackFunc, stackNum);
    s21_push(stackFunc, tmp.value, tmp.type, tmp.priority);
  } else if (tmp.type == RIGHTScobe_LEXEME) {
    while (stackFunc && s21_type(stackFunc) != LEFTScobe_LEXEME) {
      s21_calculation(stackFunc, stackNum);
    }
    s21_pop(stackFunc);
  }
}
/// @brief Вывод стека
/// @param stack стек
void s21_printf_stack(lexeme *stack) {
  lexeme *stack_print = stack;
  while (stack_print) {
    printf("%lf, %d, %d", stack_print->value, stack_print->priority,
           (int)stack_print->type);
    stack_print = stack_print->next;
    if (stack_print) {
      printf("\n");
    }
  }
  printf("\n");
}
void s21_calculation(lexeme **stackFunc, lexeme **stackNum) {
  lexeme operation = s21_top(stackFunc);
  // printf("num = %lf\n\n", (*stackNum)->value);
  // printf("TYPE = %d\n\n", (*stackFunc)->type);
  s21_pop(stackFunc);

  lexeme operand1 = {0};
  lexeme operand2 = {0};
  //  printf("type = %d\n", operation.type);
  // For Understanding the operation because of my structure
  if (operation.type > 8) {
    operand2 = s21_top(stackNum);
    s21_pop(stackNum);
  } else {
    operand1 = s21_top(stackNum);
    s21_pop(stackNum);
    operand2 = s21_top(stackNum);
    s21_pop(stackNum);
  }
  lexeme result = {0};
  if (operation.type <= 8) {
    result = s21_calculate_withOperations(operand2.value, operand1.value,
                                          operation.type);
  } else {
    result = s21_calculate_withFunctions(operand2.value, operation.type);
  }
  s21_push(stackNum, result.value, result.type, result.priority);
}

int s21_validator(char *str) {
  int res = 1, i = 0, scob = 0;
  while (i != (int)strlen(str)) {
    if (str[i] == 'x' && i != 0 && i != (int)strlen(str)) {
      if (str[i - 1] == ')' || str[i + 1] == '(' ||
          (str[i - 1] <= '9' && str[i - 1] >= '0') ||
          (str[i + 1] <= '9' && str[i + 1] >= '0') || str[i + 1] == 's' ||
          str[i + 1] == 'c' || str[i + 1] == 't' || str[i + 1] == 'a' ||
          str[i + 1] == 'l' || str[i + 1] == 'm' || str[i + 1] == 'i' ||
          str[i + 1] == 'o' || str[i + 1] == 'q' || str[i + 1] == 'n') {
        res = 0;
      }
    }
    if (str[i] == '.') {
      if (i == 0 || i == (int)strlen(str) - 1) {
        res = 0;
      } else {
        if ((str[i - 1] >= '9' && str[i - 1] <= '0') ||
            (str[i + 1] >= '9' && str[i + 1] <= '0')) {
          res = 0;
        }
      }
    } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
               str[i] == '/' || str[i] == '^') {
      if (i == 0) {
        if (str[i] != '-') {
          res = 0;
        } else if (str[i] == '-' && str[i + 1] <= '0' && str[i + 1] >= '9') {
          res = 0;
        } else if (i == (int)strlen(str) - 1) {
          res = 0;
        } else {
          if ((str[i - 1] != ')' && str[i - 1] > '9' && str[i - 1] < '0') ||
              (str[i + 1] < '0' && str[i + 1] > '9') || str[i + 1] == 'm' ||
              str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' ||
              str[i + 1] == '/' || str[i + 1] == '^') {
            res = 0;
          }
        }
      }
    } else if (str[i] == ')') {
      scob -= 1;
      if (scob == -1) {
        res = 0;
      }
      if (i != 0) {
        if (str[i - 1] == '+' || str[i - 1] == '/' || str[i - 1] == '*' ||
            str[i - 1] == '-' || str[i - 1] == '^' || str[i - 1] == '(') {
          res = 0;
        }
        if ((str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n') ||
            (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's') ||
            (str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'n') ||
            (str[i + 1] == 'a' && str[i + 2] == 's' && str[i + 3] == 'i' &&
             str[i + 4] == 'n') ||
            (str[i + 1] == 'a' && str[i + 2] == 'c' && str[i + 3] == 'o' &&
             str[i + 4] == 's') ||
            (str[i + 1] == 'l' && str[i + 2] == 'n') ||
            (str[i + 1] == 'l' && str[i + 2] == 'o' && str[i + 3] == 'g') ||
            (str[i + 1] == 'a' && str[i + 2] == 't' && str[i + 3] == 'a' &&
             str[i + 4] == 'n') ||
            (str[i + 1] == 's' && str[i + 2] == 'q' && str[i + 3] == 'r' &&
             str[i + 4] == 't') ||
            (str[i + 1] == 'm' && str[i + 2] == 'o' && str[i + 3] == 'd')) {
          res = 0;
        }
      } else {
        res = 0;
      }
    } else if (str[i] == '(') {
      scob += 1;
      if (i != (int)strlen(str) - 1) {
        if (str[i + 1] == '+' || str[i + 1] == '/' || str[i + 1] == '*' ||
            str[i + 1] == '^' || str[i + 1] == ')') {
          res = 0;
        }
        if (str[i - 1] <= '9' && str[i - 1] >= '0') {
          res = 0;
        }
      } else {
        res = 0;
      }
    } else if ((str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n') ||
               (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') ||
               (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n') ||
               (str[i] == 'a' && str[i + 1] == 's' && str[i + 2] == 'i' &&
                str[i + 3] == 'n') ||
               (str[i] == 'a' && str[i + 1] == 'c' && str[i + 2] == 'o' &&
                str[i + 3] == 's') ||
               (str[i] == 'l' && str[i + 1] == 'n') ||
               (str[i] == 'l' && str[i + 1] == 'o' && str[i + 2] == 'g') ||
               (str[i] == 'a' && str[i + 1] == 't' && str[i + 2] == 'a' &&
                str[i + 3] == 'n') ||
               (str[i] == 's' && str[i + 1] == 'q' && str[i + 2] == 'r' &&
                str[i + 3] == 't')) {
      if ((i != 0 && str[i - 1] == ')') ||
          (str[i - 1] <= '9' && str[i - 1] >= '0')) {
        res = 0;
      }
    } else if (str[i] == 'm' && str[i + 1] == 'o' && str[i + 2] == 'd') {
      if ((i == 0 && str[i] == 'm') ||
          (str[i] == 'd' && i == (int)strlen(str) - 1)) {
        res = 0;
      } else if (i != 0 && str[i] == 'm' &&
                 (str[i - 1] == '(' || str[i - 1] == '+' || str[i - 1] == '/' ||
                  str[i - 1] == '*' || str[i - 1] == '-' ||
                  str[i - 1] == '^')) {
        res = 0;
      } else if (i != (int)strlen(str) - 1 && str[i] == 'd' &&
                 (str[i + 1] == '+' || str[i + 1] == '/' || str[i + 1] == '*' ||
                  str[i + 1] == '-' || str[i + 1] == '^')) {
        res = 0;
      }
    }
    i++;
  }
  if (scob != 0) {
    res = 0;
  }
  return res;
}
// int main() {
//   char *str = "5 + 5";
//   printf("%lf\n", s21_smart_calc(str, 0.0));
// }
