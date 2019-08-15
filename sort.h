//
//  sort.hpp
//  sort
//
//  Created by Giovanni Masella on 12/7/16.
//  Copyright © 2016 Giovanni Masella. All rights reserved.
//

#ifndef SORT_H
#define SORT_H
//declaration for sort functions
inline  void Swap(int &a, int &b);
void bubble_sort(int arr[], int arr_size);
void insertion_sort(int arr[], int arr_size);
void selection_sort(int arr[], int arr_size);
void quick_sort(int arr[], int arr_size);
void merger_sort(int arr[], int arr_size);
int const MAX = 9;//LENGTH OF ARRAY (FOR NOW)
#endif
