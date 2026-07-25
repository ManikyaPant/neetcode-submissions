class Solution {
public:
    int getSum(int a, int b) {
        //this we can do using bitwise operations
        int ans = 0;
        int c = 0;
        for(int i=0;i<32;i++){
            int b1 = (a>>i)&1;
            int b2 = (b>>i)&1;
            int b = (b1 + b2 +c)%2;
            c = (b1 + b2 + c)/2;
            if(b){
                ans+= (1<<i);
            }
        } 
        return ans;
    }
};
