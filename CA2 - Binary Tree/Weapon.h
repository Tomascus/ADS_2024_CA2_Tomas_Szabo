#include <iostream>
#include <fstream> 
#include <sstream> // for stringstream
#include <vector>
#include <string>

using namespace std;

// I create a struct to hold all the data from the csv file
struct Weapon {
    string name;
    string type;
    int damage;
    int cost;
    string rarity;
};

// This method reads the csv file and returns a vector of weapons - I will change this to return a TreeMap 
vector<Weapon> readCSV(const string& filename)
{
    ifstream file(filename);
    vector<Weapon> weapons;

    if (!file) 
    {
        cout << "Error with opening the file" << endl;
        return weapons; // returns an empty array 
    }

	// Read the first line of the file - skip it as it only has the headers for types of data
    string line; 
    getline(file, line);

	// Here it reads the file line by line using stringsteam to separate data by ","
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
		string type;
		string rarity;
		int damage;
		int cost;

		// Separate the data by "," - ordering it as it is in the csv file
        getline(ss, name, ',');
        getline(ss, type, ',');
        ss >> damage; ss.ignore(); 
        ss >> cost; ss.ignore(); 
        getline(ss, rarity);

        weapons.push_back({name, type, damage, cost, rarity});
    }

    file.close(); 
    return weapons;
}
