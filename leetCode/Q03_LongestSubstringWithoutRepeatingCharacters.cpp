// Given a string, find the length of the longest substring without repeating characters.

// Examples:

// Given "abcabcbb", the answer is "abc", which the length is 3.

// Given "bbbbb", the answer is "b", with the length of 1.

// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Subscribe to see which companies asked this question

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<string, bool> map;
        int longest = 0;
        int tmpLen = 0;
        int sz = (int)s.size();
        string tmp = "";
        unordered_map<string, bool>::iterator iter;
        for(int i = 0; i < sz; i++) {
            tmp = s.substr(i, 1);
            iter =  map.find(tmp);
            if(iter == map.end()) {
                tmpLen++;
                map[tmp] = true;
            } else {
                if(tmpLen > longest) {
                    longest = tmpLen;
                }
                tmpLen = 1;
                map.clear();
                map[tmp] = true;
                for(int j = i - 1; j >= 0; j--) {
                    string c = s.substr(j, 1);
                    if(c != tmp) {
                        tmpLen++;
                        map[c] = true;
                    } else {
                        break;
                    }
                }
            }
        } 
        if(tmpLen > longest) {
            longest = tmpLen;
        }
        return longest;
    }
};