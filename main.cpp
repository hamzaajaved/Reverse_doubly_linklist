#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
  struct Node *next;
  struct Node *prev;
  int value;
};

struct Node *start = NULL;

void insert(int val);
void print();
void reverse();

int main(int argc, char const *argv[])
{
  /* code */
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50); 
  print();
  cout << "Reversed!!" << endl;
  reverse();
  print();
  system("pause");
  return 0;
}


void insert(int val){
  struct Node *ptr;
  ptr = (struct Node*) malloc (sizeof(struct Node));
  ptr->next = NULL;
  ptr->prev = NULL;
  ptr->value = val;

  if(start == NULL){
    start = ptr;
  }else{
    struct Node *curr = start;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = ptr;
    ptr->prev = curr;
  }
}

void print(){
  if(start == NULL){
    cout << "List is Empty" << endl;
  }else{
    struct Node *curr = start;
    while(curr != NULL){
      cout << curr->value << endl;
      curr = curr->next;
    }
  }
}


void reverse(){
  struct Node *curr = start;
  if(start == NULL){
    cout << "List is Empty" << endl;
  }else if(curr->next == NULL){
    return;
  }else{
      struct Node *temp = NULL;
      while (curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
      }
      if(temp != NULL){  // When Node is Single
        start = temp->prev;
      }
  }
}