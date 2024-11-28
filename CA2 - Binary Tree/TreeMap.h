#include <map>
#include <utility> 
#include "BinaryTree.h"

using namespace std;

// For now, the tests and treemap contains car names and first letters as key,value for the map - will change for part 2 maybe, also changing it to read from file

template <class K, class V>
class TreeMap {
	BinaryTree<pair<K, V>> map; // Im using a binary tree to store key value pairs for the map

	// This method finds a node in the map - used in get, remove and other methods to find the node instead of calling it in every method
    BSTNode<pair<K, V>>* find(K key) {
		BSTNode<pair<K, V>>* current = map.root; // Start from the root of the map
        
		// This part loops through the map to find the key, if the key is equal to the current key, return it,
		// otherwise we go left if the key is smaller than the current key, or right if the key is bigger than current key
        while (current != nullptr) {
            if (current->getItem().first == key) {
                return current;
            }
            else if (current->getItem().first > key) {
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
    V& get(K key);
	BinaryTree<K> keySet();
    void put(K key, V value);
    int size();
    bool removeKey(K key);
    V& operator[](K key);
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
V& TreeMap<K, V>::get(K key)
{
    //return V();
}

// This returns a binary tree of keys in the map
template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
    return BinaryTree<K>();
}

// This method adds a new pair to the map
template <class K, class V>
void TreeMap<K, V>::put(K key, V value) 
{
    BSTNode<pair<K, V>>* node = find(key);  // Find the node based on the key inputted
    if (node != nullptr) {
		node->setItem(make_pair(key, value)); // Here I replace the items in the node with the new pair, MIGHT CHANGE ???
    }
    else {
		map.add(make_pair(key, value)); // If the key doesnt exist, add it to the map
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
    BSTNode<pair<K, V>>* node = find(key); // same as before, instead of doing it separately for each method...
    if (node == nullptr) {
        return false; // returns false if the node wasnt found
    }
    pair<K, V> item = node->getItem();
	return map.remove(item); // Get the item from the node and remove it from the map
}

// This method returns the value of the key in the map - overloaded operator
template <class K, class V>
V& TreeMap<K, V>::operator[](K key) 
{
    return V();
}
