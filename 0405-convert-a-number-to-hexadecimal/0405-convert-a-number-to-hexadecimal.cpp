class Solution {
public:
string toHex(int num) {
if (num == 0) return "0";


    unsigned int n = num;
    string ans = "";

    while (n != 0) {
        int digit = n & 15;

        char ch;
        if (digit <= 9) {
            ch = '0' + digit;
        } else {
            ch = 'a' + (digit - 10);
        }

        ans.push_back(ch);
        n = n >> 4;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


};
