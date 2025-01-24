#include <iostream>
using namespace std;

#define QueueSize 4
int deque[QueueSize];
int rear = -1;
int front = -1;
int size = 0; // Keeps track of the current size of the deque

bool isFull()
{
    return (size == QueueSize);
}

bool isEmpty()
{
    return (size == 0);
}

int getQueueSize()
{
    return size; // Return the current number of elements in the deque
}

int getFront()
{
    if (!isEmpty())
    {
        return deque[front];
    }
    else
    {
        return -1; // Special value indicating deque is empty
    }
}

int getRear()
{
    if (!isEmpty())
    {
        return deque[rear];
    }
    else
    {
        return -1; // Special value indicating deque is empty
    }
}

int insertAtFront(int data)
{
    if (isFull())
    {
        return 0; // Deque is full
    }
    else
    {
        if (front == -1 && rear == -1) // Deque is empty
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0) // Wrap around
        {
            front = QueueSize - 1;
        }
        else
        {
            front--; // Move front to the previous position
        }
        deque[front] = data;
        size++; // Increment size after adding element
        return 1; // Success
    }
}

int insertAtRear(int data)
{
    if (isFull())
    {
        return 0; // Deque is full
    }
    else
    {
        if (front == -1 && rear == -1) // Deque is empty
        {
            front = 0;
            rear = 0;
        }
        else if (rear == QueueSize - 1) // Wrap around
        {
            rear = 0;
        }
        else
        {
            rear++; // Move rear to the next position
        }
        deque[rear] = data;
        size++; // Increment size after adding element
        return 1;
    }
}

int dequeueFront()
{
    if (isEmpty())
    {
        return -1; // Deque is empty
    }
    else
    {
        int data = deque[front];
        if (front == rear) // Only one element
        {
            front = rear = -1;
        }
        else if (front == QueueSize - 1) // Wrap around
        {
            front = 0;
        }
        else
        {
            front++; // Move front to the next position
        }
        size--;
        return data;
    }
}

int dequeueRear()
{
    if (isEmpty())
    {
        return -1; // Deque is empty
    }
    else
    {
        int data = deque[rear];
        if (front == rear) // Only one element
        {
            front = rear = -1;
        }
        else if (rear == 0) // Wrap around
        {
            rear = QueueSize - 1;
        }
        else
        {
            rear--; // Move rear to the previous position
        }
        size--;
        return data;
    }
}

void Display()
{
    if (isEmpty())
    {
        cout << "Deque is Empty!" << endl;
    }
    else
    {
        cout << "Deque elements: ";
        int i = front;
        while (true)
        {
            cout << deque[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % QueueSize;
        }
        cout << endl;
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
        cout << "Enter 1 to insert an element at the front of the deque\n";
        cout << "Enter 2 to insert an element at the rear of the deque\n";
        cout << "Enter 3 to delete an element from the front of the deque\n";
        cout << "Enter 4 to delete an element from the rear of the deque\n";
        cout << "Enter 5 to display the front element of the deque\n";
        cout << "Enter 6 to check whether the deque is empty or not\n";
        cout << "Enter 7 to check whether the deque is full or not\n";
        cout << "Enter 8 to display all elements of the deque\n";
        cout << "Enter 9 to display the front element of the deque\n";
        cout << "-----------------------------------------------------\n";
        cout << "Now enter your option [1/2/3/4/5/6/7/8]: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Please enter an element to insert at the front of the deque: ";
            cin >> value;
            val = insertAtFront(value);
            if (val == 1)
            {
                cout << "Added Successfully at the front!" << endl;
            }
            else
            {
                cout << "Cannot Add, deque is Full!" << endl;
            }
            break;

        case 2:
            cout << "Please enter an element to insert at the rear of the deque: ";
            cin >> value;
            val = insertAtRear(value);
            if (val == 1)
            {
                cout << "Added Successfully at the rear!" << endl;
            }
            else
            {
                cout << "Cannot Add, deque is Full!" << endl;
            }
            break;

        case 3:
            val = dequeueFront();
            if (val == -1)
            {
                cout << "Deque is Empty!" << endl;
            }
            else
            {
                cout << val << " Dequeued from front Successfully!" << endl;
            }
            break;

        case 4:
            val = dequeueRear();
            if (val == -1)
            {
                cout << "Deque is Empty!" << endl;
            }
            else
            {
                cout << val << " Dequeued from rear Successfully!" << endl;
            }
            break;

        case 5:
            if (!isEmpty())
                cout << "The front element is: " << getFront() << endl;
            else
                cout << "Deque is Empty!" << endl;
            break;

        case 6:
            if (isEmpty())
                cout << "The deque is empty" << endl;
            else
                cout << "There are some data elements in the deque" << endl;
            break;

        case 7:
            if (isFull())
                cout << "The deque is full" << endl;
            else
                cout << "The deque has some room(s) for new data elements" << endl;
            break;

        case 8:
            Display();
            break;
        case 9:
            if (!isEmpty())
                cout << "The Rear element is: " << getRear() << endl;
            else
                cout << "Deque is Empty!" << endl;
            break;
        default:
            cout << "Invalid option, Please enter a correct one" << endl;
        }

        cout << "\nDo you want to continue [Y/N]: ";
        cin >> ch;

    } while ((ch == 'Y' || ch == 'y'));

    return 0;
}
