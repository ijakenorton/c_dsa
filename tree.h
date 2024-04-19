typedef struct Node {
  int value;
  int size;
  int height;
  int root;
  struct Node *parent;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct Tree {
  Node *root;
} Tree;
