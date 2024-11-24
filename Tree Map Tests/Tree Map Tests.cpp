#include "CppUnitTest.h"
#include "../CA2 - Binary Tree/TreeMap.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTests
{
	TEST_CLASS(TreeMapTests)
	{
	public:
		
		// For now, the tests and treemap contains car names and first letters as key,value for the map - will change for part 2 maybe, also changing it to read from file
		// This test checks if the TreeMap is empty after clearing it 
		TEST_METHOD(TestClear)
		{
			TreeMap<string, char> map;
			map.put("Audi", 'A');
			map.put("Bentley", 'B');

			map.clear();
			Assert::AreEqual(0, map.size()); // Size should be 0 
			Assert::IsFalse(map.containsKey("Audi")); // All keys previously added should not exist
			Assert::IsFalse(map.containsKey("Bentley"));
		}

		// This test checks if the TreeMap has the keys that were added, also checks for keys not added
		TEST_METHOD(TestContainsKey)
		{
			TreeMap<string, char> map;
			map.put("Audi", 'A');
			map.put("Bentley", 'B');

			Assert::IsTrue(map.containsKey("Audi")); // Key in the map exists
			Assert::IsFalse(map.containsKey("Chevrolet")); // Key in the map doesnt exist
		}

		// This test checks if the TreeMap returns the correct value (string car name) for the key 
        TEST_METHOD(TestGet)
        {
			TreeMap<string, char> map;
			map.put("Audi", 'A');
			map.put("Bentley", 'B');

			Assert::AreEqual('A', map.get("Audi"));
			Assert::AreEqual('B', map.get("Bentley"));

			// If the key does not exist, it returns a default value (empty char) - Change ?
			Assert::AreEqual('\0', map.get("Chevrolet"));
        }

		// This test checks if the TreeMap returns correct key based on array of keys, checks if the array size is correct and if the keys are in the correct order
		TEST_METHOD(TestKeySet)
		{
			TreeMap<string, char> map;
			map.put("Audi", 'A');
			map.put("Bentley", 'B');
			map.put("Chevrolet", 'C');

			BinaryTree<string> keys = map.keySet();
			string* keyArray = keys.toArray();

			Assert::AreEqual(3, keys.count()); 
			Assert::AreEqual(string("Audi"), keyArray[0]);
			Assert::AreEqual(string("Bentley"), keyArray[1]);
			Assert::AreEqual(string("Chevrolet"), keyArray[2]);

			delete[] keyArray; // Free the memory for the array
		}

		// This test checks if the TreeMap can add, update and get values correctly
		TEST_METHOD(TestPut)
		{
			TreeMap<string, char> map;
			map.put("Audi", 'A');
			map.put("Bentley", 'B');

			Assert::AreEqual('A', map.get("Audi"));
			Assert::AreEqual('B', map.get("Bentley"));

			// Update existing key to a different one
			map.put("Audi", 'D');

			// Check if the value was updated
			Assert::AreEqual('D', map.get("Audi"));
		}

		// This test checks if the TreeMap returns the correct size after adding, updating and removing keys
		TEST_METHOD(TestSize)
		{
			TreeMap<string, char> map;
			Assert::AreEqual(0, map.size()); // Checks if starting size is 0

			map.put("Audi", 'A');
			map.put("Bentley", 'B');

			Assert::AreEqual(2, map.size()); // Checks if size is correct after adding keys

			// Update existing key to a different one and check if the size is the same
			map.put("Audi", 'D');
			Assert::AreEqual(2, map.size());

			map.removeKey("Bentley");
			Assert::AreEqual(1, map.size()); // Checks if size is correct after removing a key
		}

		// This test checks if the TreeMap can remove keys correctly
		TEST_METHOD(TestRemoveKey)
		{
			TreeMap<string, char> map;
			map.put("Audi", 'A');
			map.put("Bentley", 'B');
			map.put("Chevrolet", 'C');

			Assert::IsTrue(map.removeKey("Audi")); 
			Assert::AreEqual(2, map.size()); 
			Assert::IsFalse(map.containsKey("Audi")); // The key should not exist 

			Assert::IsFalse(map.removeKey("Skoda")); // Remove key that doesnt exist
			Assert::AreEqual(2, map.size()); // Size should be the same
		}

		// This test checks if the TreeMap can return the correct value for a key using the "[]" operator or null if the key doesnt exist
		TEST_METHOD(TestOperator)
		{
			TreeMap<string, char> map;
			map.put("Audi", 'A');
			map.put("Bentley", 'B');

			Assert::AreEqual('A', map["Audi"]); // Checks if the value is correct
			Assert::AreEqual('B', map["Bentley"]);

			// If the key doesnt exist, it returns a default value (empty char) - Change ?
			Assert::AreEqual('\0', map["Chevrolet"]);
		}

	};
}
