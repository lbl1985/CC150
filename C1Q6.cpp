// 1.6 Given an image represented by an NxN matrix, where each pixel in the image
// is 4 bytes, write a metho to rotate the image by 90 degrees.Can you do this in place ?

#include <iostream>
#include <vector>

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

void rotateMat(int arr[][5], uint s)
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
        printMat(arr);

    }

    printf("\n This rotated matrix is: \n");
    printMat(arr);
    
}

int main()
{
    int arr[5][5] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 } };
    printMat(arr);
    rotateMat(arr, 5);
    return 0;
}