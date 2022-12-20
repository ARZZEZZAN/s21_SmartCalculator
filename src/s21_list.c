#include "s21_smartcalc.h"
/// @brief Adds an element to the top of the stack.
/// @param head
/// @param value
/// @param type
/// @param priority
void s21_push(lexeme **head, double value, int type, int priority) {
  lexeme *tmp = (lexeme *)malloc(sizeof(lexeme));
  tmp->value = value;
  tmp->type = type;
  tmp->priority = priority;
  tmp->next = (*head);
  (*head) = tmp;
}
/// @brief Removes the topmost element from the stack.
/// @param head
/// @return Struct

void s21_pop(lexeme **head) {
  lexeme *stack = (*head);
  if (stack) {
    free(*head);
  }
  (*head) = stack->next;
}
/// @brief Displays the topmost element of the stack.
/// @param head
/// @return Struct
lexeme s21_top(lexeme **head) {
  lexeme *tmp = (*head);
  return *tmp;
}
/// @brief Type of operation.
/// @param head
/// @return Struct
int s21_type(lexeme **head) { return (*head)->type; }
