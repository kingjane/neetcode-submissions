class Solution {
public:
    int findRow(vector<vector<int>>& matrix, int right, int target) {
        int l = 0, r = right;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (matrix[m][0] <= target) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (target >= matrix[r][0]) {
            return r;
        } else if (target < matrix[l][0]) {
            return -1;
        } else
        return l;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x  = matrix.size();
        int row = findRow(matrix, x - 1, target);
        cout << "row:" << row << endl;
        if (row < 0) return false;
        int l = 0, r = matrix[row].size() - 1;       
        while (l <= r) {
            int m = (l + r) / 2;
            if (matrix[row][m] == target)
                return true;
            else if (target < matrix[row][m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};