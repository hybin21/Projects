/*******************************************************************************
 * AUTHOR         : Jessica Hahm, Jibran Khan
 * Lab #11        : Linked List Functions
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 03/01/22
*******************************************************************************/
#include <iostream>
using namespace std;

/*******************************************************************************
 *
 * Linked List Functions
 *_________________________________________________________________
 * <description>
 *  This program reversed the nodes of the linked list
 *    -returns reversed linked list
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 * 
 * OUTPUTS:
 *  returns reversed linked list
 * 
*******************************************************************************/

struct node  // sturcture for linked list
{
  int info;  // CALC/OUT - data of the node
  node * link;  // CALC/OUT - pointer variable points the nex node
};

/*******************************************************************************
 * void reverse(node*& head);
 *  This function reverses the linked list
 *  - returns nothing
 *      
*******************************************************************************/
void reverse(node*& head);  // IN - head of the linked list to be reversed

/*******************************************************************************
 * void display(node* head);
 *  This function displays the linked list
 *  - returns nothing
 *      
*******************************************************************************/
void display(node* head);  // IN - head of the linked list to be displayed

int main() 
{
  node * head = new node; //initializing new node
  node * current; //creaitng new node pointer
  
  int i;        // IN - value to be stored in node's data 
  i = 100;

  current = head; //setting current pointer to head

  // build a linked list backwards 
  head->info = i;
  head->link = NULL;
  i--;
  while(i != 0)
  {
    node * temp = new node;
    temp->info = i;
    temp->link = head;
    head = temp;
    i--;
  }

  display(head); //display
  cout << endl;
  reverse(head); //reverse linked list
  cout << endl;
  display(head); //display linked list
}

/*******************************************************************************
 * void reverse(node*& head)
 *_________________________________________________________________
 * This function reverses the linked list
 *  - void function, returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   node*& head : head of linked list
 *
 * POSTCONDITIONS:
 *  The linked list is reversed
 * 
*******************************************************************************/
void reverse(node*& head) // IN - head of the linked list 
{
  node *current; // CALC - pointer variable to store current position
  
  //setting it to head of linked list
  current = head; 
  
  node *temp;  // CALC - pointe variable to store temporary position
  node *first; // CALC - pointer variable to store position of first
  
  temp = NULL;
  first = NULL;
  

  while(current != NULL) //while the current node is not the last one
  {
    temp = current->link; //temp is node after current
    current->link = first; //node after current is null
    first = current; //first is the current node
    current = temp; //current becomes the node after itself
  }
  head = first; //head point to last node

  
}

/*******************************************************************************
 * void display(node* head)
 *_________________________________________________________________
 * This function displays the linked list
 *   - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   noed *head: head of the linked list
 *
 * POSTCONDITIONS:
 *  The linked list is displayed 
 * 
*******************************************************************************/
void display(node* head)  // IN - head of the linked list 
{
  node *current;    // CALC - pointer variable to store current posiont
  current = head;
  
  // display the info until current is NULL;
  while(current != NULL)
    {
      cout << current->info << " ";
      current = current->link;
    }
    
}