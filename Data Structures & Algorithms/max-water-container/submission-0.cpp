class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = height.size() - 1;
        int l = 0, m = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                m = max (m, (r-l) * height[l]);
                ++l;
            } else {
                m = max (m, (r-l) * height[r]);
                --r;
            }
        }
        return m;
    }
};