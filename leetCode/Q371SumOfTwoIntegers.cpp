// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

// Example:
//  Given a = 1 and b = 2, return 3. 


class Solution {
public:
    int getSum(int a, int b) {
        int A = a & b;
        if ( A ){
            return getSum(a ^ b, (A << 1));
        }
        return a | b;
    }
};