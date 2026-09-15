class Solution {
public:
    /*bool pattern(vector<int>& nums,int i,vector<vector<int>>& dp,int target)
    {
        if(target==0) return true;
        if(i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool pick=false;
        if(target>=nums[i]) 
        {
            //u can pick
            pick=pattern(nums,i+1,dp,target-nums[i]);
        }
        //not pick
        bool notpick=pattern(nums,i+1,dp,target);
        return dp[i][target]=pick || notpick;
    }*/
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<bool>> dp(nums.size()+1 ,vector<bool> (target+1,false));
        //return pattern(nums,0,dp,target);
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=1;j<=target;j++)
            {
                bool pick=false;
                if(j>=nums[i]) 
                {
                    //u can pick
                    pick=dp[i+1][j-nums[i]];
                }
                //not pick
                bool notpick=dp[i+1][j];
                dp[i][j]=pick || notpick;
            }
            //dp[i][j]=pick || notpick;
        }
        return dp[0][target];
    }
};