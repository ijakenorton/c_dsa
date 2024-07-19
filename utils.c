
#include <stdio.h>
#include <stdlib.h>
void ASSERT(int condition) {
  if (condition != 0) {
    printf("Assert failed");
    exit(1);
  }
}
