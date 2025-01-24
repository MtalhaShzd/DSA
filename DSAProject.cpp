#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// Patient Structure
struct Patient {
    int id;
    string name;
    string issue;
    string contactInfo;
    string gender;
    int age;
    Patient* next;
};

// Queue Class
class Queue {
private:
    Patient* front;
    Patient* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // enqueue function   .... to Add Patient
    void enqueue(int id, string name, string issue, string contactInfo, string gender, int age) {
        Patient* newPatient = new Patient{id, name, issue, contactInfo, gender, age, nullptr};
        if (rear == nullptr) {
            front = rear = newPatient;
            return;
        }
        rear->next = newPatient;
        rear = newPatient;
    }

    // dequeue function 
    Patient* dequeue() {
        if (front == nullptr) {
            return nullptr;
        }
        Patient* temp = front;
        front = temp->next;

        if (front == nullptr)
            rear = nullptr;

        return temp;
    }

    // to Delete a patient by ID
    void deletePatient(int id) {
        if (front == nullptr) {
            cout << "Queue is empty. No patient to delete.\n";
            return;
        }

        Patient* temp = front;
        Patient* prev = nullptr;

        // A conditional Check to see if the patient to delete is at the front
        if (temp != nullptr && temp->id == id) {
            front = temp->next;
            if (front == nullptr) rear = nullptr;
            delete temp;
            cout << "Patient with ID " << id << " deleted.\n";
            return;
        }

        // to Traverse the queue to find the patient
        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        // If patient not found
        if (temp == nullptr) {
            cout << "Patient with ID " << id << " not found.\n";
            return;
        }

        // to Remove the patient
        prev->next = temp->next;
        if (temp == rear) rear = prev;
        delete temp;
        cout << "Patient with ID " << id << " deleted.\n";
    }

    // function to Update patient's details by ID
    void updatePatient(int id, string name, string issue, string contactInfo, string gender, int age) {
        if (front == nullptr) {
            cout << "Queue is empty. No patient to update.\n";
            return;
        }

        Patient* temp = front;

        // to Traverse the queue to find the patient
        while (temp != nullptr) {
            if (temp->id == id) {
                temp->name = name;
                temp->issue = issue;
                temp->contactInfo = contactInfo;
                temp->gender = gender;
                temp->age = age;
                cout << "Patient with ID " << id << " updated successfully.\n";
                return;
            }
            temp = temp->next;
        }

        // If patient not found
        cout << "Patient with ID " << id << " not found.\n";
    }

    // to Display queue
    void display() {
        if (front == nullptr) {
            cout << "No patients in the queue.\n";
            return;
        }
        Patient* temp = front;
        cout << "Current Queue:\n";
        while (temp) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Issue: " << temp->issue
                 << ", Contact: " << temp->contactInfo
                 << ", Gender: " << temp->gender
                 << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }
};

// History Class using Linked List
class History {
private:
    Patient* head;

public:
    History() {
        head = nullptr;
    }

    // to Add patient to history
    void addToHistory(Patient* patient) {
        Patient* newPatient = new Patient{patient->id, patient->name, patient->issue, patient->contactInfo, patient->gender, patient->age, nullptr};
        if (head == nullptr) {
            head = newPatient;
            return;
        }
        Patient* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }

    // to Display history
    void displayHistory() {
        if (head == nullptr) {
            cout << "No history available.\n";
            return;
        }
        Patient* temp = head;
        cout << "Patient History:\n";
        while (temp) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Issue: " << temp->issue
                 << ", Contact: " << temp->contactInfo
                 << ", Gender: " << temp->gender
                 << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }

    // function to Save history to file
    void saveToFile() {
        ofstream outFile("E:\\patient_history.txt", ios::trunc);
        if (!outFile) {
            cout << "Error opening file for writing.\n";
            return;
        }
        Patient* temp = head;
        while (temp) {
            outFile << temp->id << "," << temp->name << "," << temp->issue << "," << temp->contactInfo << "," << temp->gender << "," << temp->age << endl;
            temp = temp->next;
        }
        outFile.close();
    }

