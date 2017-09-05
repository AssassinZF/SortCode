//
//  BinaryTree.cpp
//  C++Test
//
//  Created by zhanfeng on 2017/9/4.
//  Copyright © 2017年 lzf. All rights reserved.
//

#include "BinaryTree.hpp"
#include <iostream>
#include <queue>

using namespace std;

/* 创建二叉树 */

Node* createBinaryTree()
{
    Node *p;
    TelemType ch;
    cin>>ch;
    if(ch == 0)     //如果到了叶子节点，接下来的左、右子树分别赋值为0
    {
        p = NULL;
    }
    else
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = ch;
        p->left  = createBinaryTree();  //递归创建左子树
        p->right = createBinaryTree();  //递归创建右子树
    }
    return p;
}

/*节点总个数*/
int Nodenum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return 1+Nodenum(root->left)+Nodenum(root->right);
        
    }
}

/*二叉树的深度*/
int DepthOfTree(Node* root)
{
    if(root != NULL)
    {
        return DepthOfTree(root->left)>DepthOfTree(root->right)?DepthOfTree(root->left)+1:DepthOfTree(root->right)+1;
    }else{
        return 0;
    }
}

/*二叉树叶子节点数*/
int Leafnum(Node* root)
{
    if(!root)
    {
        return 0;
    }
    else if(  (root->left == NULL) && (root->right == NULL) )
    {
        return 1;
    }
    else
    {
        return  (Leafnum(root->left) + Leafnum(root->right)) ;
    }
}

/* 前序遍历递归版 */
void PreOrderRec(Node * node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";   //先输出当前节点
    PreOrderRec(node->left);     //然后输出左孩子
    PreOrderRec(node->right);    //最后输出右孩子
}

/*中序遍历*/
void inOrderTraverse(Node* root)
{
    if( root )
    {
        inOrderTraverse(root->left);
        cout<<root->data<<' ';
        inOrderTraverse(root->right);
    }
}

/*后序遍历*/
void lastOrderTraverse(Node* root)
{
    if( root )
    {
        lastOrderTraverse(root->left);
        lastOrderTraverse(root->right);
        cout<<root->data<<' ';
    }
}

/* 层次遍历 */
void LevelOrder(Node * node)
{
    Node * p = node;
    queue<Node*> Q;  //队列
    Q.push(p);
    while (!Q.empty())
    {
        p = Q.front();
        cout << p->data << " ";
        Q.pop();
        if (p->left)
            Q.push(p->left);  //注意顺序，先进左孩子
        if (p->right)
            Q.push(p->right);
    }
}

/* 求二叉树第 k 层的节点个数 */
int GetKLevel(Node * node, int k)
{
    if (node == nullptr)
        return 0;
    if (k == 1)
        return 1;
    return GetKLevel(node->left, k - 1) + GetKLevel(node->right, k - 1);
}

/* 判断两棵二叉树是否结构相同 */
bool StructureCmp(Node * node1, Node * node2)
{
    if (node1 == nullptr && node2 == nullptr)
        return true;
    else if (node1 == nullptr || node2 == nullptr)
        return false;
    return StructureCmp(node1->left, node2->left) && StructureCmp(node1->right, node2->right);
}

/* 求二叉树的镜像 */
void Mirror(Node * node)
{
    if (node == nullptr)
        return;
    Node * temp = node->left;
    node->left = node->right;
    node->right = temp;
    Mirror(node->left);
    Mirror(node->right);
}



