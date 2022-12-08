#ifndef BUBBLESORTB_H
#define BUBBLESORTB_H

#include "swapswap.h"
template<typename T> 
void bubblesortB(T A[], int lo, int hi){
    for( bool sorted = false; sorted = !sorted; hi-- )
      for( int i = lo+1; i < hi; i++ )
         if( A[ i-1 ] > A[ i ] ) //若逆序，则
            swapswap( A[ i-1 ], A[ i ] ), sorted = false;
}

#endif