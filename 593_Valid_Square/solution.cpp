class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<vector<int>>st;
        st.insert(p1);
        st.insert(p2);
        st.insert(p3);
        st.insert(p4);
        if(st.size()<4)return 0;
        unordered_map<int,int>mp;
        int p1p2= pow((p2[1]-p1[1]),2) +   pow((p2[0]-p1[0]),2);mp[p1p2]++;
        int p2p3= pow((p3[1]-p2[1]),2) +   pow((p3[0]-p2[0]),2);mp[p2p3]++;
        int p3p4= pow((p3[1]-p4[1]),2) +   pow((p3[0]-p4[0]),2);mp[p3p4]++;
        int p4p1= pow((p4[1]-p1[1]),2) +   pow((p4[0]-p1[0]),2);mp[p4p1]++;
        int p4p2= pow((p4[1]-p2[1]),2) +   pow((p4[0]-p2[0]),2);mp[p4p2]++;
        int p1p3= pow((p3[1]-p1[1]),2) +   pow((p3[0]-p1[0]),2);mp[p1p3]++;

        if(mp.size()==2){
            return 1;
        }
        else return 0;
        
        
    }
};