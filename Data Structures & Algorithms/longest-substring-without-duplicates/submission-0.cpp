class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> charac_set;
        int res = 0, len = 0;
        int start = 0, end = 0;
        while (end < s.size()) {
            if (!charac_set.contains(s[end])) {
                charac_set.insert(s[end]);
                end++;
                len++;
            } else {
                res = max(res, len);               
                while(s[start] != s[end]) {
                    charac_set.erase(s[start]);
                    start++;
                    len--;
                }
                start++;
                end++;
            }
        }
        res = max(res, len);
        return res;
    }
};