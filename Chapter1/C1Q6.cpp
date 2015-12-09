// 1.6 Given an image represented by an NxN matrix, where each pixel in the image
// is 4 bytes, write a metho to rotate the image by 90 degrees.Can you do this in place ?

#include <iostream>
#include <vector>
#include "..\utils.h"

typedef unsigned int uint;

#define SIZE 6

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
    // Dynamically create a 2D array
    int** arrMat = new int*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arrMat[i] = new int[SIZE];
    }

    int count = 10; 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arrMat[i][j] = ++count;
        }
    }

    printf("dynamic allocation matrix is: \n");
    print2DMat<int>(arrMat, SIZE, SIZE);

    rotateMat(arrMat, SIZE);
    return 0;
}