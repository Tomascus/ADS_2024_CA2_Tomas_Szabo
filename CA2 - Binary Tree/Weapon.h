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

// This method creates an index based on the header provided by the user 
void indexMap(TreeMap<string, vector<Weapon>>& index, const vector<Weapon>& weapons, const string& header) {
    
	// Iterating through the weapons array to create the index for the header 
    for (const auto& weapon : weapons) 
    {
        string key;

        if (header == "name")
        {
            key = weapon.name;
        }
        else if (header == "type")
        {
            key = weapon.type;
        }
        else if (header == "rarity")
        {
            key = weapon.rarity;
        }
        else if (header == "damage")
        {
            key = to_string(weapon.damage);
        }
        else if (header == "cost")
        {
            key = to_string(weapon.cost);
        }
        else 
        {
            cout << "Invalid header: " << header << endl;
            return;
        }

		// If the key is not in the map, it adds it
        if (!index.containsKey(key)) 
        {
            index.put(key, vector<Weapon>());
        }

        index[key].push_back(weapon); 
    }

	// Here it displays the keys in the map using keyset method from TreeMap
    BinaryTree<string> keys = index.keySet();
    keys.printInOrder(); 
    cout << endl;

	// Displays the number for each key in the map
    for (int i = 0; i < keys.count(); ++i) 
    {
        string key = keys.toArray()[i];
        cout << "Key: " << key << ", Count: " << index[key].size() << endl;
    }
}

// This method displays the subset of data based on the key provided by the user
void viewSubset(TreeMap<string, vector<Weapon>>& index, const string& key) {

	// If the key is in the map, it displays the data for that key
    if (index.containsKey(key)) 
    {
		const auto& items = index[key]; // Gets the vector of weapons for the key
        for (const auto& item : items) 
        {
            cout << "Name: " << item.name << ", Type: " << item.type
                << ", Damage: " << item.damage << ", Cost: " << item.cost
                << ", Rarity: " << item.rarity << endl;
        }
    }

    else 
    {
        cout << "No information found for key: " << key << endl;
    }
}