#include<iostream>
#include<conio.h>
using namespace std;
void createList(int value);
void insertionSort();
void display();
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* tail = NULL;
int main()
{
 char opt;
      do{
            int number;
            cout<<"Plz Enter a Node:";
            cin>>number;
            createList(number);
            cout<<"DO YOU WANT TO ADD ANOTHER NODE?:";
            cin>>opt;
            }while(opt=='Y'||opt=='y');
            insertionSort();
            display();
    return 0;
}

void  createList(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(!head)
    {
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertionSort()
{
    Node* current = head;
    Node* sorted = nullptr;
    while(current!=nullptr)
    {
        Node* nextNode = current->next;
        if(sorted == nullptr || sorted->data>= current->data)
        {
            current->next= sorted;
            if(sorted!=nullptr){
            sorted ->prev = current;}
            sorted =  current;
        }
        else{
            Node* temp = sorted;
            while(temp->next!= nullptr && temp->next->data<current->data)
            {
                temp = temp -> next;
            }
              current->next = temp->next;
              if(temp->next!=nullptr){
              temp->next->prev = current;}
              temp->next = current;
              current ->prev = temp;
        }
        current = nextNode;
    }
    head = sorted;
}
void display()                  //function to display linkedlist
{
    if(!head)
    {
        cout<<"List is Empty!\n";
        return;
    }
    Node* temp = head;
    cout<<"Sorted List:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL";
}