#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t

  /*
   * 1. If-statment: Når vi når et punkt,
   * hvor der ikke er en node (t == NULL),
   * så alllokerer den ny plads
   */

  if(t == NULL)
  {
    struct tree_node* temp = malloc(sizeof(struct tree_node));
    temp->item = x;
    temp->left = NULL;
    temp->right = NULL;
    t = temp;

    printf("%d\n", t->item);

    return temp;
  }

  /*
   * 2. If-statment: Hvis x er lig med en
   * en anden allerede, allokereres der
   * plads til en ny node. 
   */

  if(x == t->item)
  {
    struct tree_node* temp = malloc(sizeof(struct tree_node));
    temp->item = x;
    temp->left = t->left;
    temp->right = NULL;
    t->left = NULL;
    t->left = temp;

    return t;
  }

  /*
   * 3. If-statement: Hvis x < t->item
   * så indsætter vi x til venstre.
   * Ellers indsætter vi x til højre. 
   */

  if(x < t->item)
  {
    t->left = Insert(x, t->left);
    
    return t;
  }
  else
  {
    t->right = Insert(x, t->right);

    return t;
  }
}

struct tree_node *Remove(int x, struct tree_node *t) 
{
  // Remove one item from the tree t

  /*
   * If-statement: Hvis vores t = NULL,
   * vil der ikke blive slettet noget.
   */

  if(t == NULL)
    return t;

  /*
   * Nested if-statement af flere betingelser
   */

  if(Contains(x, t) == 0)
    return t;
  else
  {
    if(x == t->item)
    {
      /*
       * Hvis noden ikke har nogen children
       */

      if(t->left == NULL && t->right == NULL)
      {
        struct tree_node* temp = t->right;
        free(t);

        return temp; 
      }

      /*
       * Hvis noden kun har right child
       */
      
      if(t->left == NULL && t->right != NULL)
      {
        struct tree_node* temp = t->right;
        free(t);

        return temp;
      }

      /*
       * Hvis noden kun har left child
       */

      if(t->left != NULL && t->right == NULL)
      {
        struct tree_node* temp = t->left;
        free(t);

        return temp; 
      }

      /*
       * Hvis noden har både left og right child
       */

      if(t->left != NULL && t->right != NULL)
      {
        struct tree_node* temp = t->right;

        while(temp->left != NULL)
        {
          temp = temp->left;
        }

        t->item = temp->item;
        free(temp);

        return t;
      }
    }

    else if(x < t->item)
    {
      t->left = Remove(x, t->left);

      return t;
    }

    else if(x > t->item)
    {
      t->right = Remove(x, t->right);

      return t;
    }
  }
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.

  /*
   * While loop: For at tjekke om værdien vi kigger efter
   * er i træet eller ej
   */

  while(t != NULL)
  {
    if(x == t->item)
      return 1;
    else if(x < t->item)
      t = t->left;
    else
      t = t->right;
  }


  return 0;
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree

  t = NULL;

  return t;
}

int Empty(struct tree_node *t) {
  // Test if empty

  if(t == NULL)
  {
    return 1;
  }

  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}
