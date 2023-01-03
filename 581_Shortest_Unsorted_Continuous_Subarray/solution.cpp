class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*if(nums.size()==1)return 0;
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        int i=0;
        int j=nums.size()-1;
        bool foundi=0,foundj=0;
        while((foundi!=1 or foundj!=1) and (i<nums.size()-1 and j>=0))
        {
            if(copy[i]==nums[i]){
                i++;
            }
            else{
                foundi=1;
            }
            if(copy[j] == nums[j]){
                j-=1;
            }
            else{
                foundj=1;
            }
        }
        int ans=j-i+1;
        if(ans<0)
            return 0;
        else
            return ans;*/
        int minn=INT_MAX,maxx=INT_MIN;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < nums[i-1])
            {
                minn=min(minn,nums[i]);
            }
        }
        for(int j=nums.size()-2;j>=0;j--)
        {
            if(nums[j] > nums[j+1])
            {
                maxx=max(maxx,nums[j]);
            }
        }
        int open=0,close=0;
        for(int i=0;i<nums.size();i++)
        {
            if(minn < nums[i])
            {
                open=i;
                break;
            }
        }
        for(int j=nums.size()-1;j>=0;j--)
        {
            if(maxx>nums[j])
            {
                close=j;
                break;
            }
        }
        int ans=close-open;
        return ans==0?0:ans+1;
    }
};