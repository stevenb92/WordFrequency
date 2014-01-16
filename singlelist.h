/***********************************
* ./cw Source Code                 *
* Written by Steven Byrne          *
* References; C for Dummies V 1+2' *
* Advanced Programming Labs        *
************************************/

/*header file from labs modified to add a new definition for output method
as well as changing the structure of linked list to incorporate a string to 
hold the word (assuming max word size will be 20 characters)*/

#ifndef SINGLELIST_H
#define SINGLELIST_H 1

struct SLNode {
  struct SLNode *next;
  int data;
  char str[20];
};

void sl_push_front (struct SLNode **list, char word[]);
void sl_display    (struct SLNode *list);
void sl_output (struct SLNode *list);
void sl_qsort      (struct SLNode **list);

#endif /* SINGLEIST_H */



