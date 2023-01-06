class Solution {
public:
    int trailingZeroes(int n) {
        int x=n;
        int ans=0;
        int idx=1;
        while(1)
        {
            int rem=floor(n/pow(5,idx++));
            ans+=rem;
            if(rem==0)break;
        }
        return ans;
    }
};