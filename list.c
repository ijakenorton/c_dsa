#include "list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode *list_make_from_array(int *arr, size_t len);
ListNode *list_clone(ListNode *list, FuncList f);
ListNode *list_make_node(void *value);
void list_free(ListNode *head);
void list_append(ListNode *list, void *value);
void list_each(ListNode *node, FuncVoid f);
ListNode *list_inplace_map(ListNode *node, FuncList f);
void append(ListNode *node, void *value);
void free_nodes(ListNode *node);
void free_node(ListNode *node);

ListNode *list_make_node(void *value) {
  ListNode *new_node = malloc(sizeof(ListNode));
  new_node->value = value;
  new_node->right = NULL;
  new_node->length = 1;
  return new_node;
}

ListNode *list_make() {
  ListNode *new_node = malloc(sizeof(ListNode));
  new_node->right = NULL;
  new_node->value = NULL;
  new_node->length = 0;
  return new_node;
}

void list_append(ListNode *list, void *value) {
  list->length += 1;
  if (list->value == NULL) {
    list->value = value;
    return;
  }
  append(list, value);
}

void append(ListNode *node, void *value) {
  if (node->right == NULL) {
    node->right = list_make_node(value);
    return;
  }

  append(node->right, value);
}

void list_each(ListNode *head, FuncVoid f) {
  if (head == NULL) {
    return;
  }
  for (ListNode *current = head; current != NULL; current = current->right) {
    f(current);
  }
}

ListNode *list_clone(ListNode *head, FuncList f) {
  ListNode *new = list_make();
  for (ListNode *current = head; current != NULL; current = current->right) {
    list_append(new, f(current));
  }
  return new;
}

ListNode *list_inplace_map(ListNode *head, FuncList f) {
  ListNode *new = list_make();
  for (ListNode *current = head; current != NULL; current = current->right) {
    list_append(new, f(current));
  }
  return new;
}

void list_free(ListNode *head) {
  ListNode *node = head;

  if (node == NULL) {
    free_node(node);
    return;
  }

  free_nodes(node);
}

void free_nodes(ListNode *node) {
  if (node == NULL) {
    return;
  }
  free_nodes(node->right);
  free_node(node);
}

void node_print_int(ListNode *node) { printf("%d\n", *(int *)node->value); }

void *clone(ListNode *node) {
  int *value = malloc(sizeof(int));
  *value = *(int *)node->value;
  return value;
}

void free_node(ListNode *node) {
  free(node);
  node = NULL;
}

int main() {
  ListNode *list = list_make();

  int zero = 0;
  int one = 1;
  int two = 2;
  int three = 3;
  list_append(list, &zero);
  list_append(list, &one);
  list_append(list, &two);
  list_append(list, &three);

  list_each(list, (FuncVoid)node_print_int);
  printf("\n");
  list_append(list, &three);
  list_each(list, (FuncVoid)node_print_int);
  list_free(list);

  return EXIT_SUCCESS;
}
