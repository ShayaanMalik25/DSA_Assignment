#include "Parser.h"

using namespace std; 

int main()
{
  SinglyLinkedList *list = new SinglyLinkedList();
  // SinglyLinkedList list;
  // mainMenu(); //call the main menu function from Parser.h
  readFileData(list);
  writeToFile(list->start);
  // list->printList();
  return 0;
}