// 1.4 Write a method to replace all spaces in  a string with '%20'.You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please us a character array so that you can perform this operation in place.)
// Example
// Input : "Mr John Smith    "
//        Output "Mr%20John%20Smith"

// 12/05/2015 comments: 
// This implementation is using pre-allocated dst instead of dynamically allocation memory. 
// In order to use dynamically allocation memory and allocation happens in main functin. 
// we may need to use smart pointer as pointer holder 
// This could be up to my next implementation. 

#include <iostream>

void replaceSpace(const char* src, char* dst)
{
    while (*src != '\0') {
        if (*src == ' ') {
            *dst++ = '%';
            *dst++ = '2';
            *dst++ = '0';
        } else {
            *dst++ = *src;
        }
        src++;
    }
    *dst++ = '\0';
}

int main()
{
    const char src[] = "Mr John Smith";
    char dst[256];
    printf("src string is: %s\n", src);
    replaceSpace(src, dst);
    printf("dst string is: %s\n", dst);
    return 0;
}