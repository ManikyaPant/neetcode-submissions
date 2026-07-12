class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        int n = tokens.size();
        for(int i=0;i<n;i++){
           if(tokens[i].length() == 1 && !(isdigit(tokens[i][0]))) {
            // we know that its a operand 

            string c = tokens[i];
            int v1 = st.top(); st.pop();
            int v2 = st.top(); st.pop();
            if(c == "+"){
                st.push(v1+v2);
            }
            else if( c== "-"){
                st.push(v2-v1);
            } 
            else if(c== "*"){
                st.push(v1*v2);
            }
            else{
                st.push(v2/v1);
            }
           }
           else{
                st.push(stoi(tokens[i]));
           }
        }
        return st.top();
    }
};
