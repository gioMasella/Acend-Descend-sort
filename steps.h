//
//  steps.h
//  sort
//
//  Created by Giovanni Masella on 12/8/16.
//  Copyright © 2016 Giovanni Masella. All rights reserved.
//

#ifndef steps_h
#define steps_h

inline  void Swap(int &a, int &b);
int bubble_sort(int arr[], int arr_size, int steps);
int insertion_sort(int arr[], int arr_size, int steps);
int selection_sort(int arr[], int arr_size, int steps);
int quick_sort(int arr[], int arr_size, int steps);
int merger_sort(int arr[], int arr_size, int steps);
int const MAX = 9;//LENGTH OF ARRAY (FOR now

#endif /* steps_h */
