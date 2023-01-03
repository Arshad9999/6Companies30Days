class Solution {
public:
   
    /*
    int solve(vector<int>nums,int idx,int prev)
    {
        //base
        // vector<int>ans; 
        if(idx==nums.size()){
          
           return 0;
        }
       
       //recurrence
       int dont = solve(nums,idx+1,prev);
       int take= 0;
       if(prev==-1 or nums[idx]%nums[prev]==0)
       {
           
         
           take=1+solve(nums,idx+1,idx);
       }
        return max(take,dont);
        

    }
    int solve_mem(vector<int>&nums,int idx,int prev,vector<vector<int>>&dp)
    {
         if(idx==nums.size()){
          
           return 0;
        }
        if(dp[idx][prev+1] == -1)
        {
                int dont = solve_mem(nums,idx+1,prev,dp);
                int take= 0;
                if(prev==-1 or nums[idx]%nums[prev]==0)
                {
                take=1+solve_mem(nums,idx+1,idx,dp);
                }
                    dp[idx][prev+1] = max(take,dont);
        }
        return dp[idx][prev+1];

    }
    int solve_tab(vector<int>&nums,vector<vector<int>>&dp)
    {
        dp[nums.size()-1][nums.size()-1]=0;
        for(int idx=nums.size()-1;idx>=0;idx--)
        {
            for(int prev=idx-1;prev>=-1;prev-=1)
            {
                int dont = solve_mem(nums,idx+1,prev,dp);
                int take= 0;
                if(prev==-1 or nums[idx]%nums[prev]==0)
                {
                take=1+solve_mem(nums,idx+1,idx,dp);
                }
                dp[idx][prev+1] = max(take,dont);

            }
        }
        return dp[0][0];
    }
    */
    int solve_opt(vector<int>&nums,vector<int>&dp,vector<int>&hash)
    {
        int maxi=-1;
        int maxidx=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    // dp[i]=max(1+dp[j],dp[i]);
                    if((1+dp[j]) > dp[i])
                    {
                        hash[i]=j;
                        dp[i]=1+dp[j];
                    }
                }
            }
            if(dp[i] > maxi)
            {
                maxi=dp[i];
                maxidx=i;
            }
            // cout<<maxi<<"\n";
            // maxi=max(maxi,dp[i]);
        }
        return maxidx;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 1)return nums;
        vector<int>copy=nums;
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        vector<int>dp(nums.size(),1);
        vector<int>hash(nums.size(),0);
        sort(copy.begin(),copy.end());
        int maxidx=solve_opt(copy,dp,hash);//<<endl;
        // cout<<"{";
        // for(int i=0;i<hash.size();i++)
        // {
        //     cout<<dp[i]<<" ";
        // }cout<<"}";
        // cout<<endl;
        // vector<int>ans1;
        vector<int>ans;
        int i=maxidx;
        // cout<<dp[maxidx]<<endl;
        ans.push_back(copy[maxidx]);
        while(ans.size()!=dp[maxidx])
        {
            ans.push_back(copy[hash[i]]);
            i=hash[i];
        }
        
        return ans;
    }
};