#include <iostream>
using namespace std;

#define QueueSize 4
int Queue[QueueSize];
int rear = -1;
int front = -1;
int totalElements = 0;

bool isFull()
{
    return (totalElements == QueueSize);
}

bool isEmpty()
{
    return ( totalElements == 0);
}

int size()
{
    return QueueSize;
}

int peek()
{
    if (!isEmpty())
    {
        return Queue[front];
    }
    else
    {
        return -1; // Special value indicating queue is empty
    }
}

int enqueue(int data)
{
    if (!isFull())
    {
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % QueueSize;
        Queue[rear] = data;
        totalElements++;
        return 1; // Success
    }
    else
    {
        return 0; // Failure
    }
}

int dequeue()
{
    if (isEmpty())
    {
        return -1; // Special value indicating queue is empty
    }
    else
    {
        int data = Queue[front];
        totalElements--;
        if(front == rear )
        {
            front = -1;
            rear = -1;
        }
        else{
        front = (front + 1) % QueueSize;
        }
        return data;
    }
}

void Display()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << "Queue elements: ";
        int i = front;
        while(true)
        {
            cout<<Queue[i]<<" ";
            if(i == rear)
            break;
            i = (i + 1)% QueueSize;
        }
       cout<<endl;
    }
}

int main()
{
    char ch = 'y';
    int value, opt, val;

    do
    {
        system("cls");
        cout << "-----------------------------------------------------\n";
        cout << "Enter 1 to insert an element in the Queue\n";
        cout << "Enter 2 to delete an element from the Queue\n";
        cout << "Enter 3 to display peek element of the Queue\n";
        cout << "Enter 4 to check whether the Queue is empty or not\n";
        cout << "Enter 5 to check whether the Queue is full or not\n";
        cout << "Enter 6 to display all elements of the Queue\n";
        cout << "-----------------------------------------------------\n";
        cout << "Now enter your option [1/2/3/4/5/6]: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Please enter an element to insert in the Queue: ";
            cin >> value;
            val = enqueue(value);
            if (val == 1)
            {
                cout << "Added Successfully!" << endl;
            }
            else
            {
                cout << "Cannot Add, Queue is Full!" << endl;
            }
            break;

        case 2:
            val = dequeue();
            if (val == -1)
            {
                cout << "Queue is Empty!" << endl;
            }
            else
            {
                cout << val << " Dequeued Successfully!" << endl;
            }
            break;

        case 3:
            if (!isEmpty())
                cout << "The peek is: " << peek() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            if (isEmpty())
                cout << "The Queue is empty" << endl;
            else
                cout << "There are some data elements in the Queue" << endl;
            break;

        case 5:
            if (isFull())
                cout << "The Queue is full" << endl;
            else
                cout << "The Queue has some room(s) for new data elements" << endl;
            break;

        case 6:
            Display();
            break;

        default:
            cout << "Invalid option, Please enter a correct one" << endl;
        }

        cout << "\nDo you want to continue [Y/N]: ";
        cin >> ch;

    } while ((ch == 'Y' || ch == 'y'));

    return 0;
}
