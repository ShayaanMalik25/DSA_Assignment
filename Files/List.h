#include <iostream>
#include "Dictionary.h"
using namespace std;

class ListNode
{ // classs definition of Node
public:
    Dictionary data;
    ListNode *next;
};

// PASTE YOUR LINKED LIST CODE HERE
class SinglyLinkedList
{
public:
    ListNode *start;
    ListNode *last;
    ListNode *loc;
    ListNode *ploc;
    ListNode *sloc;
    SinglyLinkedList()
    {
        start = nullptr;
        last = nullptr;
        loc = nullptr;
        ploc = nullptr;
        sloc = nullptr;
    }
    bool isEmpty()
    {
        return (start == nullptr);
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
    void printList(ListNode *headNode)
    {
        ListNode *temp = headNode;
        while (temp != nullptr)
        {
            cout << (temp->data) << endl;
            temp = temp->next;
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
    void printReverse(ListNode *HeadNode)
    {
        if (HeadNode->next == nullptr)
        {
            cout << HeadNode->data << endl;
        }
        else
        {
            printReverse(HeadNode->next);
            cout << (HeadNode->data) << endl;
        }
    }
    ListNode *reverseList(SinglyLinkedList list)
    {
        ploc = nullptr;
        loc = start;
        // last = headNode;
        while (loc != nullptr)
        {
            sloc = loc->next;
            loc->next = ploc;
            ploc = loc;
            loc = sloc;
        }
        start = ploc;
        return start;
    }
    int Length()
    {
        ListNode *temp = start;
        int length;
        while (temp != nullptr)
        {
            temp = temp->next;
            length += 1;
        }
        return length;
    }
    bool isMatch(string actual, char toCheck)
    {
        for (int i = 0; i < actual.length(); i++)
        {
            if (actual[i] == toCheck)
                return true;
        }
        return false;
    }
    ListNode *filterByLetter(SinglyLinkedList *list, char letter)
    {
        ListNode *temp = list->start;
        int count = 0;
        bool first, end;
        while (temp != nullptr)
        {
            if (isMatch((temp->data).word, letter))
            {
                if (temp == list->start)
                {
                    cout << "First true hai bsdk" << endl;
                    first = true;
                }
                if (temp == list->last)
                    end = true;
                temp = temp->next;
                count += 1;
            }
            else
            {
                ListNode *temp1 = temp;
                temp = temp->next;
                list->deleteValue(temp1->data);
            }
        }
        cout << "LIST FILTERED SUCCESSFULLY" << endl;
        if (count == 0)
            cout << "No Nodes are a match" << endl;
        else if (count < list->Length())
            cout << count << " numbers of nodes are a match" << endl;
        else if (count == list->Length())
            cout << "All nodes are a match" << endl;
        if (first)
            cout << "First node is a match" << endl;
        else if (end)
            cout << "Last node is a match" << endl;
        if (first && end)
        {
            cout << "First and last nodes are also a match" << endl;
        }
        return start;
    }
    bool isEven(string toCheck)
    {
        if (toCheck.length() % 2 == 0)
        {
            return true;
        }
        return false;
    }
    bool isOdd(string toCheck)
    {
        if (toCheck.length() % 2 == 1)
        {
            return true;
        }
        return false;
    }
    ListNode *rearrangeByEvenOddLength(ListNode *headNode)
    {
        ListNode *temp = headNode;
        ListNode *even;
        ListNode *odd;
        ListNode *oddStart;
        // ListNode *evenStart;
        int evenCount = 0, oddCount = 0;
        while (temp != nullptr)
        {
            if (isEven(temp->data.word))
            {
                if (evenCount == 0)
                {
                    // evenStart = temp;
                    start= temp;
                    even = temp;
                }
                else
                {
                    even->next = temp;
                    even = even->next;
                }
                evenCount += 1;
            }
            else
            {
                if (oddCount == 0)
                {
                    odd = temp;
                    oddStart = temp;
                }
                else
                {
                    odd->next = temp;
                    odd = odd->next;
                }
                oddCount += 1;
            }
            temp = temp->next;
        }
        even->next = oddStart;
        cout << evenCount << " Nodes are of even length" << endl;
        cout << oddCount << " Nodes are of odd length" << endl;
        return headNode;
    }
};