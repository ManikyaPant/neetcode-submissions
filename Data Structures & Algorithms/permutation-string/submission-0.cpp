class Solution {
public:
    bool contains(vector<int>& f1 , vector <int>&f2){
        for(int i=0;i<26;i++){
            if(!f1[i]) continue;
            if(f2[i] < f1[i]) return false ;
        
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        vector <int> fre1(26,0) , fre2(26,0); 
        for(auto c: s1) fre1[c-'a']++;
        // for(auto c: s2) fre2[c-'a']++;
        int i=0 ,j=0,n = s2.size();
        while(i<n){
            char c = s2[i];
            fre2[c-'a']++;
            while(i-j+1 >k && j<=i){
                fre2[s2[j]-'a']--;
                j++;
            }
            if(contains(fre1, fre2)){
                cout << i << " " << j << endl; 
                return true;
            }
            i++;
        }
        return false;
    }
};
