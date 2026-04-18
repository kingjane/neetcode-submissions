class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        char len;
        for (const auto &s: strs) {
            len = s.size();
            res += (len + s);
        }
        return res;
    }

    vector<string> decode(string s) {
        unsigned char len;
        vector<string> res;
        for (int i = 0; i< s.size(); i++) {
            len = s[i];
            cout << (unsigned int)len << endl;
            ++i;
            res.push_back(s.substr(i, len));
            i += (len - 1);
        }
        return res;
    }
};
