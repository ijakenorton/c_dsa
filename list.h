#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct ListNode {
  int value;
  size_t length;
  struct ListNode *right;
} ListNode;

typedef struct ListHead {
  ListNode *head;
  size_t length;
} ListHead;

typedef void (*FuncVoid)(ListNode *);
typedef int (*FuncList)(ListNode *);

ListHead *list_make_from_values(int *arr, size_t len);
ListHead *list_make();
ListNode *list_make_node(int value);
void list_free(ListHead *head);
void list_append(ListHead *list, int value);
void list_each(ListHead *head, FuncVoid f);
ListHead *list_map(ListHead *head, FuncList f);
void append(ListNode *node, int value);

#endif // LIST_H
