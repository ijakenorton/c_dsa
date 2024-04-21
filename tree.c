#include "tree.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define LEFT 0
#define RIGHT 1

Node *node_make(int value);
Tree *tree_make();
Tree *tree_make_from_values(int *arr, size_t len);
void destructor(Node *node);
void print_node(Node *node);

void tree_add_value(Tree *tree, int value);
void add(Node *current, Node *addition);

void tree_walk(Tree *root, int *arr);
void walk_nodes(Node *node, int *arr, int i);
int leaf(Node *node);

int leaf(Node *node) {
  if (node->left == NULL && node->right == NULL)
    return TRUE;
  else
    return !TRUE;
}

Tree *tree_make() {
  Tree *new_tree = malloc(sizeof(Tree));
  return new_tree;
}
Tree *tree_make_from_values(int *arr, size_t len) {
  Tree *new_tree = malloc(sizeof(Tree));
  new_tree->root = node_make(arr[0]);

  for (size_t i = 1; i < len; i++) {
    tree_add_value(new_tree, arr[i]);
  }
  return new_tree;
}
/* Walk tree from top to bottom */
void tree_walk(Tree *tree, int *arr) { walk_nodes(tree->root, arr, 0); }
void walk_nodes(Node *node,  ) {
  arr[i] = node->value;
  if (node->left != NULL) {
    walk_nodes(node->left, arr, i);
  }
  if (node->right != NULL) {
    walk_nodes(node->right, arr, i);
  }
}

void tree_add_value(Tree *tree, int value) {
  Node *new_node = node_make(value);
  add(tree->root, new_node);
}

void increment_size(Node *node) {
  if (node->parent == NULL) {
    return;
  }
  node->parent->size += 1;
  increment_size(node->parent);
}

void add(Node *current, Node *new_node) {
  if (current->value == new_node->value) {
    destructor(new_node);
    return;
  }
  if (current->value > new_node->value) {
    if (current->left == NULL) {
      current->left = new_node;
      new_node->parent = current;
      increment_size(current);
      return;
    }
    add(current->left, new_node);
  }
  if (current->value < new_node->value) {
    if (current->right == NULL) {
      current->right = new_node;
      new_node->parent = current;
      increment_size(current);
      return;
    }
    add(current->right, new_node);
  }
}

Node *node_make(int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->size = 1;
  new_node->height = 0;
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
  printf("Leaf: Value: %d\nSize: %d\nHeight: %d\nLeft: %p\nRight: "
         "%p\n",
         node->value, node->size, node->height, node->left, node->right);
}

int main() {
  int arr[] = {5, 10, 3, 6, 9};
  Tree *tree = tree_make_from_values(arr, 5);
  int current_tree[tree->root->size];
  tree_walk(tree, current_tree);
  for (int i = 0; i < tree->root->size; i++) {
    printf("%d\n", current_tree[i]);
  }
  EXIT_SUCCESS;
}
