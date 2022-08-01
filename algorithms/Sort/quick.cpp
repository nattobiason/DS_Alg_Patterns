#include "include/sort.h"
// divide an conquer
// Time complexity: 

int partition (int arr[], int low, int high) { 
    int pivot = arr[high]; 
    int i = (low - 1); 
    for(int j = low; j <= high - 1; j++){ 
        if (arr[j] < pivot){ 
            i++; 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  

void quick(int arr[], int low, int high) { 
    if(low < high){ 
        int pi = partition(arr, low, high); 
  
        quick(arr, low, pi - 1); 
        quick(arr, pi + 1, high); 
    } 
} 