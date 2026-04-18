class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        vector<int> cnt(26);
        int st = 0, ed = 0, maxct = 0;
        while (ed < len) {
            cnt[s[ed] - 'A']++;
            maxct = max (maxct, cnt[s[ed] - 'A']);
            if (ed - st + 1 > maxct + k) {
                cnt[s[st] -'A']--;
                st++;
            }
            ed++;
        }
        return ed - st;
    }
};