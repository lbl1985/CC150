// 1.6 Given an image represented by an NxN matrix, where each pixel in the image
// is 4 bytes, write a metho to rotate the image by 90 degrees.Can you do this in place ?

#include <iostream>
#include <vector>
//#include "..\utils.h"

typedef unsigned int uint;

#define SIZE 5

void printMat(int arr[][5])
{
    for (uint i = 0; i < 5; i++) {
        for (uint j = 0; j < 5; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

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

void rotateMat(int** arr, uint s)
{
    int t;
    for (uint loop = 0; loop < s / 2; loop++) {
        int lastIndex = s - loop - 1;
        int runLength = s - 2 * loop - 1;
        for (int index = 0; index < runLength; index++) {
            t = arr[loop][loop + index];
            arr[loop][loop + index] = arr[loop + index][lastIndex];
            arr[loop + index][lastIndex] = arr[lastIndex][lastIndex - index];
            arr[lastIndex][lastIndex - index] = arr[lastIndex - index ][loop];
            arr[lastIndex - index][loop] = t;
        }

        printf("\n This rotated matrix after loop %d is: \n", loop);
        print2DMat<int>(arr, s, s);

    }

    printf("\n This rotated matrix is: \n");
    print2DMat<int>(arr, s, s);
    
}



int main()
{
    int arr[5][5] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 } };
    // Dynamically create a 2D array
    int** arrMat = new int*[5];
    for (int i = 0; i < 5; i++) {
        arrMat[i] = new int[5];
    }

    int count = 10; 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arrMat[i][j] = ++count;
        }
    }

    printf("dynamic allocation matrix is: \n");
    print2DMat<int>(arrMat, 5, 5);

    rotateMat(arrMat, 5);
    return 0;
}