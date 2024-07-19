#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct {
  size_t length;
  struct QueueNode *head;
  struct QueueNode *tail;
  int empty;
} QueueHead;

typedef struct QueueNode {
  void *value;
  struct QueueNode *next;
  struct QueueNode *prev;
} QueueNode;

typedef void (*FuncVoidQueue)(QueueNode *);
typedef void *(*FuncQueue)(QueueNode *);

#endif // QUEUE_H
