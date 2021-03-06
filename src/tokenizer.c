#include <stdio.h>
#include <stdlib.h>

int space_char(char* c){
  int charInt = (int)*c;
  //Code used to test space_char working properly.
  //printf("DEBUG In tokenizer space_char method. Character passed c:%c.\n", *c);
  //printf("DEBUG In tokenizer space_char method. Character passed c and charInt:%c %i.\n", *c, charInt);
  if(charInt == 32 || charInt == 9){
    //Code used to test if statment in space_char
    //printf("DEBUG In tokenizer space_char method if true - This is a space or tab.\n");
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  //Code used to test non_space_char working properly
  //printf("DEBUG In tokenizer non_space_char method. Character passed c and charInt:%c %i.\n", *c, charInt);
  if(c != ' ' && c != '\t' && c != '\0'){
    //Code used to test if statement in non_space_char
    //printf("DEBUG In tokenizer non_space_char method if true - This is a space or tab.\n");
    return 1;
  }
  return 0;
}

//char *word_start(char *str){

  //char *letterToRtn;
  
//  printf("DEBUG In tokenizer word_start method:%s.\n", str);
  //Aditional code used to test word_start
  //if(*str == '\0'){
  //  printf("DEBUG In tokenizer word_start method if function when str is null.\n");
  //  return str;
  //}
//  printf("DEBUG In tokenizer word_start method printing on character at a time.\n");
//  while(*str != '\0'){
//    //Code used to test for spaces
//    //if(*str == ' '){
//    //  printf("DEBUG - Detected space.\n");
//    //}
//    //printf("DEBUG: %c\n", *str++);
//    printf("DEBUG: %c\n", *str);
//    if(space_char(str) == 1){
//      printf("DEBUG Checking for space using space_char and character being passed:%c.\n", *str);
//      *str++;
//      letterToRtn = str;
//      printf("DEBUG Charater in letterToRtn:%c\n", *letterToRtn);
//      return letterToRtn;
//    }
//    *str++;
//  }
  //missing what happens if no space is found of there is no word.
//  printf("DEBUG If one or no words passed, this is the character being returned:%c\n", *str);
//  return letterToRtn;
//}

char *word_start(char *str){
  while(*str != '\0'){
    //printf("DEBUG - In word_start method. Current character is:%c.\n", *str);
    if(non_space_char(*str)){
      //printf("DEBUG - Returning the following character:%c.\n", *str);
      return str;
    }
    *str++;
  }
  return 0;
}

int count_words(char *str){
  int countWords = 0;
  //printf("DEBUG In tokenizer count_words method.\n");
  if(*str == '\0'){
    //printf("DEBUG In tokenizer count_words method If statement checking for no words:%d\n.", countWords);
    return countWords;
  }
  while(*str != '\0'){
    //printf("DEBUG - Checking on every character. Current character:%c.\n", *str);
    if(space_char(str) == 1){
      //printf("DEBUG - Character is a space:%c.\n", *str);
      countWords++;
    }
    //printf("DEBUG - Current number of words:%d.\n", countWords);
    *str++;
  }
  countWords++;
  //printf("DEBUG - Total number of spaces:%d.\n", countWords);
  return countWords;
}

char *word_terminator(char* word){
  //printf("DEBUG - In tokenizer word_terminator method:%s.\n", word);
  while(word != 0){
    //printf("DEBUG - *word:%c.\n", *word);
    if(!non_space_char(*word)){
      return word;
    }
    word++;
  }
  return 0;
}

char *copy_str(char *inStr, short len){
  char *strToRtn = (char*) malloc(sizeof(char)*(len + 1));
  char *copyOfStr = strToRtn;
  
  //printf("DEBUG - In copy_str method strToRtn is:%c.\n", *strToRtn);
  for(int i = 0; i < len; i++){
    *strToRtn = *inStr;

    //printf("DEBUG - In for loop copyOfStr:%c.\n", *strToRtn);
    if(*inStr = '\0'){
      break;
    }
    strToRtn++;
    inStr++;
  }
  *strToRtn = '\0';
  return copyOfStr;
}

char **tokenize(char *str){
  int numOfWords = count_words(str);
  //printf("DEBUG - Counting Words:%d.\n", numOfWords);

  char **tokens = malloc(sizeof(char*)*(numOfWords + 1));

  str = word_start(str);

  for(int i = 0; i < numOfWords; i++){
    char *terminatorWord = word_terminator(str);
    tokens[i] = copy_str(str, terminatorWord - str);
    //printf("DEBUG - Testing for statmement in breakToTokens method.\n");
    //printf("DEBUG - Break into tokens. Current token:%s.\n", *tokens[i]);
    str = word_start(terminatorWord);
  }

  char **terminatorWord = tokens + numOfWords;
  *terminatorWord = 0;
  //while(*tokens != 0){
  //  printf("DEBUG - Break into tokens method. Complete. Token:%s.\n", *tokens);
  //  tokens++;
  //}
  
  return tokens;
}

void print_tokens(char **tokens){
  int tokenCount = 0;
  while(*tokens != 0){
    printf("Token on index %d is: %s.\n", tokenCount, *tokens);
    tokenCount++;
    tokens++;
  }
}

void free_tokens(char **tokens){
  //printf("DEBUG - In tokenizer free_tokens method.\n");
  char **copyOfTokens = tokens;

  while(*copyOfTokens !=0){
    free(*copyOfTokens);
    copyOfTokens++;
  }
}
