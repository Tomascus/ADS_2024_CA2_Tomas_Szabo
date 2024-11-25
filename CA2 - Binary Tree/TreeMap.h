#include <map>
#include <utility>
#include "BinaryTree.h"

// For now, the tests and treemap contains car names and first letters as key,value for the map - will change for part 2 maybe, also changing it to read from file

template <class K, class V>
class TreeMap {
	BinaryTree<pair<K, V>> map; // Im using a binary tree to store key value pairs for the map

	//Implement find node here for get, remove and other methods!!! - instead of calling it in every method

public:
    void put(K key, V value) 
    {
		
    }

	// Clears the map 
    void clear() 
    {
        map.clear();
    }

    bool containsKey(K key) 
    {    
        return false;
    }

    V get(K key) 
    {
        return V();
    }

    BinaryTree<K> keySet() 
    {
        return BinaryTree<K>();
    }

	// Returns size of map
    int size() 
    {
        return map.count();
    }

    bool removeKey(K key) 
    {
        return false;
    }

    V operator[](K key) 
    {
        return V();
    }
};