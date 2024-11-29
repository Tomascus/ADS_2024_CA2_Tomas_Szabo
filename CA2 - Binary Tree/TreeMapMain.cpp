#include <iostream>
#include <string>
#include "TreeMap.h"

using namespace std;

int main() {
    
    TreeMap<char, string> map;

    // Add cars and their first letters to the map
    map.put('A', "Audi");
    map.put('B', "BMW");
    map.put('C', "Chevrolet");
    map.put('F', "Ford");

	// Display the size of the map
    cout << "Size of map: " << map.size() << endl;

    // Check if specific letter is in the map
    if (map.containsKey('A')) {
        cout << "It contains key 'A'" << endl;
    } else {
        cout << "Does not contain key 'A'" << endl;
    }

    if (map.containsKey('T')) {
        cout << "It contains key 'T'" << endl;
    } else {
        cout << "Does not contain key 'T'" << endl;
    }

	// Get values using get() and operator[] - operator will add a new key if it doesnt exist
    cout << "Value for 'B': " << map.get('B') << endl;
    cout << "Value for 'F' with operator[]: " << map['F'] << endl;

	// Try to get a value for a key that doesnt exist - should return an empty string 
    cout << "Value for 'T' with get method: " << map.get('T') << endl;
    cout << "Value for 'T' with operator[]: " << map['T'] << endl;  

	// Check the size of the map after using operator[] on a key that doesnt exist
    cout << "Size of map after operator[] method: " << map.size() << endl;

    // Remove a key from the map
    if (map.removeKey('C')) {
        cout << "Removed key 'C'" << endl;
    } else {
        cout << "Did not remove key 'C'" << endl;
    }
    cout << "Size of map after removing: " << map.size() << endl;

	// Get the key set and print it
    BinaryTree<char> keys = map.keySet();
    cout << "Keys in the map: ";
    keys.printInOrder(); 

    // Clear the map and check the size again
    map.clear();
    cout << "Size of map after clear(): " << map.size() << endl;

    return 0;
}
