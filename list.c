#include "list.h"
#include <stdlib.h>

ListHead *list_make_from_values(int *arr, size_t len);
void append(ListNode *node, int value);

  
ListHead *list_make(){
  ListHead *new_list = malloc(sizeof(ListHead));
  new_list->length = 0;
  return new_list;
}

ListNode *list_make_node(int value){
  ListNode *new_node = malloc(sizeof(ListNode));
  new_node->value = value; 
  new_node->right = NULL;
  return new_node;
}

void list_append_value(ListHead *list ,int value){
  list->length += 1;
  append(list->head, value);
}

void append(ListNode *node, int value){
  if (node->right == NULL) {
    node->value = value;
    return;
  }
  append(node->right, value);


}
int main(){

}
