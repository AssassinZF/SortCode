//
//  SortCode.cpp
//  C++Test
//
//  Created by zhanfeng on 2017/9/4.
//  Copyright © 2017年 lzf. All rights reserved.
//

#include "SortCode.hpp"
#include <stdlib.h>

void swap1(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

#pragma mark - 冒泡排序
void bubbleSort(int array[],int count){
    int k, j;
    int flag = count;
    while (flag > 0)
    {
        k = flag;
        flag = 0;
        for (j = 1; j < k; j++)
        {
            if (array[j - 1] > array[j])
            {
                swap1(&array[j - 1], &array[j]);
                flag = j;
            }
        }
    }
}

#pragma mark - 直接插入排序
void insertSort(int array[],int count){
    int i,j;
    int temp;
    for (i = 1; i < count; i ++) {
        temp = array[i];
        for (j = i; j>0 && array[j] < array[j - 1]; j--) {
            swap1(&array[j - 1], &array[j]);
        }
        array[j] = temp;
    }
}

#pragma mark - 希尔排序
/*希尔排序:先将整个待排元素序列分割成若干子序列（由相隔某个“增量”的元素组成的）分别进行
 直接插入排序，然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，
 再对全体元素进行一次直接插入排序（增量为1）。其时间复杂度为O(n^3/2),要好于直接插入排序的O(n^2) */
void ShellSort(int *arr, int N)
{
    int i, j, increment;
    int tmp;
    for (increment = N / 2; increment > 0; increment /= 2)
    {
        for (i = increment; i < N; i++)
        {
            tmp = arr[i];
            for (j = i; j >= increment; j -= increment)
            {
                if (arr[j - increment] > tmp)
                    arr[j] = arr[j - increment];
                else
                    break;
            }
            arr[j] = tmp;
        }
        
    }
}

#pragma mark - 选择排序
void selectSort(int array[],int count){
    int i,j,minIndex;
    for (i = 0; i < count; i ++) {
        minIndex = i;
        for (j = i+1; j< count; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap1(&array[i], &array[minIndex]);
    }
}

#pragma mark - 堆排序
void adjustHeap(int * arrs, int p, int len);

void HeapSort(ElemType arrs[], int count){
    //建立堆，从最底层的父节点开始
    for(int i = count /2 -1; i>=0; i--)
        adjustHeap(arrs, i, count);
    
    //交换元素到有序数列之后 继续调整堆
    for(int i = count -1; i>=0; i--){
        int maxEle = arrs[0];
        arrs[0] = arrs[i];
        arrs[i] = maxEle;
        
        adjustHeap(arrs, 0, i);
    }

}

void adjustHeap(int * arrs, int p, int len){
    int curParent = arrs[p];
    int child = 2* p + 1;   //左孩子
    while(child < len){     //没有孩子
        if(child+1<len&&arrs[child]<arrs[child+1]){
            child++;    //较大孩子的下标
        }
        if(curParent<arrs[child]){
            arrs[p]=arrs[child];
            //没有将curParent赋值给孩子是因为还要迭代子树，
            //如果其孩子中有大的，会上移，curParent还要继续下移。
            p=child;
            child=2*p+1;
        }
        else
            break;
    }
    arrs[p]=curParent;
}

#pragma mark - 快排
void quicksort(int a[],int left,int right)
{
    int i,j,t,temp;
    if(left>=right)
        return;
    temp=a[left]; //temp中存的就是基准数
    i=left;
    j=right;
    while(i!=j)
    {
        while(a[j]>=temp && i<j)   //顺序很重要，要先从右边开始找
            j--;
        while(a[i]<=temp && i<j)   //再找右边的
            i++;
        if(i<j)                   //交换两个数在数组中的位置
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];   //最终将基准数归位
    a[i]=temp;
    quicksort(a,left,i-1);//继续处理左边的，这里是一个递归的过程
    quicksort(a,i+1,right);//继续处理右边的 ，这里是一个递归的过程
}

template<typename T>
void qsort(T lst[], int head, int tail) {
    /*
     * 功能：对数组升序快排，递归实现
     * 参数：lst：带排序数组，head：数组首元素下标，tail：数组末元素下标
     * 返回值：无
     */
    
    if (head >= tail) return ;
    
    int i = head, j = tail;
    
    T pivot = lst[head];  // 通常取第一个数为基准
    
    while (i < j) { // i,j 相遇即退出循环
        while (i < j and lst[j] >= pivot) j--;
        lst[i] = lst[j];    // 从右向左扫描，将比基准小的数填到左边
        while (i < j and lst[i] <= pivot) i++;
        lst[j] = lst[i];    //  从左向右扫描，将比基准大的数填到右边
    }
    
    lst[i] = pivot; // 将 基准数 填回
    
    qsort(lst, head, i - 1);    // 以基准数为界左右分治
    qsort(lst, j + 1, tail);
}

#pragma mark - 计数排序

int maxNumber(int array[],int count){
    int max = 0;
    int i;
    for (i = 0; i < count; i ++) {
        if (array[i]>array[max]) {
            max = i;
        }
    }
    return array[max];
}

void countingSort(int array[],int count){
    int *pCount = NULL;
    int i;
    int j;
    int nMin,nMax;
    
    if(array == NULL || count <=0)return;
    
    //找最大值和最小值
    nMax = array[0];
    nMin = array[0];
    for(i = 1;i<count;i++)
    {
        if(array[i] > nMax)
        {
            nMax = array[i];
        }
        if(array[i] < nMin)
        {
            nMin = array[i];
        }
    }
    //开辟计数数组
    pCount = (int *)malloc(sizeof(int ) * (nMax-nMin+1));
//    memset(pCount,0,sizeof(int ) * (nMax-nMin+1));
    //计数
    for(i = 0;i<count;i++)
    {
        pCount[array[i]-nMin]++;
    }
    //放回原数组
    j = 0;
    for(i = 0;i< nMax-nMin+1;i++)
    {
        while(pCount[i] != 0)
        {
            array[j] = i+nMin;
            j++;
            pCount[i]--;
        }
    }
}
















