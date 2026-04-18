class Solution {
public:
    int rob(vector<int>& nums) {
        int pp = 0, p = 0;
        for(auto n : nums) {
            int curr = max( n+ pp, p);
            pp = p;
            p = curr;
        }
        return p;
    }
};