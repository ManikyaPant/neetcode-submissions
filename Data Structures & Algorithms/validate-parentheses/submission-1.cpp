class Solution {
public:
    bool isValid(string s) {
        stack < char> st;
        int cnt1=0,cnt2=0,cnt3=0;
        for(auto c:s){
            if(c=='[' || c=='{' || c=='('){
                st.push(c);
            }

            if(c==']'){
                if(!st.empty() && st.top() == '[')
                st.pop();
                else return false;
            }
            if(c=='}'){
                if(!st.empty() && st.top() == '{')
                st.pop();
                else return false;
            }if(c==')'){
                if(!st.empty() && st.top() == '(')
                st.pop();
                else return false;
            }
            
        }
        return st.size() == 0;
    }
};
