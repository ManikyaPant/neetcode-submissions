class Solution {
public:
    bool matchfre(vector<int>& f1, vector<int>& f2) {
        int n = f1.size();

        for (int i = 0; i < n; i++) {
            if (f2[i] == 0) continue;

            if (f1[i] < f2[i]) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        vector<int> f1(128, 0), f2(128, 0);

        for (char c : t) {
            f2[c]++;
        }

        int ans = 1e9;
        int l = 0, r = 0;
        int i = 0, j = 0;
        int n = s.length();

        while (i < n) {
            f1[s[i]]++;

            while (j <= i && matchfre(f1, f2)) {
                if (ans > i - j + 1) {
                    ans = i - j + 1;
                    l = j;
                    r = i;
                }

                f1[s[j]]--;
                j++;
            }

            i++;
        }

        if (ans == 1e9)
            return "";

        return s.substr(l, ans);
    }
};