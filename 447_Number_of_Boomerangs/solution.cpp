class Solution {
public:
    int dist(vector<int>p1,vector<int>p2)
    {
        int x1=p1[0];
        int x2=p2[0];
        int y1=p1[1];
        int y2=p2[1];

        int d = pow((x1-x2),2) + pow((y1-y2),2);
        return d;
        


    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        for(auto i:points)
        {
            unordered_map<int,int>mp;
            for(auto j:points)
            {
                if(i==j)continue;
                int d=dist(i,j);
                if(mp.find(d)!=mp.end())ans+=mp[d]*2;
                mp[d]+=1;

            }
            
            /*for(auto it:mp)
            {
            cout<<it.first<<":"<<it.second<<endl;
            }*/
        }
        
        return ans;
    }
};