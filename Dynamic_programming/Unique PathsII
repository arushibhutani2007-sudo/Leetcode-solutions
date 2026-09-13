class Solution {
public:
    int rec(vector<vector<int>>& obstacleGrid , int i , int j , vector<vector<int>>& dp)
    {
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1) 
        {
            return 1;
        }
        //if(obstacleGrid[i][j]==1) return 0;
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size()) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=rec(obstacleGrid,i+1,j,dp)+rec(obstacleGrid,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1) return 0;
        vector<vector<int>> dp(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,-1));
        return rec(obstacleGrid,0,0,dp);
    }
};