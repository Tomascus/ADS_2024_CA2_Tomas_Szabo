#include <iostream>
#include <fstream>
#include "TreeMap.h"

using namespace std;

// This method reads the file and and inserts the words into the map - For now Im creating the map by storing character and a binary tree of strings (CHANGE ?)
void readFile(const string& filename, TreeMap<char, BinaryTree<string>>& map) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening the file called: " << filename << endl;
        return;
    }

	// Reads the file word by word
    string word;
    while (file >> word) {
        
		// Here I convert each word to lowercase to make it easier to compare
        for (char& c : word) {
            c = tolower(c);
        }

		// Get the first letter to store as the key
        char firstLetter = word[0];

		// Inserts the word into the map if the key is not there yet
        if (!map.containsKey(firstLetter)) {
            map.put(firstLetter, BinaryTree<string>());
        }
        map[firstLetter].add(word); // Using BinaryTree's add method to insert word
    }

    file.close();
}

int main() {
    TreeMap<char, BinaryTree<string>> map;
    string filename = "words.txt";

    readFile(filename, map);

	// Display the list of letters in the file
    cout << "Letters in the file: ";
    BinaryTree<char> keys = map.keySet();
    keys.printInOrder();

	// Display all the words associated with a given letter
    char letter;
    cout << "Enter a letter to see words for it: ";
    cin >> letter;
    letter = tolower(letter);

	// Here I check if the letter is in the map and print the words associated with it
    if (map.containsKey(letter)) {
        cout << "Words starting with: '" << letter << "': ";
        map[letter].printInOrder(); 
    }
    else {
        cout << "There are no words starting with: '" << letter << "'" << endl;
    }

    return 0;
}