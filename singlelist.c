/***********************************
* ./cw Source Code                 *
* Written by Steven Byrne          *
* References; C for Dummies V 1+2' *
* Advanced Programming Labs        *
************************************/

/*This is a modified version of the singlelist.c file from the labs
  I have heavily modified the sl_push_front method to not only add
  to the linked list, but to also check if a matching string already
  exists before insertion. I have also modifed the sl_display function
  in order to format the output and also display the word as well as the 
  frequency, it was also used as a skeleton to help me write sl_output
  found in main.c*/

// Included header files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "singlelist.h"

/*method to add new words to the linked list, takes a pointer
  to a list and a string as parameters*/
void sl_push_front (struct SLNode **list,  char word[]) {

  struct SLNode *temp = (struct SLNode *)malloc (sizeof (struct SLNode)); //create temporary node
  temp->next = NULL; //set pointer to next node to NULL
  temp->data = 1; //set temporary nodes frequency to 1
  strcpy(temp->str, word); //copy string from input parameter to temporary nodes string


  if(*list){ //checks we are in the list/ that it exists
    struct SLNode *curr = *list; //create current node

    while(curr){ // while current node is not !NULL
      if(strcmp(curr->str, word) == 0){ //if the string of current node is equal to input parameter word
        curr->data += 1; //increment the frequency of current node by 1
        return;
      }
      curr = curr->next; //point to next node in list (until NULL)
    }


    curr = *list; 

    while(curr->next != NULL){
      curr = curr->next;
    }

    curr->next = temp;
  }else{ //if list doesnt exist / we are not in list
    *list = temp; //assign temp node to the pointer for list node
  }


  
}
// method to output list to console
void sl_display (struct SLNode *list) {
  
  while (list) { //while list is not NULL
    printf ("%s\t%i\n", list->str, list->data); //print formatted string featurning word and frequency to console
    list = list->next; //point to next node in list (until NULL)
  }
  return;
}


/*method to perform quick sort on the linked list and sort in ascending order
  taken from labs/learning central*/
void sl_qsort (struct SLNode **list) {
  assert (list);

  if (!*list || !(*list)->next) {
    return;
  }

  int cmp = (*list)->data;
  struct SLNode *middle = (*list);

  struct SLNode *smaller_head = NULL;
  struct SLNode *smaller = NULL;

  struct SLNode *larger_head = NULL;
  struct SLNode *larger = NULL;

  struct SLNode *temp = (*list)->next;
  while (temp) {
    if (temp->data < cmp) {
      if (smaller) {
        smaller->next = temp;
        smaller = temp;
      } else {
        smaller_head = smaller = temp;
      }
    } else {
      if (larger) {
        larger->next = temp;
        larger = temp;
      } else {
        larger_head = larger = temp;
      }
    }
    temp = temp->next;
  }

  if (smaller) {
    smaller->next = NULL;
    sl_qsort (&smaller_head);
    while (smaller->next) {
      smaller = smaller->next;
    }
    smaller->next = middle;
    *list = smaller_head;
  }

  if (larger) {
    larger->next = NULL;
    sl_qsort (&larger_head);
  }
  middle->next = larger_head;

  return;
}



