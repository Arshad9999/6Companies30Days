class Solution {
public:
    /*int solve(string s)
    {
        //Base Case
        if(s.size() == 3)
        {
            cout<<s<<endl;
            bool a=0,b=0,c=0;
            for(int i=0;i<3;i++)
            {
                if(s[i] == 'a'){
                    a=1;
                }
                if(s[i] == 'b'){
                    b=1;
                }
                if(s[i] == 'c'){
                    c=1;
                }
            }
            // cout<<"a= "<<a<<"b= "<<b<<"c= "<<c;
            if(a==1 and b==1 and c==1){
                // cout<<"exe";
                return 1;
            }
            else{
                // cout<<"exe2"<<endl;
                return 0;
            }

        }
        //Recurrence
        int rest=solve(s.substr(1));
        bool abc=0;
        bool a=0,b=0,c=0;
        int idx=-1;
        for(int i=0;i<s.size();i++)
        {
            if(abc==1)
            {
                idx=i-1;
                break;
            }
            if(s[i] == 'a')
            {
                a=1;
            }
            if(s[i] == 'b')
            {
                b=1;
            }
            if(s[i] == 'c')
            {
                c=1;
            }
            if(a==1 and b==1 and c==1)
            {
                abc=1;
            }
        }
        if(abc==1 and idx==-1)idx=s.size()-1;
        else if(abc!=1 and idx==-1)
        {
            idx=s.size();
        }
        
        int occs=s.size()-idx;
        // cout<<"rest = "<<rest<<endl;
        // cout<<"string s="<<s<<"rest = "<<rest<<"occs="<<occs<<endl;
        // cout<<"idx = "<<idx<<endl;
        return rest+occs;
    }*/
    
    int numberOfSubstrings(string s) {
        
        int ans=0;
        // int i=0;
        int j=0;
        int a=0,b=0,c=0;
        for(int i=0;i<s.size();i++)
        {
            if(a*b*c>0)
            {
                ans+=s.size()-j+1;
                if(s[i]=='a')a-=1;
                if(s[i]=='b')b-=1;
                if(s[i]=='c')c-=1;
                continue;
            }
            if(j==s.size())break;
            while(j<s.size() and a*b*c==0 )
            {
                if(s[j]=='a')a+=1;
                if(s[j]=='b')b+=1;
                if(s[j]=='c')c+=1;
                j+=1;
            }
            if(a*b*c>0)ans+=(s.size()-j+1);
                if(s[i]=='a')a-=1;
                if(s[i]=='b')b-=1;
                if(s[i]=='c')c-=1;
        }
        return ans;
    }
};