#pragma once

// разработчик: Самаев Антон ИВТ-21

#include <iostream>
#include <vector>
#include <queue>


template <typename T>
class TreeNode
{
private:
	// указатели левого и правого дочерних узлов
	TreeNode<T>* left;
	TreeNode<T>* right;

	// данные в узле
	T data;

public:

	// конструктор без параметров
	// Компилятор напишет конструктор по умолчанию
	TreeNode() = default;

	// конструктор с параметрами
	TreeNode(const T& item, TreeNode<T>* lptr = nullptr, TreeNode<T>* rptr = nullptr);

	// методы доступа к полям указателей
	TreeNode<T>* Left() const;
	TreeNode<T>* Right() const;


	// сделать класс BinSTree дружественным, поскольку необходим
	// доступ к полям left и right
	//friend class BinSTree<T>;


	// метод доступа к полю данных
	T Data() const;

	// методы для задания значений полей
	void SetLeft(TreeNode<T>* left1);
	void SetRight(TreeNode<T>* right1);
	void SetData(T data1);
};


// конструктор инициализирует поля данных и указателей
// значение nullptr соответствует пустому поддереву
template <typename T>
TreeNode<T>::TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr)
{
	data = item;
	left = lptr;
	right = rptr;
}

// Методы Left и Right возвращают значения полей левого и правого указателей
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

// Метод Data возвращает значение поля данных
template <typename T>
T TreeNode<T>::Data() const
{
	return this->data;
}

// Метод задания значения поля данных
template <typename T>
void TreeNode<T>::SetData(T data1) {
	this->data = data1;
}

// Метод задания значения правого потомка
template <typename T>
void TreeNode<T>::SetRight(TreeNode<T>* right1) {
	this->right = right1;
}

// Метод задания значения левого потомка
template <typename T>
void TreeNode<T>::SetLeft(TreeNode<T>* left1) {
	this->left = left1;
}

// Печать узла дерева
template <typename T>
void printNode(TreeNode<T>* root) {
	std::cout << root->Data() << " ";
}

// функция добавления единицы к значению узла
template <typename T>
void add1(TreeNode<T>* root) {
	root->SetData(root->Data() + 1);
}

// функция возведения в квадрат значения узла
template <typename T>
void squaring(TreeNode<T>* root) {
	root->SetData(root->Data() * root->Data());
}


// прямое прохождение узлов дерева
template <typename T>
void preorderPrint(TreeNode<T>* root, void (*func) (TreeNode<T>*))
{

	if (root != nullptr)   // Базовый случай
	{
		func(root);
		preorderPrint(root->Left(), func);   //рекурсивный вызов левого поддерева
		preorderPrint(root->Right(), func);  //рекурсивный вызов правого поддерева
	}

}


// поиск узла по значению
// возвращает уровень, на котором был найден узел
// либо -1, если узла с искомым значением нет
template <typename T>
int SearchNode(TreeNode<T>* root, const T key, int depth = 0) {
	// если дошли до nullptr, до искомого значения в дереве нет
	if (root == nullptr) {
		return -1;
	}

	// поиск в правом поддереве
	if (key > root->Data()) {
		SearchNode(root->Right(), key, depth + 1);
	}

	// поиск в левом поддереве
	else if (key < root->Data()) {
		SearchNode(root->Left(), key, depth + 1);
	}

	// если key равен значению в текущем узле
	else return depth;
}


// операция вставки узла в бинарное дерево поиска
template <typename T>
TreeNode<T>* InsertNode(TreeNode<T>* root, const T value) {

	if (root == nullptr) {

		// если дерево пустое, то создаём корень (первый узел)
		return new TreeNode<T>(value);
	}

	// Вставляем данные либо в левое, либо в правое поддерево
	if (value > root->Data()) {
		// если значение, которое нужно добавить, больше текущего
		root->SetRight(InsertNode(root->Right(), value));
	}
	else if (value < root->Data()) {
		// если значение, которое нужно добавить, меньше текущего
		root->SetLeft(InsertNode(root->Left(), value));
	}

	//возвращаем корень дерева
	return root;
}

// Нахождение минимального узла в поддереве
template <typename T>
TreeNode<T>* getNextLeft(TreeNode<T>* root)
{
	while (root->Left() != nullptr) {
		root = root->Left();
	}

	return root;
}

// нахождение ближайшего наибольшего
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

	// Базовый случай (пустое дерево)
	if (root == nullptr) {
		succ = nullptr;
	}

	// если найден узел, для которого нужно найти ближайшее наибольшее
	else if (root->Data() == key)
	{
		// если есть правый потомок
		if (root->Right() != nullptr) {
			// находим самый левый узел от правого потомка
			succ = getNextLeft(root->Right());
		}
	}

	// поиск нужного узла в левом или правом поддереве
	else if (key < root->Data())
	{
		succ = root;
		Successor(root->Left(), succ, key);
	}
	else {
		Successor(root->Right(), succ, key);
	}
}

// операция удаления узла из бинарного дерева поиска
template <typename T>
TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {

	// базовый случай
	if (root == nullptr) {
		return root;
	}

	// рекурсивный вызов функции, пока не будет найден узел, который нужно удалить
	if (root->Data() > value) {
		root->SetLeft(DeleteNode(root->Left(), value));
		return root;
	}
	else if (root->Data() < value) {
		root->SetRight(DeleteNode(root->Right(), value));
		return root;
	}

	// Когда найден узел на удаление

	// Случаи 1 и 2. если есть только 1 потомок или удалить необходимо лист (0 потомков)
	// если нет левого потомка, то правый поднимается на место удаляемого узла
	if (root->Left() == nullptr) {
		TreeNode<T>* temp = root->Right();
		delete root;
		return temp;
	}
	// если нет правого потомка, то левый поднимается на место удаляемого узла
	else if (root->Right() == nullptr) {
		TreeNode<T>* temp = root->Left();
		delete root;
		return temp;
	}

	// Случай 3. если есть оба потомка
	else {

		// узел, который является родителем ближайшего наибольшего
		TreeNode<T>* succParent = root;

		// Находим ближайшее наибольшее (самый левый узел в правом поддереве) и его родителя
		TreeNode<T>* succ = root->Right();
		while (succ->Left() != nullptr) {
			succParent = succ;
			succ = succ->Left();
		}


		// задача сводится к случаю удаления узла только с правым потомком
		// правого потомка ближайшего наибольшего делаем левым потомком родителя
		// ближайшего наибольшего

		if (succParent != root)
			succParent->SetLeft(succ->Right());
		else
			// если спуска по левому поддереву не было
			succParent->SetRight(succ->Right());


		// данные из ближайшего наибольшего переносятся на место удаляемого узла
		root->SetData(succ->Data());

		// Удаляем ближайшее наибольшее
		delete succ;
		return root;
	}
}


// cоздание массива на основе дерева (обратный обход)
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


// Нахождение глубины дерева
template <typename T>
int Depth(TreeNode<T>* root) {
	int left_height, right_height;
	int depth = 0;
	if (root == nullptr)
		depth = -1;
	else {

		// находим глубину левого и правого поддеревьев
		// рекурсивный вызов функции treeHeight
		left_height = Depth(root->Left());
		right_height = Depth(root->Right());

		// Находим максимальное из поддеревьев
		depth = std::max(left_height, right_height) + 1;
	}
	return depth;
}

// Нахождение количества узлов в дереве
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