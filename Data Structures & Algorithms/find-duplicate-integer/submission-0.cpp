class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //O(n) space solution 
        int n = nums.size()-1;
        vector < int > found(n+1, 0) ;
        for(auto num : nums) {
            if(!found[num]){
                found[num] = 1;
            }
            else return num ;
        }
    }
};
