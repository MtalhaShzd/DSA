#include <iostream>
using namespace std;

#define QueueSize 4
int deque[QueueSize];
int rear = -1;
int front = -1;

bool isFull() {
    return (rear - front + 1) == QueueSize;
}

bool isEmpty() {
    return (front == -1 && rear == -1);
}

int insertAtFront(int data) {
    if (isFull()) {
        return 0; // Deque is full
    }
    if (isEmpty()) { // First insertion
        front = rear = 0;
    } else if (front == 0) { // Shift elements to create space
        for (int i = rear; i >= front; i--) {
            deque[i + 1] = deque[i];
        }
        rear++;
    } else {
        front--;
    }
    deque[front] = data;
    return 1;
}

int insertAtRear(int data) {
    if (isFull()) {
        return 0; // Deque is full
    }
    if (isEmpty()) { // First insertion
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
    return 1;
}

int dequeueFront() {
    if (isEmpty()) {
        return -1; // Deque is empty
    }
    int data = deque[front];
    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}

int dequeueRear() {
    if (isEmpty()) {
        return -1; // Deque is empty
    }
    int data = deque[rear];
    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        rear--;
    }
    return data;
}

void Display() {
    if (isEmpty()) {
        cout << "Deque is Empty!\n";
        return;
    }
    cout << "Deque elements: ";
    for (int i = front; i <= rear; i++) {
        cout << deque[i] << " ";
    }
    cout << endl;
}

int main() {
    char ch = 'y';
    int value, opt, val;

    do {
        system("cls");
        cout << "-----------------------------------------------------\n";
        cout << "Enter 1 to insert an element at the front of the deque\n";
        cout << "Enter 2 to insert an element at the rear of the deque\n";
        cout << "Enter 3 to delete an element from the front of the deque\n";
        cout << "Enter 4 to delete an element from the rear of the deque\n";
        cout << "Enter 5 to display all elements of the deque\n";
        cout << "-----------------------------------------------------\n";
        cout << "Now enter your option [1/2/3/4/5]: ";
        cin >> opt;

        switch (opt) {
        case 1:
            cout << "Please enter an element to insert at the front of the deque: ";
            cin >> value;
            val = insertAtFront(value);
            if (val == 1) {
                cout << "Added Successfully at the front!" << endl;
            } else {
                cout << "Cannot Add, deque is Full or Front is blocked!" << endl;
            }
            break;

        case 2:
            cout << "Please enter an element to insert at the rear of the deque: ";
            cin >> value;
            val = insertAtRear(value);
            if (val == 1) {
                cout << "Added Successfully at the rear!" << endl;
            } else {
                cout << "Cannot Add, deque is Full!" << endl;
            }
            break;

        case 3:
            val = dequeueFront();
            if (val == -1) {
                cout << "Deque is Empty!" << endl;
            } else {
                cout << val << " Dequeued from front Successfully!" << endl;
            }
            break;

        case 4:
            val = dequeueRear();
            if (val == -1) {
                cout << "Deque is Empty!" << endl;
            } else {
                cout << val << " Dequeued from rear Successfully!" << endl;
            }
            break;

        case 5:
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
