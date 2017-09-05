//
//  main.cpp
//  C++Test
//
//  Created by zhanfeng on 2017/9/1.
//  Copyright © 2017年 lzf. All rights reserved.
//

/*
 * 参考：
 * https://www.61mon.com/index.php/archives/191/
 */

#include <iostream>
#include "SortCode.hpp"
#include "BinaryTree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    //原数组
    int array[] = {20,29,2,80,10,33,4,50,23,10};
    int count = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < count; i++)
        cout << array[i] << ",";
    cout << "\n排序结果:" << endl;

    /* 排序代码 */
    /*
    bubbleSort(array, count);
    insertSort(array, count);
    selectSort(array, count);
    HeapSort(array, count);
    for (int i = 0; i < count; i ++) {
        cout << array[i] << ",";
    }
    
    HeapSort(array, count);
    countingSort(array, count);
    quicksort(array, 0, count - 1);
    MergeSort(array, 0, count);
     */
    
    //排序结果
    /*
    for (int i = 0; i < count; i++)
        cout << array[i] << ",";
    cout << endl;
     */
    
    
    /* 二叉树 */
    // 测试二叉树数据：
    //              8
    //            /   \
    //           4     6
    //          / \   / \
    //         7   2  1  3
    
    Node *root = NULL;
    root = createBinaryTree();
    printf("二叉树建立成功");
    cout<<endl;
    
    cout<<"二叉树总节点数为："<<Nodenum(root)<<endl;
    
    cout<<"二叉树深度为："<<DepthOfTree(root)<<endl;
    
    cout<<"二叉树叶子节点数为："<<Leafnum(root)<<endl;
    
    cout<<"前序遍历结果:"<<endl;
    PreOrderRec(root);
    cout<<endl;
    
    cout<<"中序遍历结果:"<<endl;
    inOrderTraverse(root);
    cout<<endl;
    
    cout<<"后序遍历结果:"<<endl;
    lastOrderTraverse(root);
    cout<<endl;

    return 0;
}


