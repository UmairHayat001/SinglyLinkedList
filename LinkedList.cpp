
#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int val) : data(val),next(nullptr){}
};
class LinkedList
{
    Node* head;
public:
    LinkedList();
    ~LinkedList();
    void addAtHead(int);
    void addAtTail(int);
    void addBefore(int,int);
    void addAfter(int,int);
    void deleteAtHead();
    void deleteAtTail();
    int getSize();
    void display();
    Node* search(int);
    void deleteBefore(int);
    void deleteAfter(int);
};
#endif /* LinkedList_hpp */
//------------------------------------------------

#include "LinkedList.hpp"
LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::~LinkedList()
{
    while(head)
    {
        deleteAtHead();
    }
}

void LinkedList::addAtHead(int value)
{
    if (!head)
    {
        head = new Node(value);
        return;
    }
    Node* temp = head;
    head = new Node(value);
    head->next = temp;
}
void LinkedList::addAtTail(int value)
{
    if (!head)
    {
        head = new Node(value);
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node(value);
}
void LinkedList::addAfter(int targetValue,int newValue)
{
    Node* temp = search(targetValue);   //
    if(!temp)
        return;
    Node* temp2 = temp->next;   //
    temp->next = new Node(newValue);
    temp->next->next = temp2;
}
void LinkedList::addBefore(int targetValue,int newValue)
{
    Node* temp = search(targetValue);
    if(!temp)
        return;
    Node* tempStart = head;
    if (tempStart == temp)
    {
        addAtHead(newValue);
        return;
    }
    while(tempStart->next != temp)
        tempStart = tempStart->next;
    tempStart->next = new Node(newValue);
    tempStart->next->next = temp;
}
void LinkedList::deleteAtHead()
{
    if(!head)
        return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
void LinkedList::deleteAtTail()
{
    Node* temp = head;
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
int LinkedList::getSize()
{
    int count = 0;
    Node* temp = head;
    while(temp->next != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count+1;
}
void LinkedList::display()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}
Node* LinkedList::search(int value)
{
    Node* temp = head;
    while(temp)
    {
        if (temp->data == value)
            return temp;
        else
            temp = temp->next;
    }
    return temp;
}
void LinkedList::deleteAfter(int targetValue)
{
    Node* temp = search(targetValue);
    if (!temp || !(temp->next))
        return;
    Node* temp2 = temp->next->next;
    delete temp->next;
    temp->next = temp2;
}
void LinkedList::deleteBefore(int targetValue)
{
    Node* temp = search(targetValue);
    if (!temp || head==temp)
        return;
    if(temp == head->next)
    {
        deleteAtHead();
        return;
    }
    Node* movingPtr = head;
    while(movingPtr->next->next->data != targetValue)
        movingPtr = movingPtr->next;
    delete movingPtr->next;
    movingPtr->next = temp;
}


