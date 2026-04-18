class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            cout << l <<"," << r <<endl;
            int mid = (l+r)/2;
            int hour = 0;
            for (int i = 0; i< piles.size(); i++) {
                hour += (piles[i] + (mid-1))/mid;
            }
            if (hour > h) {
                l = mid+1;
            } else {
                r = mid;
            } 
        }
        cout << l << ", " << r <<endl;
        return l;
    }
};