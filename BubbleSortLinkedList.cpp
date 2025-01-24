#include<iostream>
#include<conio.h>
using namespace std;
void createList(int value);
void bubbleSortList();
void display();
struct Node{
    int data;
    Node* next;
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
            bubbleSortList();
            display();
    return 0;
}

void  createList(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if(!head)
    {
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
void bubbleSortList()    //function to sort linkedlist in Ascending order
{   
    if(!head) 
	{
		cout<<"List is Empty!\n";
	}  
	 bool swapped;
	do{
    Node* ptr1 = head;
    Node* lastptr = NULL;
    swapped = false;
    while(ptr1->next!=lastptr)
    {
      if(ptr1->data>ptr1->next->data)
      {
      	int temp = ptr1->data;
      	ptr1->data = ptr1->next->data;
      	ptr1->next->data = temp;
      	swapped = true;
	  }
	  ptr1 = ptr1->next;
    }
    lastptr = ptr1;
}while(swapped);
}
void display()                  //function to display linkedlist
{
    if(!head)
    {
        cout<<"List is Empty!\n";
        return;
    }
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}