#include "Parser.h"

using namespace std; 
SinglyLinkedList *list = new SinglyLinkedList();
int main()
{
  // SinglyLinkedList list;
  // mainMenu(); //call the main menu function from Parser.h
  readFileData(list);
  writeToFile(list->start);
  // list->printList();
  return 0;
}