class Solution {
public:
    int rec(vector<vector<int>>& points, int day, int last,
            vector<vector<int>>& dp)
    {
        // Base condition
        if(day == 0)
        {
            int maxi = 0;

            for(int activity = 0; activity < 3; activity++)
            {
                if(activity != last)
                {
                    maxi = max(maxi, points[0][activity]);
                }
            }

            return maxi;
        }

        if(dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for(int activity = 0; activity < 3; activity++)
        {
            if(activity != last)
            {
                int curr = points[day][activity]
                         + rec(points, day-1, activity, dp);

                maxi = max(maxi, curr);
            }
        }

        return dp[day][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& points)
    {
        int n=points.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return rec(points, n-1, 3, dp);
    }
};