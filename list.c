#include "list.h"
#include <stdio.h>
#include <stdlib.h>
  
ListHead *list_make_from_values(int *arr, size_t len);
ListHead *list_make();
ListNode *list_make_node(int value);
void list_append(ListHead *list ,int value);
void list_each(ListHead* head, FuncVoid f);
ListHead *list_map(ListHead *head, FuncList f);
void append(ListNode *node, int value);
void free_nodes(ListNode *node);
void node_destruct(ListNode *node);
void head_destruct(ListHead *head);

  
ListHead *list_make(){
  ListHead *new_list = malloc(sizeof(ListHead));
  new_list->head = NULL;
  new_list->length = 0;
  return new_list;
}

ListNode *list_make_node(int value){
  ListNode *new_node = malloc(sizeof(ListNode));
  new_node->value = value; 
  new_node->right = NULL;
  return new_node;
}

void list_append(ListHead *list ,int value){
  list->length += 1;
  if (list->head == NULL){
    list->head = list_make_node(value);
    return;
  }
  append(list->head, value);
}

void append(ListNode *node, int value){
  if (node->right == NULL) {
    node->right = list_make_node(value);
    return;
  }
  append(node->right, value);
}

void list_each(ListHead *head, FuncVoid f){
  if (head->head == NULL){
    return ;
  }
  ListNode *first = head->head;
    for (ListNode* current = first; current != NULL; current = current->right) {
        f(current);  
    }
}

ListHead *list_map(ListHead *head, FuncList f){
  ListHead *new = list_make();
  if (head->head == NULL){
    return new;
  }
  ListNode *first = head->head;
    for (ListNode* current = first; current != NULL; current = current->right) {
        list_append(new, f(current));  
    }
  return new;
}

void list_free(ListHead *head){
  ListNode *node = head->head;

  if (node == NULL){
    node_destruct(node);
    head_destruct(head);
    return;
  }

  free_nodes(node);
  head_destruct(head);
}

void free_nodes(ListNode *node){
  if (node == NULL) {
    return;
  }
  free_nodes(node->right);
  node_destruct(node);
}

void node_print(ListNode *node){
  printf("%d\n", node->value);
}

void node_destruct(ListNode *node){
  free(node);
  node = NULL;
}

void head_destruct(ListHead *head){
  free(head);
  head = NULL;
}


int main(){
  ListHead *list = list_make();
  list_append(list, 0);
  list_append(list, 1);
  list_append(list, 2);
  list_append(list, 9);

  list_each(list, (FuncVoid)node_print);
  list_free(list);

    EXIT_SUCCESS;
}
