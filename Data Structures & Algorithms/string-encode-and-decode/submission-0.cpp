string int_to_string(int num, int bit_size) {
    string ans(bit_size, '0');

    for (int i = bit_size - 1; i >= 0; --i) {
        ans[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }

    return ans;
}

int string_to_int(const string& s) {
    int num = 0;
    for(char c : s) {
        num = num * 2 + (c - '0');
    }
    return num;
}

class Solution {
public:
    static constexpr int bit_size = 9;
    static constexpr int EOS = 256;

    unordered_map<int, string> mp;

    Solution() {
        for (int i = 0; i <= EOS; i++) {
            mp[i] = int_to_string(i, bit_size);
        }
    }

    string encode(vector<string>& strs) {
        string ans;

        for (const string& str : strs) {
            for (unsigned char c : str) {
                ans += mp[(int)c];
            }
            ans += mp[EOS];
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string curr;

        for (int i = 0; i < s.size(); i += bit_size) {
            string bits = s.substr(i, bit_size);
            int val = string_to_int(bits);

            if (val == EOS) {
                res.push_back(curr);
                curr.clear();
            } else {
                curr.push_back((char)val);
            }
        }

        return res;
    }
};