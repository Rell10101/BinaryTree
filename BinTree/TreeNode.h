#pragma once

// �����������: ������ ����� ���-21

#include <iostream>
#include <vector>
#include <queue>


template <typename T>
class TreeNode
{
private:
	// ��������� ������ � ������� �������� �����
	TreeNode<T>* left;
	TreeNode<T>* right;

	// ������ � ����
	T data;

public:

	// ����������� ��� ����������
	// ���������� ������� ����������� �� ���������
	TreeNode() = default;

	// ����������� � �����������
	TreeNode(const T& item, TreeNode<T>* lptr = nullptr, TreeNode<T>* rptr = nullptr);

	// ������ ������� � ����� ����������
	TreeNode<T>* Left() const;
	TreeNode<T>* Right() const;


	// ������� ����� BinSTree �������������, ��������� ���������
	// ������ � ����� left � right
	//friend class BinSTree<T>;


	// ����� ������� � ���� ������
	T Data() const;

	// ������ ��� ������� �������� �����
	void SetLeft(TreeNode<T>* left1);
	void SetRight(TreeNode<T>* right1);
	void SetData(T data1);
};


// ����������� �������������� ���� ������ � ����������
// �������� nullptr ������������� ������� ���������
template <typename T>
TreeNode<T>::TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr)
{
	data = item;
	left = lptr;
	right = rptr;
}

// ������ Left � Right ���������� �������� ����� ������ � ������� ����������
template <typename T>
TreeNode<T>* TreeNode<T>::Right() const
{
	return this->right;
}

template <typename T>
TreeNode<T>* TreeNode<T>::Left() const
{
	return this->left;
}

// ����� Data ���������� �������� ���� ������
template <typename T>
T TreeNode<T>::Data() const
{
	return this->data;
}

// ����� ������� �������� ���� ������
template <typename T>
void TreeNode<T>::SetData(T data1) {
	this->data = data1;
}

// ����� ������� �������� ������� �������
template <typename T>
void TreeNode<T>::SetRight(TreeNode<T>* right1) {
	this->right = right1;
}

// ����� ������� �������� ������ �������
template <typename T>
void TreeNode<T>::SetLeft(TreeNode<T>* left1) {
	this->left = left1;
}

// ������ ���� ������
template <typename T>
void printNode(TreeNode<T>* root) {
	std::cout << root->Data() << " ";
}

// ������� ���������� ������� � �������� ����
template <typename T>
void add1(TreeNode<T>* root) {
	root->SetData(root->Data() + 1);
}

// ������� ���������� � ������� �������� ����
template <typename T>
void squaring(TreeNode<T>* root) {
	root->SetData(root->Data() * root->Data());
}


// ������ ����������� ����� ������
template <typename T>
void preorderPrint(TreeNode<T>* root, void (*func) (TreeNode<T>*))
{

	if (root != nullptr)   // ������� ������
	{
		func(root);
		preorderPrint(root->Left(), func);   //����������� ����� ������ ���������
		preorderPrint(root->Right(), func);  //����������� ����� ������� ���������
	}

}


// ����� ���� �� ��������
// ���������� �������, �� ������� ��� ������ ����
// ���� -1, ���� ���� � ������� ��������� ���
template <typename T>
int SearchNode(TreeNode<T>* root, const T key, int depth = 0) {
	// ���� ����� �� nullptr, �� �������� �������� � ������ ���
	if (root == nullptr) {
		return -1;
	}

	// ����� � ������ ���������
	if (key > root->Data()) {
		SearchNode(root->Right(), key, depth + 1);
	}

	// ����� � ����� ���������
	else if (key < root->Data()) {
		SearchNode(root->Left(), key, depth + 1);
	}

	// ���� key ����� �������� � ������� ����
	else return depth;
}


// �������� ������� ���� � �������� ������ ������
template <typename T>
TreeNode<T>* InsertNode(TreeNode<T>* root, const T value) {

	if (root == nullptr) {

		// ���� ������ ������, �� ������ ������ (������ ����)
		return new TreeNode<T>(value);
	}

	// ��������� ������ ���� � �����, ���� � ������ ���������
	if (value > root->Data()) {
		// ���� ��������, ������� ����� ��������, ������ ��������
		root->SetRight(InsertNode(root->Right(), value));
	}
	else if (value < root->Data()) {
		// ���� ��������, ������� ����� ��������, ������ ��������
		root->SetLeft(InsertNode(root->Left(), value));
	}

	//���������� ������ ������
	return root;
}

