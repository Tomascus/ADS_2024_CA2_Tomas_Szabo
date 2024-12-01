#include "pch.h"
#include "CppUnitTest.h"
#include "../CA2 - Binary Tree/TreeMap.h"
#include "../CA2 - Binary Tree/Weapon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCSVApplication
{
	TEST_CLASS(TestCSVApplication)
	{
	public:

		// This test checks if the map has the keys that were added
		TEST_METHOD(TestIndexCreation)
		{
			
			vector<Weapon> items = 
			{
				{"Fireball", "Spell", 38, 25, "Rare"}, {"Iron Sword", "Weapon", 26, 10, "Common"}, {"Healing Light", "Spell", 49, 15, "Uncommon"}
			};
			TreeMap<string, vector<Weapon>> index;

			indexMap(index, items, "type");

			Assert::IsTrue(index.containsKey("Spell"));
			Assert::IsTrue(index.containsKey("Weapon"));
			Assert::AreEqual(2, (int)index["Spell"].size());
			Assert::AreEqual(1, (int)index["Weapon"].size());
		}

		// This test checks if specific key shows subset of other values in the map
		TEST_METHOD(TestViewSubset)
		{
			vector<Weapon> items = 
			{{"Fireball", "Spell", 38, 25, "Rare"}, {"Iron Sword", "Weapon", 26, 10, "Common"}, {"Healing Light", "Spell", 49, 15, "Uncommon"}
			};
			TreeMap<string, vector<Weapon>> index;
			indexMap(index, items, "type");

			// Here we check for the subset of the key spell
			string key = "Spell";
			auto subset = index.get(key);

			Assert::AreEqual(2, (int)subset.size());
			Assert::AreEqual(string("Fireball"), subset[0].name);
			Assert::AreEqual(string("Healing Light"), subset[1].name);
		}

		// This tests if the code handles invalid keys correctly
		TEST_METHOD(TestInvalidSubsetKey)
		{
			vector<Weapon> items = 
			{
				{"Fireball", "Spell", 38, 25, "Rare"}, {"Iron Sword", "Weapon", 26, 10, "Common"}
			};

			TreeMap<string, vector<Weapon>> index;
			indexMap(index, items, "type");

			string key = "Armor";
			bool containsInvalidKey = index.containsKey(key);

			Assert::IsFalse(containsInvalidKey);
		}

		// This text checks if int values are stored and showed correctly
		TEST_METHOD(TestIndexByNumericField)
		{
			vector<Weapon> items = 
			{
				{"Fireball", "Spell", 38, 25, "Rare"},{"Iron Sword", "Weapon", 38, 10, "Common"},{"Healing Light", "Spell", 49, 15, "Uncommon"}
			};

			TreeMap<string, vector<Weapon>> index;
			indexMap(index, items, "damage");

			Assert::IsTrue(index.containsKey("38"));
			Assert::AreEqual(2, (int)index["38"].size());
			Assert::IsTrue(index.containsKey("49"));
			Assert::AreEqual(1, (int)index["49"].size());
		}

		// This checks if the tree map is empty after clearing
		TEST_METHOD(TestMapClear)
		{
			TreeMap<string, vector<Weapon>> index;
			index.put("Key1", { {"Fireball", "Spell", 38, 25, "Rare"} });
			index.put("Key2", { {"Iron Sword", "Weapon", 26, 10, "Common"} });
			index.clear();

			Assert::AreEqual(0, index.size());
			Assert::IsFalse(index.containsKey("Key1"));
			Assert::IsFalse(index.containsKey("Key2"));
		}

	};
}