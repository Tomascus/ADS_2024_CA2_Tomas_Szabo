#include <map>
#include <utility> 
#include "BinaryTree.h"

using namespace std;

// For now, the tests and treemap contains car names and first letters as key,value for the map - will change for part 2 maybe, also changing it to read from file

template <class K, class V>
class TreeMap {
	BinaryTree<pair<K, V>> map; // Im using a binary tree to store key value pairs for the map

	//Implement find node here for get, remove and other methods!!! - instead of calling it in every method 
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
    return false;
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
    // CODE HERE LATER
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
    return false;
}

// This method returns the value of the key in the map - overloaded operator
template <class K, class V>
V& TreeMap<K, V>::operator[](K key) 
{
    return V();
}
