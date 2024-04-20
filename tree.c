#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define LEFT 0
#define RIGHT 1

Node *make_node(int value, int root);
void destructor(Node *node);
void print_node(Node *node);

void add_new_value(Tree *tree, int value);
void add(Node *current, Node *addition);

void walk_tree(Tree *root);
void walk_nodes(Node *node);
int leaf(Node *node);

int leaf(Node *node) {
  if (node->left == NULL && node->right == NULL)
    return TRUE;
  else
    return !TRUE;
}
Tree *make_tree(int *arr, size_t len) {
  Tree *new_tree = malloc(sizeof(Tree));
  new_tree->root = make_node(arr[0], TRUE);

  for (size_t i = 1; i < len; i++) {
    add_new_value(new_tree, arr[i]);
  }
  return new_tree;
}
/* Walk tree from top to bottom */
void walk_tree(Tree *tree) {
  walk_nodes(tree->root);
}
void walk_nodes(Node *node) {
  print_node(node);
  if (node->left != NULL) {
    walk_nodes(node->left);
  }
  if (node->right != NULL) {
    walk_nodes(node->right);
  }
}

void add_new_value(Tree *tree, int value) {
  Node *new_node = make_node(value, !TRUE);
  add(tree->root, new_node);
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
      return;
    }
    add(current->left, new_node);
  }
  if (current->value < new_node->value) {
    if (current->right == NULL) {
      current->right = new_node;
      new_node->parent = current;
      return;
    }
    add(current->right, new_node);
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
    printf("Leaf: Value: %d\nSize: %d\nHeight: %d\nRoot: %d\nLeft: %p\nRight: "
           "%p\n",
           node->value, node->size, node->height, node->root, node->left , node->right);
}

int main() {
  int arr[] = {5, 10, 3, 6, 9};
  Tree *tree = make_tree(arr, 5);
  walk_tree(tree);
}
