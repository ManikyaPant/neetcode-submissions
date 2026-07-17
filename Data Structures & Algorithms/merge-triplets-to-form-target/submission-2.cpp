class Solution {
    bool isEqual(vector<int>& t1  , vector<int>&t2) {
        return t1[0]==t2[0] && t1[1] == t2[1] && t1[2] == t2[2];
    }
    void merge(vector<int>& curr , vector<int>&t){
        curr[0] = max(curr[0],t[0] );
        curr[1] = max(curr[1],t[1] );
        curr[2] = max(curr[2],t[2] );
    }
    bool bigger(vector <int>&a , vector<int>&b){
        return a[0] > b[0] || a[1] > b[1] || a[2] >b[2];
    }
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    sort(triplets.begin(), triplets.end()); 
    vector <int> curr(3,0);
    for(auto triplet: triplets){
        if(bigger( triplet, target)) continue;
         merge(curr, triplet);
         cout << curr[0] << " " << curr[1] << " " << curr[2] << endl;
        if(isEqual(curr , target))  return true;
    }
    return false;
    }
};
