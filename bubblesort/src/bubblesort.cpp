#include "bubblesortA.h"
#include "bubblesortB.h"
#include "bubblesortC.h"
#include<iostream>

using namespace std;

int main()
{
    double A[5] = {1.2, 4.3, 3.5, 5.4, 3.2};
    bubblesortC(A, 0, 5);
    for (int j = 0; j < 5; j++){
        cout << A[j] << endl;
    }    
}