// Utility functions for printing and generating data
// Author: Binlong Li   12/08/2015
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <time.h>       // time
#include <stdlib.h>     // srand, rand
#include "CLinkedList.h"
#include <vector>
#include <string>

using namespace std;

#pragma warning( disable : 4819 )

typedef unsigned int uint;

#define S_OK 0
#define S_OverFlow -1
#define S_Invalid -2
#define S_Res int

#define JUDGE_RESULT(FUNC, INPUT) FUNC(INPUT) ? "true" : "false"
// List of major entries for each question
// Chapter 2
// int C2Q5();
// int C2Q5_part2();
// int C2Q6();
// int C2Q7();
// Chapter 3
// int C3Q1();
// int C3Q2();
// int C3Q3();
// int C3Q4();
// int C3Q5();
// int C3Q6();
// int C3Q7();
//Chapter 4 Tree
int BinaryTreeTest();
int BinaryTreeTest_prac();
int GraphTest();
// int C4Q1();
// int C4Q2();
// int C4Q3();
// int C4Q4();
// int C4Q5();

// Chapter 8 Recursion_DP
int fibonacciTest();

// Chapter 10 Sort
int bubbleSortTest();
int quicksortTest();
int mergesortTest();
int binarySearchTest();



// leetCode
// int Q001_TwoSum();
//int Q005_longest_palindromic_substring();
int Q006_zigzag_conversion();
// int Q021_Merge_Two_Sorted_Lists();
// int Q025_Reverse_Nodes_in_k_group();
// int Q045_JumpGameII();
// int Q050_Pow_x_n();
// int Q051_N_Queens();
// int Q058_LengthOfLastWord();
// int Q055_JumpGame();
// int Q116_PopulatingNextRightPointersinEachNode();
// int Q130_SurroundedRegions();
// int Q149_Max_Points_on_aline();
// int Q162_FindPeakElement();
// int Q179_LargestNumber();
// int Q326_PowerOfThree();
// int Q324_WiggleSortII();
// int Q328_OddEvenLinkedList();
// int Q329_LongestIncreasingPathInAMatrix();
// int Q331_verify_preorder_serialization_of_a_binary_tree();
// int Q338_CountingBits();
// int Q342_PowerOfFour();
// int Q343_IntegerBreak();
// int Q344_ReverseString();
// int Q345_Reverse_vowels_of_a_string();
// int Q347_TopKFrequentElements();
// int Q349_IntersectionOfTwoArrays();

// int Q337_HouseRobberIII();
// int Q336_Palindrome_pairs();
// int Q335_Self_Crossing();
// int Q334_Increasing_Triplet_Subsequence();
// int Q332_Reconstruct_Itinerary();
// int Q332_Coin_Change();
// int Q189_Rotate_Array();
// int Q321_Create_Maximum_Number();
// int Q216_CombinationSumIII();
// int Q219_Contains_DuplicateII();
// int Q054_SpiralMatrix();

// Exp
int constructChar();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(const vector<int>& arr);
void releaseList(ListNode* root);
void printListNodes(const ListNode* root);

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


template<class T>
void printVector(const vector<T>& vec){
    size_t len = vec.size();
    cout << " [";
    for(size_t i = 0; i < len; i++){
        cout << vec[i] << " ";
    }
    cout << "] ";
}

template<class T>
void printVector(const vector<vector<T>>& vec){
    int len = (int)vec.size();
    cout << " [";
    for(int i = 0; i < len; i++) {
        printVector<T>(vec[i]);
    }
    cout << "] ";
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