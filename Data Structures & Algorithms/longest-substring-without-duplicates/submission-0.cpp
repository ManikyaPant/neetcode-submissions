class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map < char, int> mp;
        int n = s.length() ;
        int i=0, j=0;
        int ans =0;
        while(j<=i && i<n){
            mp[s[i]]++;
            while(mp.size() != (i-j+1) && j<=i){
                char c = s[j];
                mp[c]--;
                if(!mp[c]) mp.erase(mp.find(c));
                j++;
            }
            ans = max(ans , i-j+1);
            i++;
            

        }
        return ans;
    }
};
