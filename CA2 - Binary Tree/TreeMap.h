#include <map>
#include "BinaryTree.h"

// For now, the tests and treemap contains car names and first letters as key,value for the map - will change for part 2 maybe, also changing it to read from file

template <class K, class V>
class TreeMap {
private:
    map<K, V> data;
public:
    void put(K key, V value) {
        
		data[key] = value; // Adds key value pair to map
    }

    void clear() {
        
    }

    bool containsKey(K key) {
        
        return false;
    }

    V get(K key) {
        
        return V();
    }

    BinaryTree<K> keySet() {
        
        return BinaryTree<K>();
    }

    int size() {
        
        return 0;
    }

    bool removeKey(K key) {
        
        return false;
    }

    V operator[](K key) {
        
        return V();
    }
};