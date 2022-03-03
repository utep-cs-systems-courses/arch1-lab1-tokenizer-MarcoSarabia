#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/*Returns 1 if c is a whitespace character (like ' ' or '\t')*/
int space_char(char c){
  if (c == ' ' || c == '\n' || c == '\t'){
    return 1;
  }

  return 0;
}

/*Returns 1 if c is a non_whitespace character 
  (like ' ' or '\t')*/
int non_space_char(char c){
  if (c == ' ' || c == '\n' || c == '\t'){
    return 0;
  }
  return 1;
}

/*Returns a pointer to the first character of 
  the next space-separated word in zero-terminated
  str. Returns a zero pointer is str does not 
  contains any words*/
char *word_start(char *s){

  while(*s){

    if(non_space_char(*s)){
      
      return s;
    }
    ++s;
  }

  return '\0';
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){

  while(*word){
    if(space_char(*word)){
      return word;
    }
    ++word;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *s){

  int IN;
  int num_words = 0;

  IN = non_space_char(*s);
  while(*s){
    
    if((IN && space_char(*s)) || (IN && *(s + 1) == '\0')){
      ++num_words;
      IN = 0;
    }
    
    IN = non_space_char(*s);
    s++;
  }
  return num_words;
}

/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *ptr;
  ptr = (char*)malloc(sizeof(char) * (len + 1));

  for(int i = 0; i < len; i++){
    *(ptr + i) = *(inStr + i);
  }
  *(ptr + len) = '\0';
  
  return(ptr);
}

char **tokenize(char* str){
  int num_tokens = count_words(str);
  char **tokens = (char**)malloc(sizeof(char*) * num_tokens + 1);
  char *beginning;
  char *end;
  int word_len;

  end = word_start(str);
  for(int i = 0; i < num_tokens; ++i){
    
    beginning = word_start(end);
    end = word_terminator(beginning);
    word_len = end - beginning;

    *(tokens + i) = copy_str(beginning, word_len);
    // printf("tokens[%d] = %s\n", i, *(tokens + i));
  }
   *(tokens + num_tokens) = '\0';
  return tokens;
}

void print_tokens(char **tokens){
  int i = 0;
  while(*tokens){
    printf("tokens[%d] = %s\n", i, *tokens);
    i++;
    *tokens++;
  }
}

void free_tokens(char **tokens){
  int i = 0;
  while(*(tokens + i)){
    // printf("Deleating tokens[%d] = %s\n", i, *(tokens + i));
    free(*(tokens + i));
    i++;
  }
  free(tokens);
}
