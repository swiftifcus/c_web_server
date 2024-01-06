#include <stdlib.h>
#include <stdio.h>

struct List
{
  struct List *prev;
  struct List *next;
  struct List *last;
  int value;
};

struct List add_to_back(struct List *list, int newValue)
{
  struct List newNode;
  list->next = &newNode;
  newNode.prev = list;
  newNode.value = newValue;
  newNode.next = NULL;
  newNode.last = &newNode;
  return newNode;
}

void add_to_front(struct List *list, int newValue)
{
  struct List newNode;
  newNode.value = newValue;
  newNode.next = list;
  newNode.prev = NULL;
  if (list != NULL) {
    list->prev = &newNode;
  }
  list = &newNode;
}

int main(void)
{
  struct List beginning =
      {
          NULL,
          NULL,
          &beginning,
          1,
      };

  printf("beginning: %d\n", beginning.value);

  add_to_back(&beginning, 2);
  printf("next: %d\n", beginning.next->value);
  add_to_front(&beginning, 3);
  printf("after adding to frond %d, %d\n", beginning.value, beginning.prev->value);
  return 0;
}