//
//  SortCode.hpp
//  C++Test
//
//  Created by zhanfeng on 2017/9/4.
//  Copyright © 2017年 lzf. All rights reserved.
//

#ifndef SortCode_hpp
#define SortCode_hpp

#include <stdio.h>

typedef int ElemType;
/*
 冒泡排序最优方案
 */
void bubbleSort(int array[],int count);//O(n^2)
/*
 插入排序
 */
void insertSort(int array[],int count);//O(n^2)

/*
 选择排序
 */
void selectSort(int array[],int count);//O(n^2)

/*
 堆排序
 注意:堆实际上是一棵完全二叉树，其任何一非叶节点满足性质： Key[i]<=key[2i+1]&&Key[i]<=key[2i+2]（小顶堆）或者：Key[i]>=Key[2i+1]&&key>=key[2i+2]（大顶堆） 即任何一非叶节点的关键字不大于或者不小于其左右孩子节点的关键字。
 */
void HeapSort(ElemType arrs[], int count);

/*
 快排
 */
void quicksort(int a[],int left,int right);

/*
 计数排序
 */
void countingSort(int array[],int count);

#endif /* SortCode_hpp */
