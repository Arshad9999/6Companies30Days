class Solution {
public:
    bool check(vector<int>adj[],vector<bool>&visited,vector<bool>&dfs_visited,int current)
    {
        visited[current]=1;
        dfs_visited[current]=1;
        for(int i=0;i<adj[current].size();i++)
        {
            if(!visited[adj[current][i]])
            {
                if(check(adj,visited,dfs_visited,adj[current][i]))return 1;
            }
            else if(dfs_visited[adj[current][i]])
            {
                return 1;
            }
        }
        dfs_visited[current]=0;
        return 0;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N=numCourses;
        vector<int>adj[N];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // for(int i=0;i<N;i++)
        // {
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;
        vector<bool>visited(N);
        vector<bool>dfs_visited(N);

        for(int i=0;i<N;i++)
        {
            if(!visited[i])
            {
                if(check(adj,visited,dfs_visited,i))return 0;
            }
        }
        return 1;
    }
};