class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(grid[i][j]) {
            grid[i][j] = 0;
            int left = 0, right = 0, above = 0, below = 0;
            if (i - 1 >= 0) {
                above = dfs(grid, i-1, j);
            }
            if (i + 1 < grid.size()) {
                below = dfs(grid, i + 1, j);
            }
            if (j - 1 >= 0) {
                left = dfs(grid, i, j - 1);
            }
            if (j + 1 < grid[0].size()) {
                right = dfs(grid, i, j + 1);
                cout << "right: " << right << endl;
            }
            int sum = (left + right + above + below + 1);
            cout << i << ", " << j << ", sum: " << sum << endl;
            return sum;
        } else {
            return 0;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    int area = dfs(grid, i, j);
                    maxArea = max(area, maxArea); 
                }
            }
        }
        return maxArea;
    }
};