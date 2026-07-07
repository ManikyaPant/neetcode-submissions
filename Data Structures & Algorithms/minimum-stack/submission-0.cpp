class MinStack {
public:
    stack <int> st;
    stack <int> min_st;
    MinStack() {
        
    }
    
    void push(int val) {
      if(!st.empty()) {
        st.push(val);
        if(min_st.top() > val){
            min_st.push(val);
        }
        else{
           min_st.push(min_st.top()) ;
        }
      } 
      else{
        st.push(val);
        min_st.push(val);
      }
    }
    
    void pop() {
       st.pop();
       min_st.pop(); 
    }
    
    int top() {
       return st.top(); 
    }
    
    int getMin() {
       return min_st.top(); 
    }
};
