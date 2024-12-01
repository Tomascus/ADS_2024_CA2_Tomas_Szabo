#include <iostream>
#include <fstream>
#include "TreeMap.h"
#include "Weapon.h"

using namespace std;


void runApp1();
void runApp2();

// Main menu to run the applications 
int main() {
    int choice = 0;

    do {
        cout << "\n --- Main Menu --- \n";
        cout << "1. App 1: Text file reading and organizing words by their first letter \n";
        cout << "2. App 2: View and search CSV file data \n";
        cout << "0. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            runApp1();
            break;
        case 2:
            runApp2();
            break;
        case 0:
            cout << "Exiting the program \n";
            break;
        default:
            cout << "Invalid choice... Please enter 1, 2 or 0 to exit \n";
            break;
        }
    } while (choice != 0);

    return 0;
}

void runApp1() 
{
    cout << "\n --- Text file reading and organizing words by their first letter --- \n";

    TreeMap<char, BinaryTree<string>> map;
    string filename = "words.txt";
    readFile(filename, map);

    // Display the list of letters in the file
    cout << "Letters in the file: ";
    BinaryTree<char> keys = map.keySet();
    keys.printInOrder();

    // Display all the words associated with a given letter
    char letter;
    cout << "\n Enter a letter to see words for it: ";
    cin >> letter;
    letter = tolower(letter);

    // Here I check if the letter is in the map and print the words associated with it
    if (map.containsKey(letter)) 
    {
        cout << "Words starting with: '" << letter << "': ";
        map[letter].printInOrder();
    }
    else 
    {
        cout << "There are no words starting with: '" << letter << "' \n";
    }
}

// Application 2: View and search CSV data
void runApp2() 
{
    cout << "\n --- Application 2: View and Search CSV file data --- \n";

    string filename = "weapons.csv";
    vector<Weapon> weapons = readCSV(filename); // Read data into a vector of Weapon objects

    /*// Displays the data read from the file by irerating through the array of weapons - can be disabled
    for (const auto& weapon : weapons) {
        cout << "Name: " << weapon.name << ", Type: " << weapon.type <<
            ", Damage: " << weapon.damage << ", Cost: " << weapon.cost
            << ", Rarity: " << weapon.rarity << endl;
    }*/

    // Creates TreeMap to store the information for indexing
    TreeMap<string, vector<Weapon>> index;

    // Create an index based on user input
    string header;
    cout << "Enter header to index (name, type, rarity, damage, cost): ";
    cin >> header;

    indexMap(index, weapons, header);

    // View a subset of the data based on user input
    string key;
    cout << "Enter a key to view data subset of (specific name, type, rarity, damage, cost): ";
    cin >> key;

    // Display the subset of data
    viewSubset(index, key);
}
