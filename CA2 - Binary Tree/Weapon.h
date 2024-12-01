#include <iostream>
#include <fstream> 
#include <sstream> // for stringstream
#include <vector>

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

// This method creates an index based on the type defined by user input - I will change this to create a TreeMap instead
void index(const vector<Weapon>& weapons, const string& header) 
{
    map<string, int> index;

	// Here it iterates through the weapons array and creates an index based on the type chosen by user
    for (const auto& weapon : weapons) 
    {
        if (header == "name") {
            index[weapon.name]++;
        }
        else if (header == "type")
        {
            index[weapon.type]++;
        }
        else if (header == "rarity")
        {
            index[weapon.rarity]++;
        }
        else if (header == "damage") {
            index[to_string(weapon.damage)]++;
        }
        else if (header == "cost") {
            index[to_string(weapon.cost)]++;
        }
        else {
            cout << "Invalid header: " << header << endl;
            return;
        }

    }

	// This displays the index by iterating through the map - again, this is only for testing now, will change it to display the TreeMap
    cout << "Index of header - " << header << endl;
    for (const auto& pair : index) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }
}
