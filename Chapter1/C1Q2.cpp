// Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.
#include <iostream>

void reverse(char* s)
{
    if (s == nullptr)
        return;
    int len = strlen(s);
    char temp;
    // swap the characters in the string
    for (int i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

//void reverse(char* s)
//{
//    if (s == nullptr)
//        return;
//
//    char* end = s;
//    while (*++end) {
//    }
//    --end;
//
//    char temp;
//    while (s < end) {
//        temp = *s;
//        *s++ = *end;
//        *end-- = temp;
//    }
//}

int main()
{
    char s[] = "hello world";
    printf("Org String is: %s\n", s);
    reverse(s);
    printf("New String is: %s\n", s);
    return 0;
}