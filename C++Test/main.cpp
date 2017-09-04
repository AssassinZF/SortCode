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
#include "BinaryTree.cpp"

using namespace std;

int main(int argc, const char * argv[]) {

    //原数组
    int array[] = {20,29,2,80,10,33,4,50,23,10};
    int count = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < count; i++)
        cout << array[i] << ",";
    cout << "\n排序结果:" << endl;

    //排序代码
    
    //    bubbleSort(array, count);
    //    insertSort(array, count);
    //    selectSort(array, count);
//    HeapSort(array, count);
//    for (int i = 0; i < count; i ++) {
//        cout << array[i] << ",";
//    }
    
//    HeapSort(array, count);
//    countingSort(array, count);
//    quicksort(array, 0, count - 1);
    MergeSort(array, 0, count);
    
    //排序结果
    for (int i = 0; i < count; i++)
        cout << array[i] << ",";
    cout << endl;
    
    Node *node = NULL;
    node = createBinaryTree();
    return 0;
}


