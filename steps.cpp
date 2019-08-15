//
//  steps.cpp
//  sort
//
//  Created by Giovanni Masella on 12/8/16.
//  Copyright © 2016 Giovanni Masella. All rights reserved.
//

#include <stdio.h>
#include "steps.h"
#include <iostream>
#include <ctime>//for time
using namespace std;

inline void SwapStep(int &a, int &b){
    int k;
    k = a;
    a = b;
    b = k;
}
int bubble_sort(int arr[], int arr_size, int steps)
{
    int count = 0;
    if (arr_size > 1)
    {
        count++;
        int size = arr_size;
        //for (bool sorted = false; sorted == (!sorted); --size)
        for (int i = 1; i < size; i++)
            if (arr[i - 1] > arr[i])
            {
                count++;
                Swap(arr[i - 1], arr[i]);
                //sorted = false;
            }
        count++;
    }
    return count;
}
int insertion_sort(int arr[], int arr_size, int steps)
{
    int count = 0;
    if (arr_size > 1)
    {
        count++;
        int size = arr_size;
        for (int i = 1; i < size; ++i){
            int j = i - 1;
            int key = arr[i];
            while (j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                --j;
                count++;
            }
            arr[j + 1] = key;
            count++;
        }
        count++;
    }
    return count;
}
int selection_sort(int arr[], int arr_size, int steps)
{
    int count = 0;
    for (int i = 0; i < arr_size - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < arr_size; ++j)
            if (arr[j] < arr[min])
                min = j;
        Swap(arr[min], arr[i]);
        count++;
    }
    return count;
}
//quick sort
/*******************quick sort algorithm 1 *****************
 void QuickSort(int arr[], int lo, int hi){
 if(lo < hi){
 int i = lo, j = hi, x = arr[lo];
 while(i < j){
 while(i < j && arr[j] >= x)
 --j;
 if(i < j)
 arr[i++] = arr[j];
 while(i < j && arr[i] < x)
 ++i;
 if(i < j)
 arr[j--] = arr[i];
 }
 arr[i] = x;
 QuickSort(arr, lo, i-1);
 QuickSort(arr, i+1, hi);
 }
 }
 *********************************************************/
/****************quick sort algorithm 2******************/
//reload rand to produce random number in a fixed range
inline int randStep(int p, int q){
    int size = q - p + 1;
    srand(time(NULL));
    return (p + rand() % size);
}
int PartitionStep(int arr[], int lo, int hi){
    //produce ramdom subscript
    int t = randStep(lo, hi);
    Swap(arr[t], arr[hi]);
    
    int index = lo - 1;
    int key = arr[hi];
    for (int i = lo; i < hi; i++){
        if (arr[i] <= key)
            Swap(arr[++index], arr[i]);
    }
    Swap(arr[++index], arr[hi]);
    return index;
}
int QuickSort(int arr[], int lo, int hi, int steps)
{
    int x = steps;
    if (lo < hi)
    {
        int index = PartitionStep(arr, lo, hi);
        QuickSort(arr, lo, index - 1, x);
        QuickSort(arr, index + 1, hi, x);
        x++;
    }
    return x;
}

int quick_sort(int arr[], int arr_size, int steps)
{
    int count = steps;
    QuickSort(arr, 0, arr_size - 1, count);
   return count++;
}

//meger sort
void MergerStep(int arr[], int lo, int  mi, int hi){
    int *temp = new int[hi - lo + 1];//temporary merger array
    int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
    int k = 0;//k is for the temporary array
    while (i <= mi && j <= hi){
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    //rest elements of left-half
    while (i <= mi)
        temp[k++] = arr[i++];
    //rest elements of right-half
    while (j <= hi)
        temp[k++] = arr[j++];
    //copy the mergered temporary array to the original array
    for (k = 0, i = lo; i <= hi; ++i, ++k)
        arr[i] = temp[k];
    
    delete[]temp;
}
void MergerSortStep(int arr[], int lo, int hi)
{
    int count = 0;
    int mid;
    if (lo < hi)
    {
        mid = (lo + hi) >> 1;
        MergerSortStep(arr, lo, mid);
        MergerSortStep(arr, mid + 1, hi);
        count++;
    }
}
int merger_sort(int arr[], int arr_size, int steps)
{
    int count = 0;
    MergerSortStep(arr, 0, arr_size - 1);
    return count++;
}













