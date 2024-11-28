#include <iostream>
using namespace std;

template <class K, class V>
class MapValues {
public:
    K key;
    V value;

    MapValues();
    MapValues(K key, V value);

	// Overloading operators for comparison of keys
    bool operator<(const MapValues& other) const
    {
        return key < other.key;
    }

    bool operator==(const MapValues& other) const
    {
        return key == other.key;
    }

    bool operator>(const MapValues& other) const
    {
        return key > other.key;
    }

	// Overloading the << operator to print key as well as value of each map pair
    friend ostream& operator<<(ostream& out, const MapValues<K, V>& values)
    {
        out << "{" << values.key << ", " << values.value << "}";
        return out;
    }
};

template <class K, class V>
MapValues<K, V>::MapValues() 
{
	// Uses default values
	key = K();
	value = V();
}

template <class K, class V>
MapValues<K, V>::MapValues(K key, V value) 
{
	this->key = key;
	this->value = value;
}


