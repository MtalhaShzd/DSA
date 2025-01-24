#include <iostream>
#include <climits>
using namespace std;

// Define the maximum size of the priority queue
const int MAX_SIZE = 100;

// Arrays to store the values and their priorities
int values[MAX_SIZE];
int priorities[MAX_SIZE];

// Variable to keep track of the current size of the priority queue
int size = 0;

// Function to check if the priority queue is empty
bool isEmpty() {
    return size == 0;
}

// Function to check if the priority queue is full
bool isFull() {
    return size == MAX_SIZE;
}

// Function to insert an element into the priority queue
void push(int value, int priority) {
    if (isFull()) {
        cout << "Error: Priority queue is full. Cannot insert.\n";
        return;
    }

    // Add the value and its priority at the end of the arrays
    values[size] = value;
    priorities[size] = priority;

    // Increment the size of the priority queue
    size++;
}

// Function to find the index of the element with the highest priority
int findHighestPriorityIndex() {
    if (isEmpty()) {
        return -1; // Return -1 if the queue is empty
    }

    int highestPriorityIndex = 0;

    // Iterate through the priorities to find the highest priority
    for (int i = 1; i < size; i++) {
        // Higher priority means a larger value
        if (priorities[i] > priorities[highestPriorityIndex]) {
            highestPriorityIndex = i;
        }
    }

    return highestPriorityIndex;
}

// Function to get the value of the highest priority element
int top() {
    if (isEmpty()) {
        cout << "Error: Priority queue is empty. No elements to retrieve.\n";
        return INT_MIN; // Sentinel value indicating an error
    }

    // Find the highest priority element
    int highestPriorityIndex = findHighestPriorityIndex();
    return values[highestPriorityIndex];
}

// Function to remove the element with the highest priority
void pop() {
    if (isEmpty()) {
        cout << "Error: Priority queue is empty. No elements to remove.\n";
        return;
    }

    // Find the index of the highest priority element
    int highestPriorityIndex = findHighestPriorityIndex();

    // Shift all elements after the highest priority element to the left
    for (int i = highestPriorityIndex; i < size - 1; i++) {
        values[i] = values[i + 1];
        priorities[i] = priorities[i + 1];
    }

    // Decrease the size of the priority queue
    size--;
}

// Function to display all elements and their priorities in the queue
void display() {
    if (isEmpty()) {
        cout << "The priority queue is empty.\n";
        return;
    }

    cout << "Priority Queue Elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Value: " << values[i] << ", Priority: " << priorities[i] << endl;
    }
}

// Main function to demonstrate the working of the priority queue
int main() {
    // Insert elements with their priorities
    push(10, 2);  // Element: 10, Priority: 2
    push(20, 5);  // Element: 20, Priority: 5
    push(15, 1);  // Element: 15, Priority: 1
    push(25, 4);  // Element: 25, Priority: 4

    // Display the elements in the priority queue
    cout << "\nInitial Priority Queue:\n";
    display();

    // Get the top (highest priority) element
    cout << "\nTop element: " << top() << endl; // Should be 20

    // Remove the top (highest priority) element
    pop();
    cout << "\nPriority Queue after removing the top element:\n";
    display();

    // Add a new element
    push(30, 6); // Element: 30, Priority: 6
    cout << "\nPriority Queue after adding 30 with priority 6:\n";
    display();

    // Get the top element again
    cout << "\nNew Top element: " << top() << endl; // Should be 30

    return 0;
}
