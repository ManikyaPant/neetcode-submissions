class Solution {
public:
    void expand( int&l , int&r , string&s, int&cnt){
        int n = s.length();
        while(l>=0 && r<n && s[l]==s[r]) {
                l-- ; r++;
                cnt++;
        }
    }


    int countSubstrings(string s) {
        int n = s.length();
        // considering every index as an odd centre
        int maxi = 0;
        // string ans = "";
        int cnt=0;
        for(int i=0;i<n;i++){
            // this is for odd 
            int l = i , r = i;
            expand(l , r , s , cnt); 
            cout << cnt << endl;
        }

        for(int i=0;i<n-1;i++){
            int l = i, r = i+1;
            expand(l ,r ,s ,cnt);
        }
        return cnt;     
    }
};
