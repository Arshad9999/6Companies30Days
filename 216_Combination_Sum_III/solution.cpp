class Solution {
public:
    vector<vector<int>>res;
    void solve(int k,int n,vector<int>&ans,unordered_map<int,int>action_space)
    {
        //Base Case
        if(k>n or n<0)return;
       
        if(ans.size() == k)
        {
            int sum=0;
            for(int i=0;i<ans.size();i++)
            {
                sum+=ans[i];
            }

            if(sum==n)
            {
                // cout<<"executed"<<endl;
                // sort(ans.begin(),ans.end());
                // s.insert(ans);
                res.push_back(ans);
                return;
            }
            else return;
            
        }
       
        //Recursive calls
        
        
       
        for(int i=1;i<=9;i++)
        {
            
            if(action_space[i] == 1)
            {
                //pick
                action_space[i] = 0;
                ans.push_back(i);
               
                solve(k,n,ans,action_space);
                ans.pop_back();
               


            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         unordered_map<int,int>action_space;
         for(int i=1;i<=9;i++)
        {
            action_space[i]=1;
        }
        // set<vector<int>>s;
        vector<int>ans;
        solve(k,n,ans,action_space);
        // cout<<s.size()<<endl;
        // vector<vector<int>>res;
        // for(auto it=s.begin();it!=s.end();it++)
        // {
        //     res.push_back(*it);
        // }
        return res;
    }
};