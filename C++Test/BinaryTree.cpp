//
//  BinaryTree.cpp
//  C++Test
//
//  Created by zhanfeng on 2017/9/4.
//  Copyright © 2017年 lzf. All rights reserved.
//

#include "BinaryTree.hpp"
#include <iostream>
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

/* 前序遍历递归版 */
void PreOrderRec(Node * node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";   //先输出当前节点
    PreOrderRec(node->left);     //然后输出左孩子
    PreOrderRec(node->right);    //最后输出右孩子
}
