class Solution {
public:
    int hammingDistance(int x, int y) {
         int ans = x ^ y;
         int cnt = 0;

        while (ans != 0) {
            cnt += ans & 1;
            ans = ans >> 1;
        }
        return cnt;

    }
};