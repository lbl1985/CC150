// Utility functions for printing and generating data
// Author: Binlong Li   12/08/2015
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <time.h>       // time
#include <stdlib.h>     // srand, rand
#include "CLinkedList.h"
#include <vector>

using namespace std;

typedef unsigned int uint;

#define S_OK 0
#define S_OverFlow -1
#define S_Invalid -2
#define S_Res int

// List of major entries for each question
// Chapter 2
int C2Q5();
int C2Q5_part2();
int C2Q6();
int C2Q7();
// Chapter 3
int C3Q1();
int C3Q2();
int C3Q3();
int C3Q4();
int C3Q5();
int C3Q6();
int C3Q7();
//Chapter 4 Tree
int BinaryTreeTest();
int C4Q1();
int C4Q2();
int C4Q3();
int C4Q4();
int C4Q5();

// Chapter 10 Sort
int bubbleSortTest();
int quicksortTest();

// leetCode
int Q001_TwoSum();
int Q116_PopulatingNextRightPointersinEachNode();
int Q130_SurroundedRegions();
int Q162_FindPeakElement();
int Q326_PowerOfThree();
int Q324_WiggleSortII();
int Q328_OddEvenLinkedList();
int Q329_LongestIncreasingPathInAMatrix();


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
void print2DMat(const vector< vector<T> >& mat){
    size_t height = mat.size();
    size_t width  = mat[0].size();
    for(size_t i = 0; i < height; i++ ){
        for(size_t j = 0; j < width; j++){           
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
void generateRandomValue2D(T** arr, uint rows, uint cols, T maxValue)
{
    srand(uint(time()));

    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            arr[i][j] = rand() % maxValue;
        }
    }
}

template<class T>
T generateRandomValue(T minValue, T maxValue)
{
    //time_t* t = new time_t();
    //srand(uint(time(t)));
    return rand() % maxValue + minValue;
}

// convert linked list to number for Ascend order
template<class T>
T linkedListToNumAscOrder(const Node<T>* head)
{

    if (nullptr == head) {
        return -1;
    } else {
        T num = 0;
        int count = 0;
        while (head) {
            num += (T)(head->data * pow(10, count++));
            head = head->next;
        }
        return num;
    }        
}

template<class T>
T linkedListToNumDesOrder(const Node<T>* head)
{
    if (nullptr == head) {
        return -1;
    } else {
        size_t s = head->size();
        T num = 0; 
        while (s) {
            num += head->data * (T)(pow(10, --s));
            head = head->next;
        }
        return num;
    }
    
}

#endif