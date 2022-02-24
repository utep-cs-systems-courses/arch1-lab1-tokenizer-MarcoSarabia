#include <stdio.h>
//#include "tokenizer.c"
#include "tokenizer.h"
#include "history.h"

void getInput(){

  int c;

  printf(">");
    while((c = getchar()) != EOF && c != '\n' ){
    putchar(c);
  }
  printf("\n");
  
  
}

int main(void){
  char string[] = "Hello my name is Marco";
  char **tokens = tokenize(string);
  print_tokens(tokens);
  free_tokens(tokens);
  print_tokens(tokens);
}
