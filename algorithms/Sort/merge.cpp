#include "include/sort.h"
// time complexity: O(nlogn)
// divide and conquer

void mg(int *array, int l, int m, int r) {
    int i, j, k, nl, nr;
    nl = m-l+1; nr = r-m;
    int larr[nl], rarr[nr];

    for(i = 0; i<nl; i++) larr[i] = array[l+i];
    for(j = 0; j<nr; j++) rarr[j] = array[m+1+j];

    i = 0; j = 0; k = l;

    while(i < nl && j<nr) {
        if(larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        }
        else{
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl) {
        array[k] = larr[i];
        i++; k++;
    }
    while(j<nr) {
        array[k] = rarr[j];
        j++; k++;
   }
}
void merge(int *array, int l, int r) {
    int m;
    if(l < r) {
        int m = l+(r-l)/2;
        merge(array, l, m);
        merge(array, m+1, r);
        mg(array, l, m, r);
    }
}

