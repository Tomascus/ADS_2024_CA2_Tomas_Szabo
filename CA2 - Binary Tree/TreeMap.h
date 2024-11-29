#include <map>
#include <utility> 
#include "BinaryTree.h"
#include "MapValues.h"

using namespace std;

// For now, the tests and treemap contains car names and first letters as key,value for the map - will change for part 2 maybe, also changing it to read from file

template <class K, class V>
class TreeMap {
    BinaryTree<MapValues<K, V>> map; // Im using a binary tree to store key value pairs from struct for the map

	// This method finds a node in the map - used in get, remove and other methods to find the node instead of calling it in every method
    BSTNode<MapValues<K, V>>* find(K key) {
		BSTNode<MapValues<K, V>>* current = map.root; // Start from the root of the map
        
		// This part loops through the map to find the key, if the key is equal to the current key, return it,
		// otherwise we go left if the key is smaller than the current key, or right if the key is bigger than current key
        while (current != nullptr) {
            if (current->getItem().key == key) {
                return current;
            }
            else if (current->getItem().key > key) {
                current = current->getLeft();
            }
            else {
                current = current->getRight();
            }
        }
		return nullptr; // If key was not found return null
    }

public:
    void clear();
    bool containsKey(K key);
    V get(K key);
	BinaryTree<K> keySet();
    void put(K key, V value);
    int size();
    bool removeKey(K key);
    V& operator[](K key);
	void printMap();
	void printMapHelper(BSTNode<MapValues<K, V>>* node);
};


// Uses clear method from binary tree to clear the map
template <class K, class V>
void TreeMap<K, V>::clear() 
{
    map.clear();
}

// This method checks if the key exists in the map
template <class K, class V>
bool TreeMap<K, V>::containsKey(K key) 
{
    return find(key) != nullptr; // Just calling the find method and checking if the key exists and is not null
}

// This method returns the value of the key in the map
template <class K, class V>
V TreeMap<K, V>::get(K key)
{
	// Start by finding the node with the key and return the value of the node if present in map, otherwise return a default value
    BSTNode<MapValues<K, V>>* node = find(key);
    if (node == nullptr) {
		 // Instead of using error when nullptr, I return a default value (null) which makes it cleaner and esier to orient 
        return V();
    }
    return node->getItem().value;
}

template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet() {
	
    BinaryTree<K> keySetTree; // I create a temporary binary tree to store the keys

	// Gets all the keys sorted by using array of each node in the map
    int nodeCount = map.count(); 
    MapValues<K, V>* nodeArray = map.toArray();

	// Goes through each node and adds the key to the keysTree
    for (int i = 0; i < nodeCount; ++i) {
        keySetTree.add(nodeArray[i].key);
    }

    delete[] nodeArray; // Free the memory
    return keySetTree;
}

// This method adds a new pair to the map
template <class K, class V>
void TreeMap<K, V>::put(K key, V value) 
{
    BSTNode<MapValues<K, V>>* node = find(key);  // Find the node based on the key inputted
    if (node != nullptr) {
        node->setItem(MapValues<K, V>(key, value)); // Here I replace the items in the node with the new map pair
    }
    else {
        MapValues<K, V> newItem(key, value); // If the key doesnt exist, add it to the map
        map.add(newItem);
    }
}

// This method returns the number of pairs in the map
template <class K, class V>
int TreeMap<K, V>::size() 
{
    return map.count();
}

// This method removes a key from the map
template <class K, class V>
bool TreeMap<K, V>::removeKey(K key) 
{
    BSTNode<MapValues<K, V>>* node = find(key); // same as before, instead of doing it separately for each method...
    if (node == nullptr) {
        return false; // returns false if the node wasnt found
    }
    MapValues<K, V> item = node->getItem();
	return map.remove(item); // Get the item from the node and remove it from the map
}

// This method returns the value of the key in the map - overloaded operator
template <class K, class V>
V& TreeMap<K, V>::operator[](K key) 
{
	// Same as get method, but instead of returning a default value, I add a new pair with default value if not found
    BSTNode<MapValues<K, V>>* node = find(key);
    if (node == nullptr) {
        put(key, V());
		node = find(key); // Find it again and return the value
    }
    return node->getItem().value;
}
