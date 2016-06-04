vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n <= 0) return res;
    if (n == 1) {
        string tmp = "()";
        res.push_back(tmp);
        return res;
    }
    vector<string> r = generateParenthesis(n-1);
    unordered_map<string, int> dict;
    for(int i = 0; i < r.size(); i++) {
        string s = r[i];
        vector<string> t{"()" + s, "(" + s + ")", s + "()"};
        // detect complete parenthesis
        stack<int> leftP;
        int index;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '(') {
                leftP.push(j);
            }
            if(s[j] == ')') {
                index = leftP.top();
                leftP.pop();
            }
            if(leftP.empty()) {
                string temp;
                temp = s.substr(0, index - 0) + "(" + s.substr(index, j - index + 1) + ")" + s.substr(j+1, s.size() - j);
                t.push_back(temp);
            }
        }
        for(int j = 0; j < t.size(); j++) {
            if(dict.count(t[j]) == 0) {
                dict[t[j]] = 1;
                res.push_back(t[j]);
            }
        }
    }
    return res;
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    helper(result, n, n, "");
    return result;
}
void helper(vector<string>& result, int m, int n, string temp){
    if(m == 0 && n == 0){
        result.push_back(temp);
        return;
    }
    if(m>0)
        helper(result, m-1, n, temp+'(');
    if(m<n)
        helper(result, m, n-1, temp+')');
}