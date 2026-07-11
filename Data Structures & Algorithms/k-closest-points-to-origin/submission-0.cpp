class Solution {
public:
    struct customOps {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            return a.first*a.first + a.second*a.second <
                   b.first*b.first + b.second*b.second;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       customOps> q;

        for (auto &point : points) {
            int x = point[0];
            int y = point[1];

            if (q.size() < k) {
                q.push({x, y});
            } else {
                auto [a, b] = q.top();
                if (x*x + y*y < a*a + b*b) {
                    q.pop();
                    q.push({x, y});
                }
            }
        }

        vector<vector<int>> ans;
        while (!q.empty()) {
            auto [x, y] = q.top();
            q.pop();
            ans.push_back({x, y});
        }

        return ans;
    }
};