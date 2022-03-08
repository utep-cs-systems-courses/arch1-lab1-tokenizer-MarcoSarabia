#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

char *getInput(){

  char c;
  char *str = (char*)malloc(sizeof(char));
  int i = 0;
  
  printf(">");
  while((c = getchar()) != EOF && c != '\n'){
    *(str + i) = c;
    i++;
  }

  return str;
}

int main(void){
  printf("Welcome to TOKENIZE! Select one of the following options\n");

  char *string;
  char **tokens;
  List *history = init_history();
  while(1){
    printf("'1' = tokenize | '2' = print tokens | '3' = delete tokens\n");
    printf("'4' = print history | '!3' recall history item | 'q' = exit the program\n");
    printf("\n");
    
    string = getInput();
    //printf("%s\n", string);

    if(*string == 'q'){
      printf("Thank you for using this program!\n");
      break;
    }
    
    switch(*string)
    {
    case '1':
      printf("You chose to 'tokenize'! Please enter the String you would like to tokenize:\n");
      string = getInput();
      tokens = tokenize(string);
      add_history(history, string);
      break;

    case '2':
      printf("You chose to 'print tokens'\n");
      print_tokens(tokens);
      break;

    case '3':
      printf("You chose to 'delete tokens\n'");
      free_tokens(tokens);
      break;

    case '4':
      printf("You chose to 'print history'\n");
      print_history(history);
      break;

    case '5':
      printf("You chose to 'retrieve item from history'\n");
      printf("please enter the element id:\n");
      printf(">");
      
      int id; 
      scanf("%d", &id);
      tokens = tokenize(get_history(history, id));
      break;
    }
  }
}
