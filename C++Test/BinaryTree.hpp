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

#endif /* BinaryTree_hpp */
