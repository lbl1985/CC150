// Utility functions for printing and generating data
// Author: Binlong Li   12/08/2015

#include <iostream>
#include <time.h>       // time
#include <stdlib.h>     // srand, rand

typedef unsigned int uint;

template<class T>
void print2DMat(T** mat, uint rows, uint cols)
{
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

template<class T>
void generateRandomValue2D(T** arr, uint rows, uint cols, T maxValue)
{
    srand(uint(time(NULL)));

    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            arr[i][j] = rand() % maxValue;
        }
    }
}