#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  // There is NO testcode for this

  /*
   * if-statement. Hvis p ikke er 0,
   * så printer vi noden, den er ved
   */

  if(p == NULL)
    return;
  else
    {
      printf("%d", p->value);
      print_list(p->next);

      return;
    }
}

int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp

  /*
   * if-statement. Hvis p ikke er 0,
   * så ganger vi p-værdien med sig selv
   * og så tilføjer det til sum_squares
   */

  if(p == NULL)
    return 0;
  else
    {
      return p->value * p->value + sum_squares(p->next);
    }

  return -1;
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3

  /*
   * If-statement; hvis p er NULL,
   * så returnerer vi NULL. Hvis 
   * p ikke er NULL, så kører vi 
   * make_node, hvor værdien og mapper
   * (p->next,f), som den næste pointer
   */

  if(p == 0)
    return NULL;
  else
    {
      return make_node(f(p->value), map(p->next, f));
    }
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
