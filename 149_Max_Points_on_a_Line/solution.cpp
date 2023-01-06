class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)return 1;
        int maxx=2;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<double,int>mp;
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=0;j<points.size();j++)
            {
                if(j!=i)
                {int x2=points[j][0];
                int y2=points[j][1];
                mp[atan2(x1-x2,y1-y2)]+=1;}
            }
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                maxx=max(maxx,it->second+1);
            }
        }
        
        

        return maxx;

    }
};