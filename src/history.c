#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List *list1 = (List*)malloc(sizeof(List));
  list1-> root = NULL;
  return list1;
}

void add_history(List *list, char *str){
  
  Item *new_node = (Item*)malloc(sizeof(Item));
  new_node-> str = str;
  new_node-> next = NULL;
  
  Item *temp = list->root;

  if(!temp){
    new_node-> id = 0;
    list-> root = new_node;
    return;
  }
  int i = 1;
  while(temp-> next){
    temp = temp->next;
    i++;
  }
  new_node-> id = i;
  temp-> next = new_node;
}

char *get_history(List *list, int id){
  if(!(list-> root)){
    printf("Sorry but you have no history:(\n");
    return '\0';
  }

  Item *temp = list-> root;
  for(int i = 0; i < id; i++){
    temp = temp-> next;
  }

  return temp-> str;
}

void print_history(List *list){
  if(!(list-> root)){
    printf("Sorry but you have no history:(\n");
    return;
  }

  Item *temp = list-> root;
  while(temp){
    printf("[%d] - %s\n", temp-> id, temp-> str);
    temp = temp-> next;
  }
}

void free_history(List *list){
  Item *temp = list-> root;

  while(list-> root){
    temp = list-> root;
    list-> root = list-> root-> next;
    free(temp);
  }
  free(list);
}
