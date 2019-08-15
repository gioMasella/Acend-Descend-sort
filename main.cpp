#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include "stdlib.h"
#include "sort.cpp"
//#include "steps.cpp"
#include <iomanip>
//#include "steps.h"

int counter;
using namespace std;
void print(int arr[], int arr_size);


int main()
{
    
    
    int *ascend;		//Therefore, we have to make arrays and 2licate them
    int *ascend2;
    int *descend;
    int *descend2;
    int *random;
    int *random2;
    int numArray[] {100,200,300,400,500,1000,2000,4000,10000};	//the values for n
    
    
    
    for (int j = 0; j < 9; j++)		//j will be the index for our numArray
    {
        
        ascend = new int[numArray[j]];	//Every time the loop iterates, new arrays are dynamically created based on numArray[j]
        //cout << *ascend << endl << endl;
        ascend2 = new int[numArray[j]];
        
        descend = new int[numArray[j]];
        descend2 = new int[numArray[j]];
        
        random = new int[numArray[j]];
        random2 = new int[numArray[j]];
        
        for (int i = 0; i < numArray[j]; i++)	//creates an ascending array
        {
            ascend[i] = i + 1;
            ascend2[i] = i + 1;				//creates a duplicate array
            
        }
        for (int i = numArray[j]; i >= 0; i--) //creates a descending array
        {
            descend[numArray[j] - i] = i;
            descend2[numArray[j] - i] = i; //creates a 2licate array
            
        }
        //cout << *descend << endl;
        for (int i = 0; i < numArray[j]; i++)	//creates an ascending array to be randomized
        {
            random[i] = i + 1;
            
        }
        
        random_shuffle(random, random + numArray[j]);	//creates a random permutation of integers
        //parameters sent are address of first element and last element + 1
        
        for (int i = 0; i < numArray[j]; i++)	//sets elements of duplicate array to the exact random permutation used for original random array
        {
            random2[i] = random[i];
        }
        int n;
        cout << "====================" << endl << "When n = " << numArray[j] << endl;
        n = numArray[j];
        int B[n]; // values go into another array
        for (int i = 0; i < n; i++)
            B[i] = rand() % n + 1;
        clock_t t1, t2;
        t1 = clock();
        bubble_sort(B, n);
        t2 = clock();
        cout << "Bubble sort" << endl;
        cout << "Time: " << setprecision(5) << (double)(t2 - t1) / CLOCKS_PER_SEC << endl << "Steps: " << endl
        << "=====================================" << endl;
        //print(B, n);
        
        cout << "When n = " << numArray[j] << endl;
        //insertion sort
        t1 = clock();
        insertion_sort(B, n);
        t2 = clock();
        cout << "Insertion sort" << endl;
        cout << "Time: " << setprecision(5) << (double)(t2 - t1) / CLOCKS_PER_SEC << endl << "Steps: " << endl
        << "=====================================" << endl;
        //print(B, n);
        
        cout << "When n = " << numArray[j] << endl;
        //selection sort
        t1 = clock();
        selection_sort(B, n);
        t2 = clock();
        cout << "Selection sort" << endl;
        cout << "Time: " << setprecision(5) << (double)(t2 - t1) / CLOCKS_PER_SEC << endl << "Steps: " << endl
        << "=====================================" << endl;
        //print(B, n);

        cout << "When n = " << numArray[j] << endl;
        //quick sort
        t1 = clock();
        quick_sort(B, n);
        t2 = clock();
        cout << "Quick sort" << endl;
        cout << "Time: " << setprecision(5) << (double)(t2 - t1) / CLOCKS_PER_SEC << endl << "Steps: " << endl
        << "=====================================" << endl;
        //print(B, n);
        
        cout << "When n = " << numArray[j] << endl;
        //merger sort
        t1 = clock();
        merger_sort(B, n);
        t2 = clock();
        cout << "Merge sort" << endl;
        cout << "Time: " << setprecision(5) << (double)(t2 - t1) / CLOCKS_PER_SEC << endl << "Steps: " << endl
        << "=====================================" << endl;
        //print(B, n);

    }
    return 0;
}


void print(int arr[], int arr_size)
{
  for (int i = 0; i < arr_size; ++i)
      cout << arr[i] << " ";
      cout << "\n================================================" << endl;
}


