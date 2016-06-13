// Write a program to find the nth super ugly number. 

// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]  is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4. 

// Note:
//  (1) 1 is a super ugly number for any given primes.
//  (2) The given numbers in primes are in ascending order.
//  (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000. 


class Solution {
public:
    bool checkAvail(const vector<unsigned long>& mullist, unsigned long num){
        bool res = false;
        for(int i = 0; i < mullist.size(); i++){
            if (mullist[i] == num){
                return true;
            }
        }
        return false;
    }
    void updateMin(const vector<unsigned long>& mullist){
        m_minVal = mullist[0];
        idx = 0;
        for(int i = 1; i < mullist.size(); i++){
            if(m_minVal > mullist[i]) {
                m_minVal = mullist[i];
                idx = i;
            }
        }
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        vector<unsigned long> res;
        res.push_back(1);
        vector<unsigned long> primelist;
        for(int i = 0; i < primes.size(); i++){
            primelist.push_back(primes[i]);
        }
        vector<unsigned long> resIdx((int)primes.size(), 0);
        vector<unsigned long> mullist(primelist);
        m_minVal = primes[0];
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