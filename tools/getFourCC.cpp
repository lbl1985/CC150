// Print out FOURCC
#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned int uint32_t;

const bool isDebug = false;

const uint32_t maxVal = -1;

int main(int argc, char* argv[])
{
    uint32_t tmp = 0;
    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++) {
        if (isDebug) {
            printf("%c", argv[1][i]);
        }        
        tmp += (argv[1][i] - '0') * (uint32_t)(pow(double(10), double(n - i- 1)));
    }
    if (isDebug) {
        cout << endl << tmp << endl;
    }

    if (tmp == maxVal) {
        printf("%s is ANYFORMAT", argv[1]);
    } else {
        printf("%s is: %c%c%c%c", argv[1], tmp & 0xff, tmp>>8 & 0xff, tmp>>16 & 0xff, tmp>>24 & 0xff);
    }    

    return 0;
}