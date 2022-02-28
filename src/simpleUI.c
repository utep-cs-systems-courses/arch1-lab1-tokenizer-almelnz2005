#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define LIMIT 200

void menuOptions(char *command, int strCacheLength, List *stringCache){
  int idOfHistoryPlace;
  char *strReturned;
  char temp;
  
  if(command[1] == 'q'){
    //printf("DEBUG - Free memory.\n");
    //printf("DEBUG - Quiting software.\n");
    printf("-------------Quiting Software-------------\n");
    printf("------------------------------------------\n");
    free_history(stringCache);
    exit(EXIT_SUCCESS);
  }
  else if(command[1] == 'h'){
   //printf("DEBUG - Printing String Cache");
   printf("-------------String Cache------------\n");
   print_history(stringCache);
   printf("-------------------------------------\n");
  }
  else{
    idOfHistoryPlace = command[2] - '0';
    //printf("DEBUG - Index of history:%d./n", idOfHistoryPlace);
    strReturned = get_history(stringCache, idOfHistoryPlace);
    printf("-------------History Query-------------\n");
    printf("String returned at index %d is: %s.\n", idOfHistoryPlace, strReturned);
    printf("---------------------------------------\n");
  }
  
}

void main(){
  char command[LIMIT];
  //char test; //Variable used to test the space_char and non_space_char methods
  //int checkWhiteSpace; //Variable used to test the space_char and non_space_char methods
  //int checkAnyOtherChar; //Variable used to test the space_char and non_space_char methods
  //char *letterReturned;
  //int wordCount = 0;
  //char *strReturned;
  //short len;
  int strLength;
  char **tokens;
  List *stringCache = init_history();
  int stringCacheLength = 0;
  char *copyCommand;

  printf("-------------Lab 1 - Tokenizer-------------\n");
  printf("Available Commands: \n\t1. Type and store a new string.\n\t2. '@(num)' To a previous string or command.\n\t3. '@h' Display all previous entries.\n\t4. '@q' Quit Tokenizer\n");
  
  while(1){
    //printf("DEBUGGING: In the SimpleUI main method.\n");
    printf(">>> ");
    scanf("%[^\n]%*c",command);
    //printf("DEBUG In main - Print variable: %s.\n", &command);

    //strLength = stringLength(command);
    //copyCommand = copy_str(command, strLength);
    //printf("DEBUG - In main testing copied command:%s.\n", copyCommand);
    //printf("DEBUG - In main testing the stringLength method. Length:%d.\n", strLength);
    
    if(command[0] == '@'){
      //printf("DEBUG - In main. Command working.\n");
      menuOptions(command, stringCacheLength, stringCache);
    }
    else{
      //add_history(stringCache, copyCommand);
      //-----------------------------------------------------
      //Code used to test add_history and print_history
      //-----------------------------------------------------
      //printf("DEBUG - In main testing print_history.\n");
      //print_history(stringCache);
      //printf("----------------------------------------\n");
      //printf("DEBUG - just another string. No command:%s\n", command);
      tokens = tokenize(command);
      print_tokens(tokens);
      //add_history(stringCache, copyCommand);
      free_tokens(tokens);
    }
    //-----------------------------------------------------
    //Code used to test stringLength method - worked but not at the end of the code.
    //-----------------------------------------------------
    //printf("DEBUG - In main after all completed. Print variable: %s.\n", &command);
    //strLength = stringLength(command);
    //printf("DEBUG - In main. After stringLength method:%d.\n", strLength);
    //------------------------------------------------------
    //Code used to test tokenize method
    //------------------------------------------------------
    //while(*tokens != 0){
    //  printf("DEBUG In Main - Printing Tokens:%s\n.", *tokens);
    //  tokens++;
    //}
    //------------------------------------------------------
    //Code use to test copy_str method
    //------------------------------------------------------
    //len = 6;
    //strReturned = copy_str(name, len);
    //printf("DEBUG In main after copy_str - Print strReturned.\n");
    //while(*strReturned != '\0'){
    //  printf("%c", *strReturned++);
    //}
    //printf("\n");
    //------------------------------------------------------
    //Code used to  test word_terminator method
    //------------------------------------------------------
    //letterReturned = word_terminator(name);
    //printf("DEBUG In main after word_terminator - Print retptr:%c.\n", *letterReturned);
    //------------------------------------------------------
    //Code used to test count_words method
    //------------------------------------------------------
    //wordCount = count_words(name);
    //printf("DEBUG In main - Number of words: %d.\n", wordCount);
    //-------------------------------------------------------
    //Code used to test word_start method
    //-------------------------------------------------------
    //letterReturned = word_start(name);
    //printf("DEBUG In main after word_start - Print retptr:%c.\n", *letterReturned);
    //-------------------------------------------------------
    //Code used to test space_char and non_space_char methods
    //-------------------------------------------------------
    //test = getchar();
    //getchar();
    //printf("DEBUG In main - Print varriable:%c.\n", test);
    //checkWhiteSpace = space_char(&test);
    //checkAnyOtherChar = non_space_char(&test);
    //printf("DEBUG In main - Checked for white space:%i.\n", checkWhiteSpace);
    //printf("DEBUG In main - Checked for anyother character:%i.\n", checkAnyOtherChar);
    //-------------------------------------------------------
  }
}
