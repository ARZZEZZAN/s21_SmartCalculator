#ifndef S21_LIST_H
#define S21_LIST_H
typedef enum {
  DIG_LEXEME = 1,
  X_LEXEME = 2,
  MINUS_LEXEME = 3,
  PLUS_LEXEME = 4,
  DIV_LEXEME = 5,
  MUL_LEXEME = 6,
  POW_LEXEME = 7,
  MOD_LEXEME = 8,
  UNARM_LEXEME = 9,
  UNARP_LEXEME = 10,
  COS_LEXEME = 11,
  SIN_LEXEME = 12,
  TAN_LEXEME = 13,
  ACOS_LEXEME = 14,
  ASIN_LEXEME = 15,
  ATAN_LEXEME = 16,
  SQRT_LEXEME = 17,
  LN_LEXEME = 18,
  LOG_LEXEME = 19,
  LEFTScobe_LEXEME = 20,
  RIGHTScobe_LEXEME = 21
} lexeme_enum;
typedef struct Node {
  double value;
  int priority;
  lexeme_enum type;
  struct Node *next;
} lexeme;
void s21_push(lexeme **head, double value, int type, int priority);
void s21_pop(lexeme **head);
lexeme s21_top(lexeme **head);
int s21_type(lexeme **head);
#endif  // S21_LIST_H
