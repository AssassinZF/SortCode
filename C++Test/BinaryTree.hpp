//
//  BinaryTree.hpp
//  C++Test
//
//  Created by zhanfeng on 2017/9/4.
//  Copyright © 2017年 lzf. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

typedef int TelemType;

typedef struct BinaryTreeNode
{
    TelemType data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
}Node;

//创建二叉树
Node* createBinaryTree();

/*节点总个数*/
int Nodenum(Node* root);

/*二叉树的深度*/
int DepthOfTree(Node* root);

/*二叉树叶子节点数*/
int Leafnum(Node* root);

/* 前序遍历递归版 */
void PreOrderRec(Node * node);

/*中序遍历*/
void inOrderTraverse(Node* root);

/*后序遍历*/
void lastOrderTraverse(Node* root);

/* 层次遍历 */
void LevelOrder(Node * node);

/* 求二叉树第 k 层的节点个数 */
int GetKLevel(Node * node, int k);


/* 判断两棵二叉树是否结构相同 */
bool StructureCmp(Node * node1, Node * node2);


#endif /* BinaryTree_hpp */
