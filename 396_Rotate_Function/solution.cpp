class Solution {
public:
    int F(int k,vector<int>&nums,int sum)
    {
        if(k == 0)
        {
            int ans=0;
         for(int i=0;i<nums.size();i++)
         {
             ans+=i*nums[i];
         }
         return ans;
        }
        int F_k_1=F(k-1,nums,sum) ;
        int F_k=F_k_1 + sum - (nums.size()*(nums[nums.size()-k]));
        return F_k;
    }
    int F_mem(int k,vector<int>&nums,int sum,vector<int>&dp)
    {
        if(k == 0)
        {
            int ans=0;
         for(int i=0;i<nums.size();i++)
         {
             ans+=i*nums[i];
         }
         return ans;
        }
        if(dp[k] == -1)
        {
            int F_k_1=F_mem(k-1,nums,sum,dp) ;
            int F_k=F_k_1 + sum - (nums.size()*(nums[nums.size()-k]));
            dp[k]=F_k;
        }
        return dp[k];
    }
    int F_tab(int k,vector<int>&nums,int sum,vector<int>&dp)
    {
        int init_sum=0;

        for(int i=0;i<nums.size();i++){
            init_sum+=(nums[i])*i;
        }
        dp[0]=init_sum;
        int res=dp[0];
        for(int i=1;i<=k;i++)
        {
            dp[i] = dp[i-1]+sum-nums.size()*(nums[nums.size()-i]);
            res=max(res,dp[i]);
        }
        return res;
        
    }
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        int res=INT_MIN;
        vector<int>dp(nums.size(),-1);
        // for(int i=0;i<nums.size();i++)
        // {
        //     int y=F_mem(i,nums,sum,dp);
        //     // cout<<"i="<<i<<y<<" "<<endl;
        //     res=max(res,y);
        // }
        return F_tab(nums.size()-1,nums,sum,dp);
    }
};