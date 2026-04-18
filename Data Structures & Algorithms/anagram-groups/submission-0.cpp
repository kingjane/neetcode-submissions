class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (const auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto iter = hash.begin(); iter != hash.end(); ++iter) {
            res.push_back(iter->second);
        }
        return res;
    }
};