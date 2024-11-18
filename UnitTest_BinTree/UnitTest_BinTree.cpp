// разработчик: Самаев Антон ИВТ-21

#include "pch.h"
#include "CppUnitTest.h"
#include "../BinTree/TreeNode.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBinTree
{
	TEST_CLASS(UnitTestBinTree)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(1 == 1);
		};

		TEST_METHOD(TestMethod_Count)
		{
			TreeNode<int>* leftleaf, * rightleaf, * root;
			leftleaf = new TreeNode<int>(3);

			rightleaf = new TreeNode<int>(10);
			root = new TreeNode<int>(8, leftleaf, rightleaf);
			InsertNode(root, 1);
			InsertNode(root, 6);
			InsertNode(root, 4);
			InsertNode(root, 7);
			InsertNode(root, 14);
			InsertNode(root, 13);

			Assert::IsTrue(CountNodes(root) == 9);
		};

		

		TEST_METHOD(TestMethod_Depth)
		{
			TreeNode<int>* leftleaf, * rightleaf, * root;
			leftleaf = new TreeNode<int>(3);

			rightleaf = new TreeNode<int>(10);
			root = new TreeNode<int>(8, leftleaf, rightleaf);
			InsertNode(root, 1);
			InsertNode(root, 6);
			InsertNode(root, 4);
			InsertNode(root, 7);
			InsertNode(root, 14);
			InsertNode(root, 13);

			Assert::IsTrue(Depth(root) == 3);
		};

		TEST_METHOD(TestMethod_Search)
		{
			TreeNode<int>* leftleaf, * rightleaf, * root;
			leftleaf = new TreeNode<int>(3);

			rightleaf = new TreeNode<int>(10);
			root = new TreeNode<int>(8, leftleaf, rightleaf);
			InsertNode(root, 1);
			InsertNode(root, 6);
			InsertNode(root, 4);
			InsertNode(root, 7);
			InsertNode(root, 14);
			InsertNode(root, 13);

			Assert::IsTrue(SearchNode(root, 6) == 2);
			Assert::IsTrue(SearchNode(root, 13) == 3);
			Assert::IsTrue(SearchNode(root, 8) == 0);
		};

		TEST_METHOD(TestMethod_Insert)
		{
			TreeNode<int>* leftleaf, * rightleaf, * root;
			leftleaf = new TreeNode<int>(3);

			rightleaf = new TreeNode<int>(10);
			root = new TreeNode<int>(8, leftleaf, rightleaf);
			Assert::IsTrue(CountNodes(root) == 3);
			InsertNode(root, 1);
			InsertNode(root, 6);
			Assert::IsTrue(CountNodes(root) == 5);
			InsertNode(root, 4);
			Assert::IsTrue(CountNodes(root) == 6);
			InsertNode(root, 7);
			InsertNode(root, 14);
			InsertNode(root, 13);
			Assert::IsTrue(CountNodes(root) == 9);

		};

		TEST_METHOD(TestMethod_Successor)
		{
			TreeNode<int>* leftleaf, * rightleaf, * root;
			leftleaf = new TreeNode<int>(3);

			rightleaf = new TreeNode<int>(10);
			root = new TreeNode<int>(8, leftleaf, rightleaf);
			InsertNode(root, 1);
			InsertNode(root, 6);
			InsertNode(root, 4);
			InsertNode(root, 7);
			InsertNode(root, 14);
			InsertNode(root, 13);
			TreeNode<int>* s = nullptr;
			Successor(root, s, 13);
			Assert::IsTrue(s->Data() == 14);

			Successor(root, s, 3);
			Assert::IsTrue(s->Data() == 4);

		};

		TEST_METHOD(TestMethod_Delete)
		{
			TreeNode<int>* leftleaf, * rightleaf, * root;
			leftleaf = new TreeNode<int>(3);

			rightleaf = new TreeNode<int>(10);
			root = new TreeNode<int>(8, leftleaf, rightleaf);
			InsertNode(root, 1);
			InsertNode(root, 6);
			InsertNode(root, 4);
			InsertNode(root, 7);
			InsertNode(root, 14);
			InsertNode(root, 13);
			Assert::IsTrue(CountNodes(root) == 9);

			DeleteNode(root, 14);
			Assert::IsTrue(CountNodes(root) == 8);

			DeleteNode(root, 4);
			DeleteNode(root, 7);
			Assert::IsTrue(CountNodes(root) == 6);
		};

		TEST_METHOD(TestMethod_ToArray)
		{
			TreeNode<int>* leftleaf, * rightleaf, * root;
			leftleaf = new TreeNode<int>(3);

			rightleaf = new TreeNode<int>(10);
			root = new TreeNode<int>(8, leftleaf, rightleaf);
			InsertNode(root, 1);
			InsertNode(root, 6);
			InsertNode(root, 4);
			InsertNode(root, 7);
			InsertNode(root, 14);
			InsertNode(root, 13);

			std::vector<int> arr, arr1 = { 1, 4, 7, 6, 3, 13, 14, 10, 8 };
			TreeToArrayLRN(root, arr);
			bool a = arr == arr1;
			Assert::IsTrue(a == 1);
		};
	};
}
