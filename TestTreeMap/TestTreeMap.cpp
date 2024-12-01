#include "pch.h"
#include "CppUnitTest.h"
#include "../CA2 - Binary Tree/TreeMap.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTests
{
	TEST_CLASS(TreeMapTests)
	{
	public:

		// For now, the tests and treemap contains car names and first letters as key,value for the map 
		// This test checks if the TreeMap is empty after clearing it 
		TEST_METHOD(TestClear)
		{
			TreeMap<char, string> map;
			map.put('A', "Audi");
			map.put('B', "Bentley");

			map.clear();
			Assert::AreEqual(0, map.size()); // Size should be 0 
			Assert::IsFalse(map.containsKey('A')); // All keys previously added should not exist
			Assert::IsFalse(map.containsKey('B'));
		}

		// This test checks if the TreeMap has the keys that were added, also checks for keys not added
		TEST_METHOD(TestContainsKey)
		{
			TreeMap<char, string> map;
			map.put('A', "Audi");
			map.put('B', "Bentley");

			Assert::IsTrue(map.containsKey('A')); // Key in the map exists
			Assert::IsFalse(map.containsKey('C')); // Key in the map doesnt exist
		}

		// This test checks if the TreeMap returns the correct value (string car name) for the key 
		TEST_METHOD(TestGet)
		{
			TreeMap<char, string> map;

			Assert::AreEqual(string(""), map.get('A')); // This tests an edge case where the key is not in the map at the start

			map.put('A', "Audi");
			map.put('B', "Bentley");

			Assert::AreEqual(string("Audi"), map.get('A'));
			Assert::AreEqual(string("Bentley"), map.get('B'));

			// If the key does not exist, it returns a default value (empty string) 
			Assert::AreEqual(string(""), map.get('C'));
		}

		// This test checks if the TreeMap returns correct key based on array of keys, checks if the array size is correct and if the keys are in the correct order
		TEST_METHOD(TestKeySet)
		{
			TreeMap<char, string> map;

			map.put('A', "Audi");
			map.put('B', "Bentley");
			map.put('C', "Chevrolet");

			BinaryTree<char> keys = map.keySet();
			char* keyArray = keys.toArray();

			keys.printInOrder();
			Assert::AreEqual(3, keys.count());
			Assert::AreEqual('A', keyArray[0]);
			Assert::AreEqual('B', keyArray[1]);
			Assert::AreEqual('C', keyArray[2]);

			delete[] keyArray; // Free the memory for the array
		}

		// This test checks if the TreeMap can add, update and get values correctly
		TEST_METHOD(TestPut)
		{
			TreeMap<char, string> map;
			map.put('A', "Audi");
			map.put('B', "Bentley");

			Assert::AreEqual(string("Audi"), map.get('A'));
			Assert::AreEqual(string("Bentley"), map.get('B'));

			// Update existing key to a different one
			map.put('A', "Dodge");

			// Check if the value was updated
			Assert::AreEqual(string("Dodge"), map.get('A'));
		}

		// This test checks if the TreeMap returns the correct size after adding, updating and removing keys
		TEST_METHOD(TestSize)
		{
			TreeMap<char, string> map;
			Assert::AreEqual(0, map.size()); // Checks if starting size is 0

			map.put('A', "Audi");
			map.put('B', "Bentley");

			Assert::AreEqual(2, map.size()); // Checks if size is correct after adding keys

			// Update existing key to a different one and check if the size is the same
			map.put('A', "Dodge");
			Assert::AreEqual(2, map.size());

			map.removeKey('B');
			Assert::AreEqual(1, map.size()); // Checks if size is correct after removing a key
		}

		// This test checks if the TreeMap can remove keys correctly
		TEST_METHOD(TestRemoveKey)
		{
			TreeMap<char, string> map;
			map.put('A', "Audi");
			map.put('B', "Bentley");
			map.put('C', "Chevrolet");

			Assert::IsTrue(map.removeKey('A'));
			Assert::AreEqual(2, map.size());
			Assert::IsFalse(map.containsKey('A')); // The key should not exist 

			Assert::IsFalse(map.removeKey('D')); // Remove key that doesnt exist
			Assert::AreEqual(2, map.size()); // Size should be the same
		}

		// This test checks if the TreeMap can return the correct value for a key using the "[]" operator or null if the key doesnt exist
		TEST_METHOD(TestOperator)
		{
			TreeMap<char, string> map;

			Assert::AreEqual(string(""), map['C']); // Tests an edge case at the start where the key is not there

			map.put('A', "Audi");
			map.put('B', "Bentley");

			Assert::AreEqual(string("Audi"), map['A']); // Checks if the value is correct
			Assert::AreEqual(string("Bentley"), map['B']);

			// If the key doesnt exist, it returns a default value (empty string) 
			Assert::AreEqual(string(""), map['C']);
		}

		// This test checks how it handles duplicate keys, it should update the value of the key
		TEST_METHOD(TestDuplicateKeys) {
			TreeMap<char, string> map;
			map.put('B', "BMW");
			map.put('B', "Bentley");

			Assert::AreEqual(1, map.size()); 
			Assert::AreEqual(string("Bentley"), map.get('B')); 
		}

	};
}
