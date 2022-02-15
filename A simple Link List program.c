//This is a simple Singly Linked List program....
//I took the main idea from here >> https://www.programiz.com/dsa/linked-list

#include <stdio.h>
#include <stdlib.h>

// first Creating a node
struct node {
  int value;
  struct node *next;
};

// print the linked list value
void printLinkedlist(struct node *i) {
  while (i != NULL) {
    printf("%d ", i->value);
    i = i->next;
  }
}

int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  // Allocate memory
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  // Assign value values manually
  //   //one->value = 1;
  //   two->value = 2;
  //   three->value = 3;

  // Assigning values from user
  scanf("%d",&one->value);
  scanf("%d",&two->value);
  scanf("%d",&three->value);
    

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // printing node-value
  //in head we store the adress of first node for futher works
  head = one;
  printLinkedlist(head);
}
