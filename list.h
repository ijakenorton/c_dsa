#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct ListNode {
  void *value;
  size_t length;
  struct ListNode *right;
} ListNode;

typedef void (*FuncVoid)(ListNode *);
typedef void *(*FuncList)(ListNode *);

#endif // LIST_H
