class Solution {
public:
    int characterReplacement(string s, int k) {
    int n = s.size();
    unordered_map<char, int> freq;    
    int maxFreq = 0;  
    int res = 0;
    
    int l = 0;   
    
    for (int r = 0; r < n; ++r) {
      
        freq[s[r]]++;
        
        maxFreq = max(maxFreq, freq[s[r]]);
        
        if (r-l+1 - maxFreq > k) {
            freq[s[l]]--;  
            ++l;           
        }

        res = max(res, r - l + 1);
    }
    
    return res;
    }
};
