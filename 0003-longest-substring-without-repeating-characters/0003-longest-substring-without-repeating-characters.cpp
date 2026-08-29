class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxCount = 0;

        unordered_set<char> ans;

        while (j < s.length()) {

            if (ans.find(s[j]) == ans.end()) {
                ans.insert(s[j]);

                maxCount = max(maxCount, j - i + 1);

                j++;
            }
            else {
                ans.erase(s[i]);
                i++;
            }
        }

        return maxCount;
    }
};