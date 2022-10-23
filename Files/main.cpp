#include "Parser.h"

using namespace std; 

int main()
{
  SinglyLinkedList *list = new SinglyLinkedList();
  // SinglyLinkedList list;
  // mainMenu(); //call the main menu function from Parser.h
  readFileData(list);
  writeToFile(list->start);
//   list->printReverse(list->start);
  
//  cout<<list->reverseList(*list);
 
//   list->printList(list->start);
//  cout<<list->start->data;
 cout<<list->filterByLetter(list,'z');
  cout<<endl<<list->start->data;
  list->printList(list->start);
  return 0;
}