    // Load history from file
    void loadFromFile() {
        ifstream inFile("E:\\patient_history.txt");
        if (!inFile) {
            return; 
        }
        string line;
        while (getline(inFile, line)) {
            int id, age;
            string name, issue, contactInfo, gender;
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            size_t pos4 = line.find(',', pos3 + 1);
            size_t pos5 = line.rfind(',');

            id = stoi(line.substr(0, pos1));
            name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            issue = line.substr(pos2 + 1, pos3 - pos2 - 1);
            contactInfo = line.substr(pos3 + 1, pos4 - pos3 - 1);
            gender = line.substr(pos4 + 1, pos5 - pos4 - 1);
            age = stoi(line.substr(pos5 + 1));

            Patient* newPatient = new Patient{id, name, issue, contactInfo, gender, age, nullptr};
            if (head == nullptr) {
                head = newPatient;
            } else {
                Patient* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newPatient;
            }
        }
        inFile.close();
    }
};
//This PatientStack class is to show the recent history of patients, not complete history, only recent history in stack form.
// Stack Class for Patient History
class PatientStack {
private:
    Patient* top;

public:
    PatientStack() {
        top = nullptr;
    }

    // Push patient onto the stack
    void push(Patient* patient) {
        Patient* newPatient = new Patient{patient->id, patient->name, patient->issue, patient->contactInfo, patient->gender, patient->age, top};
        top = newPatient;
    }

    // Pop patient from the stack
    Patient* pop() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return nullptr;
        }
        Patient* temp = top;
        top = top->next;
        return temp;
    }

    // Display stack
    void displayStack() {
        if (top == nullptr) {
            cout << "No recent history available.\n";
            return;
        }
        Patient* temp = top;
        cout << "Recent Patient History (Stack):\n";
        while (temp) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Issue: " << temp->issue
                 << ", Contact: " << temp->contactInfo
                 << ", Gender: " << temp->gender
                 << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }
};
// Main Function
int main() {
    Queue queue;
    History patientHistory;
    PatientStack historyStack;

    // Load history from file
    patientHistory.loadFromFile();
    int choice;
    do {
        cout << "\n****************Hospital Patient Management System(Using Queue,Stack,LinkedList)****************\n";
        cout << "1. Add Patient\n";
        cout << "2. Serve Patient\n";
        cout << "3. View Current Queue\n";
        cout << "4. Delete Patient from Queue\n";
        cout << "5. Update Patient in Queue\n";
        cout << "6. View Patient History (in Queue form/FIFO)\n";
        cout << "7. View Recent History (in Stack form/LIFO)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, age;
            string name, issue, contactInfo, gender;
            cout << "Enter Patient ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Patient Name: ";
            getline(cin, name);
            cout << "Enter Patient Issue: ";
            getline(cin, issue);
            cout << "Enter Contact Info: ";
            getline(cin, contactInfo);
            cout << "Enter Patient Gender: ";
            getline(cin, gender);
            cout << "Enter Patient Age: ";
            cin >> age;

            queue.enqueue(id, name, issue, contactInfo, gender, age);
            cout << "Patient added to the queue.\n";
            break;
        }
        case 2: {
            Patient* servedPatient = queue.dequeue();
            if (servedPatient) {
                cout << "Serving Patient: \n";
                cout << "ID: " << servedPatient->id
                     << ", Name: " << servedPatient->name
                     << ", Issue: " << servedPatient->issue
                     << ", Contact: " << servedPatient->contactInfo
                     << ", Gender: " << servedPatient->gender
                     << ", Age: " << servedPatient->age << endl;

                // Add served patient to history
                patientHistory.addToHistory(servedPatient);
                historyStack.push(servedPatient);
                delete servedPatient;
            } else {
                cout << "No patients in the queue.\n";
            }
            break;
        }
        case 3: {
            queue.display();
            break;
        }
        case 4: {
            int id;
            cout << "Enter Patient ID to delete: ";
            cin >> id;
            queue.deletePatient(id);
            break;
        }
        case 5: {
            int id, age;
            string name, issue, contactInfo, gender;
            cout << "Enter Patient ID to update: ";
            cin >> id;
            cin.ignore();
            cout << "Enter New Patient Name: ";
            getline(cin, name);
            cout << "Enter New Patient Issue: ";
            getline(cin, issue);
            cout << "Enter New Contact Info: ";
            getline(cin, contactInfo);
            cout << "Enter New Patient Gender: ";
            getline(cin, gender);
            cout << "Enter New Patient Age: ";
            cin >> age;

            queue.updatePatient(id, name, issue, contactInfo, gender, age);
            break;
        }
        case 6: {
            patientHistory.displayHistory();
            break;
        }
        case 7: {
            historyStack.displayStack();
            break;
        }
        case 8: {
            cout << "Exiting the system...GoodBye!\n";
            // Save history to file before exiting
            patientHistory.saveToFile();
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

