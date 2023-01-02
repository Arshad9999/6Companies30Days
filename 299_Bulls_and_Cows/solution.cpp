
class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int bulls=0;int cows=0;
        unordered_map<int,int>mp;
        //storing all original digits
        for(int i=0;i<n;i++)
        {
            mp[secret[i] - '0']+=1;
            
        }
vector<bool>visited(guess.size());
        for(int i=0;i<n;i++)
        {
          
          if(secret[i] == guess[i]){
                mp[secret[i] - '0']-=1;
                bulls+=1;
                visited[i]=1;
            }  
            

        }
        
        for(int i=0;i<n;i++)
        {
            if(mp[guess[i] - '0']!=0 and visited[i]==0)
            {
                cows+=1;
                mp[guess[i] - '0']-=1;
            }
        }
        string ans="";
            ans=to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};