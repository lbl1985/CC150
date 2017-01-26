class Solution {
public:
    int reverse_real(int x) {
        int y = 0;
        while(x != 0) {
            if(y > INT_MAX / 10) {
                return 0;
            }
            y *= 10;
            y += x % 10;
            
            x /= 10;
        }
        return y;
    }
    int reverse(int x) {
        if(x == 0 || x == INT_MIN || x == INT_MAX) return 0;
        if(x < 0) {
            int y = reverse_real((-x));
            return -y;
        } else {
            int y = reverse_real(x);
            return y;
        }
    }
};