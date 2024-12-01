#include "pch.h"
#include "CppUnitTest.h"
#include "../CA2 - Binary Tree/BSTNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


//These tests based on the provided sample code tests
namespace SearchTreeTest
{
	TEST_CLASS(TestBSTNode)
	{
	public:
		//Test Seeing the BSTNode being created ** left,right and parent are null
		TEST_METHOD(TestConstructor)
		{
			BSTNode<int> node(1);
			Assert::AreEqual(1, node.getItem());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
			Assert::IsNull(node.getParent());
		}
		//Testing to see if child will be added to the left of the parent
		TEST_METHOD(TestAddLessThan)
		{
			BSTNode<int> node(4);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getLeft());
			int x = 3;
			node.add(x);
			Assert::IsNotNull(node.getLeft());
			Assert::AreEqual(3, node.getLeft()->getItem());
		}

		//Testing to see if child will be added to the right of the parent
		TEST_METHOD(TestAddGreaterThan)
		{
			BSTNode<int> node(4);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getRight());
			int x = 6;
			node.add(x);
			Assert::IsNotNull(node.getRight());
			Assert::AreEqual(6, node.getRight()->getItem());
		}

		/*
		Test Add to add a node as a child. As this is
		A Binary Search Tree, all items add should remain in order.
		By Adding 6 to a node wiht a value of 4, the new node
		should be on the right. If we then add two children 5 and 7
		They should appear as follows
					4
	   / \
	   6
	  / \
					5   7
		*/

		TEST_METHOD(TestAddGreaterThanChildren)
		{
			BSTNode<int> node(4);
			int x = 6, y = 5, z = 7;
			node.add(x);
			BSTNode<int>* right = node.getRight();
			node.add(y);
			node.add(z);
			Assert::IsNotNull(right->getLeft());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::IsNotNull(right->getRight());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		/*
		Test Add to add a node as a child. As this is
		A Binary Search Tree, all items add should remain in order.
		By Adding 2 to a node wiht a value of 4, the new node
		should be on the left. If we then add two children 1 and 3
		They should appear as follows
	 4
				/ \
	  2
	 / \
	1   3
		*/

		TEST_METHOD(TestAddLessThanChildren)
		{
			BSTNode<int> node(4);
			int x = 2, y = 1, z = 3;
			node.add(x);
			BSTNode<int>* left = node.getLeft();
			node.add(y);
			node.add(z);
			Assert::IsNotNull(left->getLeft());
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNotNull(left->getRight());
			Assert::AreEqual(3, left->getRight()->getItem());

		}

		/*
			Test the count method returns the correct value.
			to test this we will use the following tree
					4
	   / \
	  2   6
	 / \ / \
				1  3 5  7

		*/
		TEST_METHOD(TestCount)
		{
			int a = 2, b = 6, c = 1, d = 3, e = 5, f = 7;
			BSTNode<int> node(4);
			node.add(a);
			node.add(b);
			BSTNode<int>* left = node.getLeft();
			node.add(c);
			node.add(d);
			node.add(e);
			node.add(f);
			Assert::AreEqual(7, node.count());

		}
	};
}