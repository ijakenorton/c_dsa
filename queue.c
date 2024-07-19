#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

QueueNode *queue_make_from_array(int *arr, size_t len);
QueueNode *queue_make_node(void *value);
void queue_free(QueueHead *head);
void queue_add(QueueHead *queue, void *value);
void queue_each(QueueHead *node, FuncVoidQueue f);
QueueHead *queue_inplace_map(QueueHead *node, FuncQueue f);
void free_nodes(QueueNode *node);
void free_node(QueueNode *node);

QueueNode *queue_make_node(void *value) {
  QueueNode *new_node = malloc(sizeof(QueueNode));
  new_node->value = value;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

QueueHead *queue_make() {
  QueueHead *new_queue = malloc(sizeof(QueueHead));
  new_queue->head = NULL;
  new_queue->tail = NULL;
  new_queue->length = 0;
  return new_queue;
}

void queue_add(QueueHead *queue, void *value) {
  queue->length += 1;
  QueueNode *node = queue_make_node(value);
  if (queue->head == NULL) {
    queue->head = node;
    return;
  }
  if (queue->tail == NULL) {
    queue->tail = node;
    queue->tail->next = queue->head;
    queue->head->prev = queue->tail;
    return;
  }

  queue->tail->prev = node;
  queue->tail->prev->next = queue->tail;
  queue->tail = node;
  return;
}

void queue_each(QueueHead *queue, FuncVoidQueue f) {
  if (queue == NULL) {
    return;
  }
  for (QueueNode *current = queue->tail; current != NULL;
       current = current->next) {
    f(current);
  }
}

QueueHead *queue_inplace_map(QueueHead *queue, FuncQueue f) {
  QueueHead *new = queue_make();
  for (QueueNode *current = queue->tail; current != NULL;
       current = current->next) {
    queue_add(new, f(current));
  }
  return new;
}

void queue_free(QueueHead *queue) {
  QueueNode *tail = queue->tail;
  if (tail == NULL) {
    free_node(queue->head);
    free_node(tail);
    return;
  }

  free_nodes(tail);
  free(queue);
  queue = NULL;
}

void free_nodes(QueueNode *node) {
  if (node == NULL) {
    return;
  }

  QueueNode *next = node->next;
  free_node(node);
  free_nodes(next);
}

void node_print_int(QueueNode *node) { printf("%d\n", *(int *)node->value); }

void free_node(QueueNode *node) {
  free(node);
  node = NULL;
}

int main() {
  QueueHead *queue = queue_make();

  int zero = 0;
  int one = 1;
  int two = 2;
  int three = 3;
  queue_add(queue, &zero);
  queue_add(queue, &one);
  queue_add(queue, &two);
  queue_add(queue, &three);

  queue_each(queue, (FuncVoidQueue)node_print_int);
  printf("\n");
  queue_add(queue, &three);
  queue_each(queue, (FuncVoidQueue)node_print_int);
  queue_free(queue);

  return EXIT_SUCCESS;
}
