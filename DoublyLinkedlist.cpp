/* ********************************************************************************************************************************************
This is Single LinkedList Program of Data Structures and Algorithms in Cpp,in this program some common operations on linkedlist are performed.
This is the Optimized Code, here I used nullptr instead of NULL because it is more type safer,clear and less ambiguous than NULL.
In addition to this I also used new tail technique for insertion at last,which decreases time complexity from O(n) to O(1).
************************************************************************************************************************************************/

//#include <iostream>
//#include<list>
#include<bits/stdc++.h>    //including libraries
//#include<cstdlib>
using namespace std;
void insertAtLast(int value);
void insertAtFirst(int value);
void display();
void search(int value);
void countOccurrence(int value);   //functions definitions
void findMax();
void findMin();
void findAverage();
void deallocate();
void insertAtPos(int value,int ind);
void deleteFirst();
void deleteLast();
void deleteAtPos(int ind);
void createList(int value);
int  calLength();
void sortListAscending();
void sortListDescending();
void insertAtLast_Optimized(int value);
struct Node
{
    int data;
    Node* next; 
    Node* previous;        //structure
};
Node* head_first = nullptr;
Node* head_last = nullptr;
int main()                    //main function
{
    char choice;
    cout<<"----------------Single Linked-List Operations-----------------------\n";
    cout<<"C: For Linked-List Creation\n";
    cout<<"F: To Insert new Node at First\n";
    cout<<"L: To Insert new Node at Last\n";
    cout<<"d: To Displaying Linked-List\n";
    cout<<"S: TO Search a Number in Linked-List\n";
    cout<<"O: For Counting Occurrence of a Number in Linked-List\n";
    cout<<"M: To Find Maximum in Linked-List\n";
    cout<<"m: To Find Minimum in Linked-List\n";
    cout<<"a: To Find Average in Linked-List\n";
    cout<<"P: For Inserting new Node at specific position\n";
    cout<<"f: To Delete First Node\n";
    cout<<"l: To Delete Last Node\n";
    cout<<"p: For Deleting Node at Specific Position\n";
    cout<<"A: For Sorting Linked-List in Ascending Order\n";
    cout<<"D: For Sorting Linked-List in Descending Order\n";
    cout<<"i: To Calculate length of Linked-List\n";
    cout<<"-------------------------------------------------------------------\n";
    char opt;
    do{
    cout<<"ENTER YOUR CHOICE:";
    cin>>choice;
    switch(choice)                       //switch case
    {
        case 'C':{
            char opt;
            do{
            int number;
            cout<<"Plz Enter a Node:";
            cin>>number;
            createList(number);
            cout<<"DO YOU WANT TO ADD ANOTHER NODE?:";
            cin>>opt;
            }while(opt=='Y'||opt=='y');
            break;
        }
        case 'F':{
            char opt;
            do{
            int number;
            cout<<"Plz Enter a New Node:";
            cin>>number;
            insertAtFirst(number);
            cout<<"-------Node Added Successfully-----\n";
            cout<<"DO YOU WANT TO ADD ANOTHER NODE?:";
            cin>>opt;
            }while(opt=='Y'||opt=='y');
            break;
        }
        case 'L':{
            char opt;
            do{
            int number;
            cout<<"Plz Enter a New Node:";
            cin>>number;
            insertAtLast_Optimized(number);
            cout<<"-------Node Added Successfully-----\n";
            cout<<"DO YOU WANT TO ADD ANOTHER NODE?:";
            cin>>opt;
            }while(opt=='Y'||opt=='y');
            break;
        }
        case 'd':{
            cout<<"The Linked-List is:\n";
            display();
            break;
        }
        case 'S':{
            char opt;
            do{
            int number;
            cout<<"Enter a Number You want to Search in Linked-List:";
            cin>>number;
            search(number);
            cout<<"DO YOU WANT TO SEARCH ANOTHER NUMBER?:";
            cin>>opt;
            }while(opt=='Y'||opt=='y');
            break;
        }
        case 'O':{
            char opt;
            do{
            int number;
            cout<<"Enter a Number,You want to Find Occurrence in Linked-List:";
            cin>>number;
            countOccurrence(number);
            cout<<"DO YOU WANT TO FIND OCCURRENCE OF ANOTHER NUMBER?:";
            cin>>opt;
            }while(opt=='Y'||opt=='y');
            break;
        }
        case 'M':{
            cout<<"The Maximum in given Linked-List is:";
            findMax();
            break;
        }
        case 'm':{
            cout<<"The Minimum in given Linked-List is:";
            findMin();
            break;
        }
        case 'a':{
            cout<<"The Average of given Linked-List is:";
            findAverage();
            break;
        }
          case 'P':{
            char opt;
            do{
            int number;
            int pos;
            cout<<"Plz Enter a New Node:";
            cin>>number;
            cout<<"Plz Enter a New Node's Position/Index:";
            cin>>pos;
            insertAtPos(number,pos);
            cout<<"-------Node Added Successfully-----\n";
            cout<<"DO YOU WANT TO ADD ANOTHER NODE?:";
            cin>>opt;
            }while(opt=='Y'||opt=='y');
            break;
        }
        case 'f':{
            deleteFirst();
            cout<<"The First Node of Linked-List is Deleted Successfully!\n";
            break;
        }
        case 'l':{
            deleteLast();
            cout<<"The Last Node of Linked-List is Deleted Successfully!\n";
            break;
        }
        case 'p':{
            char opt;
            do{
            int pos;
            cout<<"Plz Enter the Node's Position/Index to be deleted:";
            cin>>pos;
            deleteAtPos(pos);
            cout<<"-------Node Deleted Successfully-----\n";
            cout<<"DO YOU WANT TO DELETE ANOTHER NODE?:";
            cin>>opt;
            }while(opt=='Y'||opt=='y');
            break;
        }
        case 'A':{
            cout<<"The Ascending Order of given Linked-List is:";
            sortListAscending();
            display();
            break;
        }
        case 'D':{
            cout<<"The Descending Order of given Linked-List is:";
            sortListDescending();
            display();
            break;
        }
        case 'i':{
            int length;
            cout<<"The Length of given Linked-List is:";
            length = calLength();
            cout<<length;
            break;
        }
        default:
        cout<<"Plz Enter Correct Choice!\n";
    }
    cout<<"\nDo You Want to Continue to Another Operation?:";
    cin>>opt;
    }while(opt=='Y'||opt=='y');
    deallocate();   //deallocating memory
    return 0;
}
void insertAtLast(int value)           //insertion function to insert new node at last position
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    if(head_first==nullptr)
    {
        head_first = newNode;
    }
    else
    {
        Node* temp = head_first;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }
}
void display()                  //function to display linkedlist
{
    if(!head_first)
    {
        cout<<"List is Empty!\n";
        return;
    }
    Node* temp = head_first;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"nullptr";
}
/*function for searching particular number in linkedlist
it will search the number at nearest possible index
if a number is present at more than 1 indexes,then it gives the nearest possible index of the number.*/
void search(int value)                    
{
    if(!head_first)
    {
        cout<<"List is Empty!\n";
        return;
    }
    Node* temp = head_first;
    int ind = 0;
    while(temp!= nullptr)
    {
        if(temp->data == value)
        {
           cout<<"\nThe Number\t"<<value<<"\tis Present at Address\t"<<&temp->data<<"\tAnd Index is\t"<<ind<<endl;
           return;
        }
        ind++;
        temp = temp->next;
    }
    cout<<"Number\t"<<value<<"\tNot Found!\n";
}
void countOccurrence(int value) //Function to find occurrence of a number,it gives all the posssible indexes of a Number.
{   
    if(!head_first)
    {
        cout<<"List is Empty!\n";
        return;
    }
    Node* temp = head_last;
    int count = 0;
    int ind = calLength()-1;
    while(temp!= nullptr)
    {
        if(temp->data == value)
        {
           cout<<"\nThe Number\t"<<value<<"\tis Present at Address\t"<<&temp->data<<"\tAnd Index is\t"<<ind<<endl;
           count++;
        }
        ind--;
        temp = temp->previous;
    }
    if(count>0)
    {
    cout<<"The Number\t"<<value<<"\tis Present\t"<<count<<"\ttimes in given List\n";
    }
    else
    {
        cout<<"Number\t"<<value<<"\tNot Found!\n";
    } 
}
void findMax()                        //function to find maximum
{
    if(head_first==nullptr)
    {
        cout<<"List is Empty!\n";
        return;
    }
    Node* temp = head_first;
    int max = temp->data;
    while(temp!=nullptr)
    {
       if(max<temp->data)
       {
        max = temp->data;
       }
       temp = temp->next;
    }
    cout<<"The Maximum Number in the given list is\t"<<max<<endl;
}
void findMin()                                               //function to find minimum
{
    if(head_first==nullptr)
    {
        cout<<"List is Empty!\n";
        return;
    }
    Node* temp = head_last;
    int min = temp->data;
    while(temp!=nullptr)
    {
       if(min>temp->data)
       {
        min = temp->data;
       }
       temp = temp->previous;
    }
    cout<<"The Minimum Number in the given list is\t"<<min<<endl;
}
void findAverage()             //Average function,to find Average
{
    if(!head_first)
    {
        cout<<"List is Empty!\n";
        return;
    }
   Node* temp = head_first;
   double sum = 0;
   int count = 0;
   double average = 0;
   while(temp!=nullptr)
   {
      sum += temp->data;
      temp = temp->next;
      count++;
   }
   average = sum/count;
   cout<<"Average of Given List is\t"<<average<<endl;
}
void deallocate()
{                                    //function to deallocate memory
    Node* current = head_first;
    Node* newNode;
    while(current!=nullptr)
    {
        newNode = current->next;
        delete current;         //free each node
        current = newNode;
    }
    head_first = nullptr;  //head is again set to nullptr
}
void insertAtFirst(int value)   //function for insertion of node at begining
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    if(!head_first)
    {
        head_first = newNode;
        return;
    }
    newNode->previous = head_first;
    head_first->next = newNode;
    head_first = newNode;
}
void insertAtPos(int  value,int ind)   //function for insertion of node at specific Position
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->next = nullptr;
    int length = calLength();
    if(ind<0 || ind>length)
    {
        cout<<"Invalid Index!\n";
    }
    else if (ind==0)
    {
        insertAtFirst(value);
    }
    else{
    Node* temp = head_first;
    int count = 0;
    while(count<ind -1 && temp->next!=nullptr)
    {
        temp = temp->next;
        count++;
    }
    if(temp->next==nullptr)
    {
        insertAtLast_Optimized(value);
    }
    else{
    newNode->next = temp->next;
    newNode->previous = temp;
    temp->next = newNode;
    }
 }
}
void createList(int value)   //function to create Linked List
{                            //uses insert at last function,so first node is head.
    insertAtLast_Optimized(value);
}
void deleteFirst()            //function to delete first node
{
    if(!head_first)
    {
        cout<<"List is Empty!\n";
    }
    else if(head_first->next == nullptr)
    {
        delete head_first;
        head_first = nullptr;
    }
    else{
    Node* temp = head_first;
    head_first = temp->next;
    delete temp;
    }
}
void deleteLast()          //function to delete Last node
{
    if(!head_first)
    {
        cout<<"List is Empty!\n";
    }
    else if(head_first->next == nullptr)
    {
        delete head_first;     //delete is a keyword to deallocate the node 
        head_first = nullptr;
    }
    else{
    Node* temp = head_last;
    head_last = temp->previous;
    delete temp;
}
}
void deleteAtPos(int ind)   //function to delete node at specific position
{
    int length = calLength();
    if(ind<0 || ind == length)
    {
        cout<<"INVALID  INDEX!\n";
    }
    else if(ind==0)
    {
        deleteFirst();
    }
    else{
    int count = 0;
    Node* temp = head_first;
    while(count<ind-1 && temp->next->next!=nullptr) 
    {
        temp= temp->next;
        count++;
    }
    if(temp->next->next==nullptr)
    {
        deleteLast();
    }
    else{
    Node* delNode = temp->next;   //saving node to be deleted
    temp->next = temp->next->next;
    delete delNode;     //deleting the node to be deleted
    }
}
}
int calLength()    //function to find the length of linkedlist
{
    int count = 0;
    Node* temp = head_first;
    while(temp!=nullptr)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void sortListAscending()               //function to sort linkedlist in Ascending order
{
    Node* temp1 = head_first;
    while(temp1!=nullptr)
    {
      Node* temp2 = temp1->next;
        while(temp2!=nullptr)
        {
           if(temp1->data>temp2->data)
           {
            int temp = temp1->data;
            temp1->data = temp2->data;
            temp2->data = temp;
           }
            temp2= temp2->next;
        }
        temp1 = temp1->next;
    }
}
void sortListDescending()    //function to sort linkedlist in descending order
{
    Node* temp1 = head_last;
    while(temp1!=nullptr)
    {
      Node* temp2 = temp1->previous;
        while(temp2!=nullptr)
        {
           if(temp1->data<temp2->data)
           {
            int temp = temp1->data;
            temp1->data = temp2->data;
            temp2->data = temp;
           }
            temp2= temp2->previous;
        }
        temp1 = temp1->previous;
    }
}
/* this function works as same as insertAtLast(int value); but it reduces the time complexity from O(n) to O(1)
  hence, it is optimized and faster.*/
void  insertAtLast_Optimized(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    if(!head_first)
    {
        head_first = head_last = newNode;
    }
    else{
        head_last->next = newNode;
        newNode->previous = head_last;
        head_last = newNode;
    }
}

