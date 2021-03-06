
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *list = (List*) calloc(1, sizeof(List));

  return list;
}

int stringLength(char *str){
  int strLength = 0;
  //printf("DEBUG - In the stringLength method. First character:%c.\n", *str);
  while(*str != '\0'){
    //printf("DEBUG - In history stringLength method. Character being counted:%c.\n", *str);
    strLength++;
    *str++;
    
  }
  printf("DEBUG - strLength count:%d.\n", strLength);
  return strLength;
}

void add_history(List *list, char *str){
  Item *newItem = (Item*) malloc(sizeof(Item));
  Item *currentItem = list->root;
  int idx;
  int strLength = stringLength(str);

  printf("DEBUG - In history add_history method.\n");
  newItem -> str = copy_str(str, strLength);

  if(currentItem == NULL){
    list->root = newItem;
    newItem->id = 1;
  }
  else{
    while(currentItem -> next != NULL){
      currentItem = currentItem->next;
      idx++;
    }
    currentItem -> next = newItem;
    newItem -> id = currentItem -> id + 1;
  }
}

void print_history(List *list){
  Item *currentItem = list->root;
  int idx = 0;

  printf("DEBUG - In history print_history method.\n");
  while(currentItem){
    printf("History: Index %d. String: %s.\n", idx, currentItem->str);
    idx++;
    currentItem = currentItem -> next;
  }
}

char *get_history(List *list, int id){
  Item *currentItem = list -> root;
  while(currentItem){
    if(currentItem -> id == id){
      printf("DEBUG - In history get_history method. Returning string is:%s.\n", currentItem -> str);
      return currentItem -> str;
    }
    currentItem =  currentItem -> next;
  }
}

void free_history(List *list){
  Item *currentItem = list -> root;
  Item *previousItem;

  printf("DEBUG - In history free_history method.\n");
  while(currentItem){
    previousItem = currentItem;
    currentItem  = currentItem -> next;

    free(previousItem -> str);
    free(previousItem);
  }
  free(list);
}
