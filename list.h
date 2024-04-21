#include <stdlib.h>

typedef struct ListNode {
  int value;
  struct ListNode *right;
} ListNode;

typedef struct ListHead {
  ListNode *head;
  size_t length;
} ListHead;

typedef void (*FuncVoid)(ListNode *);
typedef int (*FuncList)(ListNode *);
