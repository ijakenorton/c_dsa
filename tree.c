/* #include <cstdio> */
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define LEFT 0
#define RIGHT 1

Node *make_node(int value, int root);
void destructor(Node *node);
void print_node(Node *node);
void add(Tree *tree, int value);
void walk(Node *current, Node *addition);

Tree *make_tree(int *arr, size_t len) {
  Tree *new_tree = malloc(sizeof(Tree));
  new_tree->root = make_node(arr[0], TRUE);
  for (size_t i = 1; i < len; i++) {
    add(new_tree, arr[i]);
  }
  return new_tree;
}

void add(Tree *tree, int value) {
  Node *new_node = make_node(value, !TRUE);
  walk(tree->root, new_node);
}

void walk(Node *current, Node *new_node) {
  if (current->value == new_node->value) {
    destructor(new_node);
    return;
  }
  if (current->value > new_node->value) {
    if (current->left == NULL) {
      current->left = new_node;
      return;
    }
    walk(new_node->left, current);
  }
  if (current->value < new_node->value) {
    if (current->right == NULL) {
      current->right = new_node;
      return;
    }
    walk(new_node->right, current);
  }
}

Node *make_node(int value, int root) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->size = 1;
  new_node->height = 0;
  new_node->root = root;
  new_node->parent = NULL;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

void destructor(Node *node) {
  free(node);
  node = NULL;
}

void print_node(Node *node) {
  printf("Value: %d\nSize: %d\nHeight: %d\nRoot: %d\n", node->value, node->size,
         node->height, node->root);
}

int main() {
  int arr[] = {0, 1, 2, 3, 4, 5};
  Tree *tree = make_tree(arr, 6);

  Node *node = make_node(9, !TRUE);

  print_node(node);
  destructor(node);
}
