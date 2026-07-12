class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> indegree(26, 0);
        vector<vector<int>> adj(26);
        vector<bool> present(26, false);
        int uniqueChars = 0;
        
        for (const string& word : words) {
            for (char c : word) {
                if (!present[c - 'a']) {
                    present[c - 'a'] = true;
                    uniqueChars++;
                }
            }
        }

        int n = words.size();
        for (int i = 1; i < n; i++) {
            string s1 = words[i - 1]; 
            string s2 = words[i];    
            int j = 0;
            int len = min(s1.length(), s2.length());
            bool diffFound = false;

            while (j < len) {
                if (s1[j] != s2[j]) {
                    char c = s1[j];
                    char d = s2[j];
                    adj[c - 'a'].push_back(d - 'a');
                    indegree[d - 'a']++;
                    diffFound = true;
                    break; 
                }
                j++;
            }
            
            if (!diffFound && s1.length() > s2.length()) {
                return "";
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back('a' + node);
            
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (ans.length() != uniqueChars) {
            return ""; 
        }

        return ans;
    }
};