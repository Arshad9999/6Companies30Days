class Solution {
public:
    
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/")
        {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                if(tokens[i] == "+")
                {
                    st.push(op1+op2);
                }
                else if(tokens[i] == "-")
                {
                    st.push(op2-op1);
                }
                else if(tokens[i] == "*")
                {
                    st.push(op1*op2);
                }
                else {
                    st.push(op2/op1);
                }
        }
        else{
            
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};