// ���������� ������������ ���� � ���������
template <typename T>
TreeNode<T>* getNextLeft(TreeNode<T>* root)
{
	while (root->Left() != nullptr) {
		root = root->Left();
	}

	return root;
}

// ���������� ���������� �����������
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

	// ������� ������ (������ ������)
	if (root == nullptr) {
		succ = nullptr;
	}

	// ���� ������ ����, ��� �������� ����� ����� ��������� ����������
	else if (root->Data() == key)
	{
		// ���� ���� ������ �������
		if (root->Right() != nullptr) {
			// ������� ����� ����� ���� �� ������� �������
			succ = getNextLeft(root->Right());
		}
	}

	// ����� ������� ���� � ����� ��� ������ ���������
	else if (key < root->Data())
	{
		succ = root;
		Successor(root->Left(), succ, key);
	}
	else {
		Successor(root->Right(), succ, key);
	}
}

// �������� �������� ���� �� ��������� ������ ������
template <typename T>
TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {

	// ������� ������
	if (root == nullptr) {
		return root;
	}

	// ����������� ����� �������, ���� �� ����� ������ ����, ������� ����� �������
	if (root->Data() > value) {
		root->SetLeft(DeleteNode(root->Left(), value));
		return root;
	}
	else if (root->Data() < value) {
		root->SetRight(DeleteNode(root->Right(), value));
		return root;
	}

	// ����� ������ ���� �� ��������

	// ������ 1 � 2. ���� ���� ������ 1 ������� ��� ������� ���������� ���� (0 ��������)
	// ���� ��� ������ �������, �� ������ ����������� �� ����� ���������� ����
	if (root->Left() == nullptr) {
		TreeNode<T>* temp = root->Right();
		delete root;
		return temp;
	}
	// ���� ��� ������� �������, �� ����� ����������� �� ����� ���������� ����
	else if (root->Right() == nullptr) {
		TreeNode<T>* temp = root->Left();
		delete root;
		return temp;
	}

	// ������ 3. ���� ���� ��� �������
	else {

		// ����, ������� �������� ��������� ���������� �����������
		TreeNode<T>* succParent = root;

		// ������� ��������� ���������� (����� ����� ���� � ������ ���������) � ��� ��������
		TreeNode<T>* succ = root->Right();
		while (succ->Left() != nullptr) {
			succParent = succ;
			succ = succ->Left();
		}


		// ������ �������� � ������ �������� ���� ������ � ������ ��������
		// ������� ������� ���������� ����������� ������ ����� �������� ��������
		// ���������� �����������

		if (succParent != root)
			succParent->SetLeft(succ->Right());
		else
			// ���� ������ �� ������ ��������� �� ����
			succParent->SetRight(succ->Right());


		// ������ �� ���������� ����������� ����������� �� ����� ���������� ����
		root->SetData(succ->Data());

		// ������� ��������� ����������
		delete succ;
		return root;
	}
}


// c������� ������� �� ������ ������ (�������� �����)
template <typename T>
void TreeToArrayLRN(TreeNode<T>* root, std::vector<T>& arr) {
	if (root != nullptr) {

		if (root->Left() != nullptr) {
			TreeToArrayLRN(root->Left(), arr);
		}

		if (root->Right() != nullptr) {
			TreeToArrayLRN(root->Right(), arr);
		}

		arr.push_back(root->Data());
	}
}


// ���������� ������� ������
template <typename T>
int Depth(TreeNode<T>* root) {
	int left_height, right_height;
	int depth = 0;
	if (root == nullptr)
		depth = -1;
	else {

		// ������� ������� ������ � ������� �����������
		// ����������� ����� ������� treeHeight
		left_height = Depth(root->Left());
		right_height = Depth(root->Right());

		// ������� ������������ �� �����������
		depth = std::max(left_height, right_height) + 1;
	}
	return depth;
}

// ���������� ���������� ����� � ������
template <typename T>
unsigned int CountNodes(TreeNode<T>* root)
{
	if (root == nullptr) {
		return 0;
	}

	unsigned int l = CountNodes(root->Left());
	unsigned int r = CountNodes(root->Right());

	return 1 + l + r;
}