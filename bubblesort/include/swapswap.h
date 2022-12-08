#ifndef SWAPSWAP_H
#define SWAPSWAP_H

template<typename T> 
void swapswap(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}


#endif