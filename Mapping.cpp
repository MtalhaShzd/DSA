#include <iostream>
#include <map>
using namespace std;

int main() {
    // Create a map that stores <key, value> pairs
    map<int, string> myMap;

    // Inserting elements in the map using insert() and the [] operator
    myMap.insert({1, "Apple"});
    myMap.insert({2, "Banana"});
    myMap.insert({3, "Cherry"});
    myMap[4] = "Date";  // Using [] to insert or update
    myMap[5] = "Elderberry"; 

    // Display all elements in the map
    cout << "Map elements (key-value pairs):" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // Access an element by key using the [] operator
    cout << "\nAccessing an element by key (key 3): " << myMap[3] << endl;

    // Check if a key exists using find()
    int keyToFind = 2;
    auto search = myMap.find(keyToFind);
    if (search != myMap.end()) {
        cout << "\nFound key " << keyToFind << ": " << search->second << endl;
    } else {
        cout << "\nKey " << keyToFind << " not found in the map." << endl;
    }

    // Erase an element by key
    myMap.erase(4);  // Erase element with key 4
    cout << "\nAfter erasing key 4, map elements are:" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // Remove elements using an iterator
    auto it = myMap.begin();
    myMap.erase(it);  // Remove the first element
    cout << "\nAfter erasing the first element, map elements are:" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // Check the size of the map
    cout << "\nSize of the map: " << myMap.size() << endl;

    // Clearing all elements from the map
    myMap.clear();
    cout << "\nAfter clearing the map, size: " << myMap.size() << endl;

    return 0;
}
