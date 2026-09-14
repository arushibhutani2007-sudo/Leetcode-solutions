class Solution {
public:
    int minsum(int i , int j , vector<vector<int>>& triangle , vector<vector<int>>& dp)
    {
        if(i==triangle.size()-1) return triangle[i][j];
        //if(j>=triangle[i].size()) return INT_MAX;
        if(dp[i][j]!=INT_MAX) return dp [i][j];
        int noplusone=minsum(i+1,j,triangle,dp);
        int plusone=minsum(i+1,j+1,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(noplusone,plusone);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return minsum(0,0,triangle,dp);
    }
};