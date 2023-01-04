class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
       /* map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]+=1;
        }
        // for(auto it=freq.begin();it!=freq.end();it++)
        // {
        //     cout<<it->first<<endl;
        // }
        int ans=0;
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            bool found=0;
            for(int j=0;j<numsDivide.size();j++)
            {
                if(numsDivide[j]%it->first!=0)
                {
                    // cout<<it->first<<" ";
                    ans+=it->second;
                    found=1;
                    break;
                }
            }
            if(found==0)
            {
                break;
            }

        }
        if(ans==nums.size())return -1;
        return ans;*/
        // unordered_map<int,int>freq;
        // for(int i=0;i<nums.size();i++)
        // {
        //     freq[nums[i]]+=1;
        // }
        int GCD=numsDivide[0];
        for(int i=0;i<numsDivide.size();i++)
        {
            GCD=__gcd(GCD,numsDivide[i]);

        }
        int ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(GCD%nums[i]==0)
            {
                ans=i;
                break;
            }
            
        }
        // ans+=1;
        return ans;

    }

};