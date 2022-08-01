#include "include/sort.h"
// time complexity: O(n) best case, O(n2) avg/worst case

void insertion(int *array, int size){ 
    int key, j;
    for(int i = 1; i < size; i++) {
        key = array[i];//take value
        j = i;
        while(j > 0 && array[j-1]>key) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = key;   //insert in right place
    }
}