// разработчик: Самаев Антон ИВТ-21

#include "pch.h"
#include "CppUnitTest.h"
#include "../BinTree/TreeNode.h"
#include <vector>

// Класс для бинарного дерева
template <typename T>
class BinaryTree {
public:
	TreeNode<T>* root; // Корень дерева

	// Конструктор для создания пустого дерева
	BinaryTree() : root(nullptr) {}

};

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

		TEST_METHOD(TestMethod_Data)
		{
			TreeNode<int>*root;
			// дерево из одного узла
			root = new TreeNode<int>(3);
			Assert::IsTrue(root->Data() == 3);
		};

		TEST_METHOD(TestMethod_Count)
		{
			// обычное бинарное дерево
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

			// вырожденное
			/*
			* 3
			*  \
			*   4
			*	 \
			*	  6
			*      \
			*       8
			*        \
			*         9
			*		   \
			*          12
			*           \
			*            20
			*/
			TreeNode<int>* root2;
			root2 = new TreeNode<int>(3);
			InsertNode(root2, 4);
			InsertNode(root2, 6);
			InsertNode(root2, 8);
			InsertNode(root2, 9);
			InsertNode(root2, 12);
			InsertNode(root2, 20);

			Assert::IsTrue(CountNodes(root2) == 7);

			// сбалансированное дерево
			/*
			*		   10
					  /  \
					 7    13
					/ \   / \
				   1   9 11  20
			*/
			TreeNode<int>* root3;
			root3 = new TreeNode<int>(10);
			Assert::IsTrue(CountNodes(root3) == 1);
			InsertNode(root3, 7);
			InsertNode(root3, 13);
			InsertNode(root3, 1);
			Assert::IsTrue(CountNodes(root3) == 4);
			InsertNode(root3, 9);
			InsertNode(root3, 11);
			InsertNode(root3, 20);
			Assert::IsTrue(CountNodes(root3) == 7);
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

			// вырожденное
			/*
			* 3
			*  \
			*   4
			*	 \
			*	  6	
			*      \
			*       8
			*        \
			*         9
			*		   \
			*          12
			*           \
			*            20
			*/
			TreeNode<int>* root2;
			root2 = new TreeNode<int>(3);
			InsertNode(root2, 4);
			InsertNode(root2, 6);
			InsertNode(root2, 8);
			InsertNode(root2, 9);
			InsertNode(root2, 12);
			InsertNode(root2, 20);
			Assert::IsTrue(Depth(root2) == 6);

			// сбалансированное дерево
			/*
			*		   10
					  /  \
					 7    13
					/ \   / \
				   1   9 11  20
			*/
			TreeNode<int>* root3;
			root3 = new TreeNode<int>(10);
			Assert::IsTrue(Depth(root3) == 0);
			InsertNode(root3, 7);
			InsertNode(root3, 13);
			Assert::IsTrue(Depth(root3) == 1);
			InsertNode(root3, 1);
			InsertNode(root3, 9);
			InsertNode(root3, 11);
			InsertNode(root3, 20);
			Assert::IsTrue(Depth(root3) == 2);

			
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

			// вырожденное
			/*
			* 3
			*  \
			*   4
			*	 \
			*	  6
			*      \
			*       8
			*        \
			*         9
			*		   \
			*          12
			*           \
			*            20
			*/
			TreeNode<int>* root2;
			root2 = new TreeNode<int>(3);
			InsertNode(root2, 4);
			InsertNode(root2, 6);
			InsertNode(root2, 8);
			InsertNode(root2, 9);
			InsertNode(root2, 12);
			InsertNode(root2, 20);

			Assert::IsTrue(SearchNode(root2, 3) == 0);
			Assert::IsTrue(SearchNode(root2, 6) == 2);
			Assert::IsTrue(SearchNode(root2, 20) == 6);

			// сбалансированное дерево
			/*
			*		   10
					  /  \
					 7    13
					/ \   / \
				   1   9 11  20
			*/
			TreeNode<int>* root3;
			root3 = new TreeNode<int>(10);
			InsertNode(root3, 7);
			InsertNode(root3, 13);
			InsertNode(root3, 1);
			InsertNode(root3, 9);
			InsertNode(root3, 11);
			InsertNode(root3, 20);
			Assert::IsTrue(SearchNode(root3, 10) == 0);
			Assert::IsTrue(SearchNode(root3, 13) == 1);
			Assert::IsTrue(SearchNode(root3, 20) == 2);

			// Создаем пустое бинарное дерево
			TreeNode<int>* root4 = new TreeNode<int>();
			Assert::IsTrue(SearchNode(root4, 10) == -1);
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


			// вырожденное
			/*
			* 3
			*  \
			*   4
			*	 \
			*	  6
			*      \
			*       8
			*        \
			*         9
			*		   \
			*          12
			*           \
			*            20
			*/
			TreeNode<int>* root2;
			root2 = new TreeNode<int>(3);
			Assert::IsTrue(CountNodes(root2) == 1);
			InsertNode(root2, 4);
			InsertNode(root2, 6);
			Assert::IsTrue(CountNodes(root2) == 3);
			InsertNode(root2, 8);
			InsertNode(root2, 9);
			InsertNode(root2, 12);
			InsertNode(root2, 20);
			Assert::IsTrue(CountNodes(root2) == 7);

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

			// вырожденное
			/*
			* 3
			*  \
			*   4
			*	 \
			*	  6
			*      \
			*       8
			*        \
			*         9
			*		   \
			*          12
			*           \
			*            20
			*/
			TreeNode<int>* root2;
			root2 = new TreeNode<int>(3);
			InsertNode(root2, 4);
			InsertNode(root2, 6);
			InsertNode(root2, 8);
			InsertNode(root2, 9);
			InsertNode(root2, 12);
			InsertNode(root2, 20);
			TreeNode<int>* s2 = nullptr;
			Successor(root2, s2, 3);
			Assert::IsTrue(s2->Data() == 4);
			Successor(root2, s2, 12);
			Assert::IsTrue(s2->Data() == 20);

			// сбалансированное дерево
			/*
			*		   10
					  /  \
					 7    13
					/ \   / \
				   1   9 11  20
			*/
			TreeNode<int>* root3;
			root3 = new TreeNode<int>(10);
			InsertNode(root3, 7);
			InsertNode(root3, 13);
			InsertNode(root3, 1);
			InsertNode(root3, 9);
			InsertNode(root3, 11);
			InsertNode(root3, 20);
			TreeNode<int>* s3 = nullptr;
			Successor(root3, s3, 10);
			Assert::IsTrue(s3->Data() == 11);
			Successor(root3, s3, 7);
			Assert::IsTrue(s3->Data() == 9);

			//TODO пустое дерево
		};



		/*TEST_METHOD(TestMethod_Delete)
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
		};*/

		TEST_METHOD(TestMethod_Remove)
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

			removeNode(root, 14);
			Assert::IsTrue(CountNodes(root) == 8);

			removeNode(root, 4);
			removeNode(root, 7);
			Assert::IsTrue(CountNodes(root) == 6);


			// вырожденное
			/*
			* 3
			*  \
			*   4
			*	 \
			*	  6
			*      \
			*       8
			*        \
			*         9
			*		   \
			*          12
			*           \
			*            20
			*/
			TreeNode<int>* root2;
			root2 = new TreeNode<int>(3);
			InsertNode(root2, 4);
			InsertNode(root2, 6);
			InsertNode(root2, 8);
			InsertNode(root2, 9);
			InsertNode(root2, 12);
			InsertNode(root2, 20);
			Assert::IsTrue(CountNodes(root2) == 7);
			removeNode(root2, 4);
			removeNode(root2, 6);
			Assert::IsTrue(CountNodes(root2) == 5);
			removeNode(root2, 20);
			Assert::IsTrue(CountNodes(root2) == 4);


			// сбалансированное дерево
			/*
			*		   10
					  /  \
					 7    13
					/ \   / \
				   1   9 11  20
			*/
			TreeNode<int>* root3;
			root3 = new TreeNode<int>(10);
			InsertNode(root3, 7);
			InsertNode(root3, 13);
			InsertNode(root3, 1);
			InsertNode(root3, 9);
			InsertNode(root3, 11);
			InsertNode(root3, 20);
			Assert::IsTrue(CountNodes(root3) == 7);
			removeNode(root3, 10);
			Assert::IsTrue(CountNodes(root3) == 6);
			removeNode(root3, 11);
			removeNode(root3, 1);
			Assert::IsTrue(CountNodes(root3) == 4);

			// Создаем пустое бинарное дерево
			TreeNode<int>* root4 = new TreeNode<int>();
			Assert::IsTrue(CountNodes(root4) == 1);
			root4 = nullptr;
			Assert::IsTrue(root4 == nullptr);
			Assert::IsTrue(CountNodes(root4) == 0);
			removeNode(root4, 1);
			Assert::IsTrue(removeNode(root4, 1) == nullptr);
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

		TEST_METHOD(TestMethod_Apply)
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

			Assert::IsTrue(root->Data() == 8);
			add1(root);
			Assert::IsTrue(root->Data() == 9);
		};

		TEST_METHOD(TestMethod_Apply2)
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

			Assert::IsTrue(root->Data() == 8);
			squaring(root);
			Assert::IsTrue(root->Data() == 64);
		};
	};
}
