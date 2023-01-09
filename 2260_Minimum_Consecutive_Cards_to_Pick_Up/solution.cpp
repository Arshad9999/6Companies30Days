class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        //brute force
        /*vector<int>lens;
        for(int i=0;i<cards.size();i++)
        {
            unordered_map<int,int>mp;
            mp[cards[i]]+=1;
            for(int j=i+1;j<cards.size();j++)
            {
                if(mp.find(cards[j])!=mp.end())
                {
                    int len=j-i+1;
                    lens.push_back(len);
                }
            }
           
        }
        int res=-1;
        if(lens.size()!=0)res=*min_element(lens.begin(),lens.end());
         cout<<res<<endl;
         return res;*/
        //better
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<cards.size();i++)
        {
            mp[cards[i]].push_back(i);
        }
        /*for(auto it=mp.begin();it!=mp.end();it++)
        {
            cout<<it->first<<":";
            for(int i=0;i<it->second.size();i++)
            {
                cout<<it->second[i]<<" ";
            }cout<<endl;
        }*/
        int minlen=INT_MAX;  
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second.size()<2)continue;

            vector<int>occs=it->second;
            
            // int len=0;
            for(int i=1;i<occs.size();i++)
            {
                int len=occs[i]-occs[i-1]+1;
                minlen=min(minlen,len);

            }
        }
        if(minlen==INT_MAX)return -1;
        return minlen;
    }
};