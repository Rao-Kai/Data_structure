#ifndef BUBBLESORTA_H
#define BUBBLESORTA_H

#include "swapswap.h"

template<typename T>
void bubblesortA(T A[], int lo, int hi){
    while (lo < --hi){
        for(int i = lo; i < hi; i++){
            if (A[i+1] < A[i]){
                swapswap(A[i], A[i+1]);
            }
        }
    }
        
}

#endif