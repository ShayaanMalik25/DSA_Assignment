#include <iostream>
#include "Dictionary.h"
using namespace std;

class ListNode{   //classs definition of Node 
  public:
    Dictionary data;
    ListNode *next;
};

//PASTE YOUR LINKED LIST CODE HERE
class SinglyLinkedList{
public:
ListNode* start;
ListNode* last;
ListNode* loc;
ListNode* ploc;
SinglyLinkedList(){
  start = nullptr;
  last = nullptr;
  loc = nullptr;
  ploc = nullptr;
}
bool isEmpty(){
  return start==nullptr;
}
void insertAtFront(Dictionary val)
    {
        ListNode *nn = new ListNode();
        nn->data = val;
        if (isEmpty())
        {
            start = nn;
            last = nn;
            nn->next = nullptr;
        }
        else
        {
            nn->next = start;
            start = nn;
        }
    }
void insertAtEnd(Dictionary val)
{
    ListNode *nn = new ListNode();
    nn->data = val;
    if (isEmpty())
    {
        last = nn;
        start = nn;
        nn->next = nullptr;
    }
    else
    {
        last->next = nn;
        last = nn;
    }
}
void searchValue(Dictionary val)
{
    loc = start;
    ploc = nullptr;
    while (loc != nullptr && loc->data < val)
    {
        ploc = loc;
        loc = loc->next;
    }
    if (loc != nullptr and loc->data != val)
    {
        loc = nullptr;
    }
}
void insertSorted(Dictionary val)
    {
        searchValue(val);
        if (loc == nullptr)
        {

            if (ploc == nullptr)
            {
                insertAtFront(val);
            }
            else
            {
                if (ploc == last)
                {
                    insertAtEnd(val);
                }
                else
                {
                    ListNode *nn = new ListNode();
                    nn->data = val;
                    nn->next = ploc->next;
                    ploc->next = nn;
                }
            }
        }
    }
void printList()
    {
        ListNode *temp = start;
        if (!(isEmpty()))
        {
            while (temp != nullptr)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
void deleteValue(Dictionary val)
    {
        if (isEmpty())
        {
            cout << "Invalid Command!" << endl;
        }
        else
        {
            searchValue(val);
            if (loc != nullptr)
            {
                if (ploc == nullptr)
                {
                    start = loc->next;
                    delete loc;
                }
                else
                {
                    if (loc == last)
                    {
                        last = ploc;
                        ploc->next = loc->next;
                        delete loc;
                    }
                    else
                    {
                        ploc->next = loc->next;
                        delete loc;
                    }
                }
            }
        }
    }
void printReverse(ListNode *HeadNode){
    if (HeadNode->next==nullptr){
        cout<<HeadNode->data;
    }
    else{
        printReverse(HeadNode->next);
        cout<<(HeadNode->next)->data<<endl;
    }
} 

};