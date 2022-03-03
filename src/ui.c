#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

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
  free_tokens(tokens);

  List *new_list = init_history();

  add_history(new_list, "Hello");
  add_history(new_list, "Goodbye");
  add_history(new_list, "Hola");
  print_history(new_list);

  char *ptr = get_history(new_list, 1);
  printf("This is the string: %s\n", ptr);

  free_history(new_list);
  print_history(new_list);
}
