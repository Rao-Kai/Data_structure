#ifndef BUBBLESORTC_H
#define BUBBLESORTC_H

#include "swapswap.h"

template<typename T>
void bubblesortC(T A[], int lo, int hi){
    for(int last; lo < hi; hi = last){
        for( int i = ( last = lo ) + 1; i < hi; i++ ){
            if( A[ i-1 ] > A[ i ] ) //若逆序，则
            swapswap( A[ i-1 ], A[ last = i ] );
        }
    }
}


#endif