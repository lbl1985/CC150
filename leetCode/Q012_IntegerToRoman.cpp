string intToRoman(int num) {
    string res;
    if (num == 0 || num > 3999) return res;
    char c[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int q[7] = {1000, 500, 100, 50, 10, 5, 1};
    int n = 0;
    while (num != 0) {
        for(int i = 0; i < 7; i++) {
            
            int d = q[i];
            int delta = (i % 2 == 0) ? 2 : 1;
            int b = q[i + delta];
            if (num >= d){
                n = num / d;
                for(int r = 0; r < n; r++) {
                    res.append(&c[i], 1);
                }
                num -= n * d;
                break;
            } else if (num >= d - b) {
                res.append(&c[i+delta], 1);
                res.append(&c[i], 1);
                num -= d - b;
                break;
            }
            
        }
    }
    return res;
}