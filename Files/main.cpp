#include "Parser.h"

using namespace std; 

int main()
{
  SinglyLinkedList *list = new SinglyLinkedList();
  // SinglyLinkedList list;
  // mainMenu(); //call the main menu function from Parser.h
  readFileData(list);
  writeToFile(list->start);
  // list->printReverse(list->start);
  
 cout<<list->reverseList(list->start,list->last);
 
//  cout<<list->start->data;
  list->printList(list->ploc);
  return 0;
}