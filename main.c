/***********************************
* ./cw Source Code                 *
* Written by Steven Byrne          *
* References; C for Dummies V 1+2' *
* Advanced Programming Labs        *
************************************/

//included libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "singlelist.h"

int main (int argc, char *argv[]) {

  //Initializing of variables
  int l; // used to loop through length of file
  int length = 0; //used to determine length and positions in buffer
  char c; //used to show characters read in from ASCII file
  char buf[60]; //string buffer to hold characters to make a word
  int filelength; //used to determine the length of the ASCII file
  int wordcount =0; //used to count the number of words in the ASCII file

  struct SLNode *list = NULL;
  FILE *myfile; //pointer for inputfile
  FILE *outputfile; //point for outputfile

  if(argc < 3) //output error if number of cmdline arguments entered is less than 3
  {
    printf("ERROR: please enter input+output file (e.g. ./cw filename.txt filename.csv)");
    return 0; //exit program
  }

  if(!myfile) //output error if filename entered in argv[1] is not found
  {
    printf("ERROR: %s not found!",argv[1]);
    return 0; //exit program NOT WORKING
  }
  
  myfile = fopen(argv[1], "r"); //myfile is to open the file entered in first arguement in read mode
  outputfile = fopen(argv[2],"w"); //outputfile is to open the  file entered in second arguement in read mode

  

  /*Find File Size (Number of chars plus NULL byte)*/
  fseek(myfile, 0 ,SEEK_END);
  filelength = ftell(myfile);
  fseek(myfile, 0 , SEEK_SET);

  
  /*method for outputting results to file*/
  void sl_output (struct SLNode *list) {
      fprintf (outputfile,"word,frequency\n"); //print column headers to file
      
      while (list) { //loop through linked list
       fprintf (outputfile,"%s,%i\n", list->str, list->data); //print word and frequency to file
        list = list->next; //move to next node until list = NULL
     }
    return;
  }

  for(l=0; l<filelength; l++){ //loop through for number of characters n ASCII file
    c = fgetc(myfile); //c is equal to next character pulled from ASCII file
    if(isalpha(c)){ // if c is 'a' - 'z or 'A to 'Z'....
      buf[length] = tolower(c); // add c in lowercase to the array buffer at position equal to current length
      length++; //increment length by 1
      
    }
    else{ //if c is not alphanumeric (special characters, space etc....)
      sl_push_front (&list,  buf);// insert current buff into list
      memset(buf,'\0', sizeof(buf)); //set every position in buf to NULL resetting the string
      length = 0; // set word length back to 0
      wordcount++; //increment wordcount by 1

    }

  }
  /*Some Command Line output...*/
  printf("opened %s\n",argv[1]);
  printf("total number of words; %i\n",wordcount);
  printf ("Words in ascending order of Frequency:\n");
  sl_qsort (&list); //quick sort operation on the words frequency, sorting in ascending order
  sl_display (list); //print out the linked list to the console
  sl_output (list); //print the linked list to the file specified in argv[2]
  fclose(myfile); //close input file
  fclose(outputfile); //close output file
  return 0; //end program
}