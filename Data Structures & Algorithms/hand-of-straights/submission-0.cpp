class Solution {
   public:
    bool isNStraightHand(vector<int>& arr, int groups) {
        int n = arr.size();
        if (n % groups != 0) return false;

        map<int, int> fre;
        for (auto it : arr) {
            fre[it]++;
        }

        while (!fre.empty()) {
            int start = fre.begin()->first;

            for (int x = start; x < start + groups; x++) {
                if (fre[x] == 0) return false;

                fre[x]--;
                if (fre[x] == 0) fre.erase(x);
            }
        }
        return true;
    }
};
