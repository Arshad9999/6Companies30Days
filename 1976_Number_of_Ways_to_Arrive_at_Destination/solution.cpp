class Solution {
public:
    typedef  long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
       
        //dijkstra's algo along with tracing the paths
        vector<ll>ways(n,0);
        vector<ll>times(n,LONG_MAX);
        times[0]=0;
        ways[0]=1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        ll mod = (1e9+7); 
        while(!pq.empty())
        {
            ll time=pq.top().first;
            ll Node=pq.top().second;
            pq.pop();
            for(auto it:adj[Node])
            {
                ll adjNode=it.first;
                ll weight=it.second;
                //first time discovering a path with time this short!
                 ll tot=(time+weight);
                if(tot < times[adjNode])
                {
                    times[adjNode] = tot;
                    ways[adjNode]=ways[Node];//since we travelled from Node to adjNode
                    pq.push({times[adjNode],adjNode});
                    // cout<<"executed this";
                }
                else if(tot == times[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[Node])%mod;
                    // cout<<"executed";
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};
