// Write a program to find the n-th ugly number. 

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers. 

// Note that 1 is typically treated as an ugly number. 


class Solution {
public:
    bool checkAvail(const vector<unsigned long>& mullist, unsigned long num){
        bool res = false;
        for(int i = 0; i < 3; i++){
            if (mullist[i] == num){
                return true;
            }
        }
        return false;
    }
    void updateMin(const vector<unsigned long>& mullist){
        m_minVal = mullist[0];
        idx = 0;
        for(int i = 1; i < 3; i++){
            if(m_minVal > mullist[i]) {
                m_minVal = mullist[i];
                idx = i;
            }
        }
    }
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        vector<unsigned long> res;
        res.push_back(1);
        vector<unsigned long> primelist{2, 3, 5};
        vector<unsigned long> resIdx{0, 0, 0};
        vector<unsigned long> mullist(primelist);
        m_minVal = 2;
        idx = 0;
        for(int m = 2; m <= n; m++){
            res.push_back(m_minVal);
            bool avail = true;
            unsigned long val;
            while(avail){
                resIdx[idx]++;
                val = primelist[idx] * res[resIdx[idx]];
                avail = checkAvail(mullist, val);
            }
            mullist[idx] = val;
            updateMin(mullist);
        }
        return (int)res[n - 1];
    }
private:
    unsigned long m_minVal;
    int idx;
};