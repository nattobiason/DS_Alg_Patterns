#include "include/sort.h"
// time complexity: O(n) best case, O(n2) avg/worst case

void bubble(int *array, int size) { 
    for(int i = 0; i<size; i++) {
        int swaps = 0;
        for(int j = 0; j<size-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                swaps = 1;
            }
        }
        if(!swaps) break;
   }
}