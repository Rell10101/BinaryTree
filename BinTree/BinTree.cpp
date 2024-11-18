
// разработчик: Самаев Антон ИВТ-21

#include <iostream>
#include "TreeNode.h"

int main()
{
    // создаётся указатели на узлы дерева 
    /*TreeNode<int>* leftleaf, * rightleaf, * root;

    //создаётся указатель на лист дерева (указатели на левый и правый узлы nullptr)
    leftleaf = new TreeNode<int>(12);

    //создаётся узел только с левым потомком
    root = new TreeNode<int>(2, leftleaf, nullptr);

        //       2
        //      /
        //     12

    //printNode(root);

    preorderPrint(root, printNode);

    std::cout << SearchNode(root, 12) << std::endl;
    std::cout << std::endl;*/

    /// Бинарное дерево поиска

    //     
    //     
    //      8   
    //    /   \
    //   3      10
    //  / \       \
    //  1  6       14
    //     /\      /
    //    4  7    13



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

    preorderPrint(root, printNode);
    std::cout << std::endl;


    std::vector<int> arr;
    TreeToArrayLRN(root, arr);
    for (int i = 0; i < 9; i++) {
        std::cout << arr[i] << " ";
    }
    //std::cout << SearchNode(root, 4) << std::endl;


}

