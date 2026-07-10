class Solution {
public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& f : flights) {
            int u = f[0];
            int v = f[1];
            int price = f[2];

            adj[u].push_back({v, price});
        }

        const int INF = 1e9;

        // dist[node][flights used]
        vector<vector<int>> dist(n, vector<int>(k + 2, INF));

        // {cost, node, flightsUsed}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, used] = pq.top();
            pq.pop();

            if (cost != dist[node][used]) {
                continue;
            }

            if (node == dst) {
                return cost;
            }

            if (used == k + 1) {
                continue;
            }

            for (auto [next, price] : adj[node]) {
                int newCost = cost + price;
                int newUsed = used + 1;

                if (newCost < dist[next][newUsed]) {
                    dist[next][newUsed] = newCost;
                    pq.push({newCost, next, newUsed});
                }
            }
        }

        return -1;
    }
};