class Solution {
public:
    int minpath(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        if(i>=grid.size() || j>=grid[0].size() ) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=minpath(i+1,j,grid,dp);
        int right=minpath(i,j+1,grid,dp);
        return dp[i][j]=grid[i][j]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp( grid.size()+1 , vector<int> ( grid[0].size()+1 , -1));
        return minpath(0,0,grid,dp);
    }
};