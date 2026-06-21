class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int max_freq = 0;
        
        for (char task : tasks) {
            freq[task - 'A']++;
            max_freq = max(max_freq, freq[task - 'A']);
        }
        
        int max_freq_count = 0;
        for (int count : freq) {
            if (count == max_freq) {
                max_freq_count++;
            }
        }
       
        int ans = (max_freq - 1) * (n + 1) + max_freq_count;
        
        
        return max(ans, (int)tasks.size());
    }
};