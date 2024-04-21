#include "list.h"
#include <stdio.h>
#include <stdlib.h>
  
ListNode *list_make_from_array(int *arr, size_t len);
ListNode *list_clone(ListNode *list);
ListNode *list_make_node(void *value );
void list_free(ListNode *head);
void list_append(ListNode *list ,void *value);
void list_each(ListNode* node, FuncVoid f);
ListNode *list_map(ListNode *node, FuncList f);
void append(ListNode *node, void *value);
void free_nodes(ListNode *node);
void node_destruct(ListNode *node);



ListNode *list_make_node(void *value){
  ListNode *new_node = malloc(sizeof(ListNode));
  new_node->value = value; 
  new_node->right = NULL;
  new_node->length = 1;
  return new_node;
}

ListNode *list_make(){
  ListNode *new_node = malloc(sizeof(ListNode));
  new_node->right = NULL;
  new_node->value = NULL;
  new_node->length = 0;
  return new_node;
}

void list_append(ListNode *list ,void *value){
  list->length += 1;
  if (list->value == NULL) {
    list->value = value;
    return;
  }
  append(list, value);
}

void append(ListNode *node, void *value){
  if (node->right == NULL) {
    node->right = list_make_node(value);
    return;
  }

  append(node->right, value);
}

void list_each(ListNode *head, FuncVoid f){
  if (head == NULL){
    return ;
  }
    for (ListNode* current = head; current != NULL; current = current->right) {
        f(current);  
    }
}

ListNode *list_clone(ListNode *head){
  ListNode *new = list_make();
    for (ListNode* current = head; current != NULL; current = current->right) {
      list_append(new, current->value);  
    }
  return new;
}

ListNode *list_map(ListNode *head, FuncList f){
  ListNode *new = list_make();
    for (ListNode* current = head; current != NULL; current = current->right) {
        list_append(new, f(current));  
    }
  return new;
}

void list_free(ListNode *head){
  ListNode *node = head;

  if (node == NULL){
    node_destruct(node);
    return;
  }

  free_nodes(node);
}

void free_nodes(ListNode *node){
  if (node == NULL) {
    return;
  }
  free_nodes(node->right);
  node_destruct(node);
}

void node_print_int(ListNode *node){
  printf("%d\n",*(int*)node->value);
}

void node_destruct(ListNode *node){
  free(node);
  node = NULL;
}



int main(){
  ListNode *list = list_make();
  int* zero = malloc(sizeof(int));
  int* one = malloc(sizeof(int));
  int* two = malloc(sizeof(int));
  int* three = malloc(sizeof(int));
  *zero = 0 ;
  *one = 1 ;
  *two = 2 ;
  *three = 3 ;

  list_append(list, zero);
  list_append(list, one);
  list_append(list, two);
  list_append(list, three);

  list_each(list, (FuncVoid)node_print_int);
  list_free(list);
  free(zero);
  free(one);
  free(two);
  free(three);

    EXIT_SUCCESS;
}
