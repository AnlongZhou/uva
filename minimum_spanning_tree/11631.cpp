#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[200005];
int cost[200005];

void prim(int m) {

    for (int u = 1; u < m; u++)
        cost[u] = INT_MAX;
    cost[0] = 0;

    vector<bool> inQ(m, true);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < m; i++) {
        pq.push({cost[i], i});
    }

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curID = pq.top().second;
        pq.pop();
        inQ[curID] = false;

        for (auto e : adj[curID]) {
            if (cost[e.second] > e.first && inQ[e.second]) {
                cost[e.second] = e.first;
                pq.push({cost[e.second], e.second});
            }
        }
    }
}

int main() {

    int m, n, x, y, z;

    while (cin >> m >> n, (m != 0 && n != 0)) {

        int totalCost = 0;

        for (int i = 0; i < m; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            adj[x].push_back({z, y});
            adj[y].push_back({z, x});
            totalCost += z;
        }

        prim(m);

        int mstCost = 0;

        for (int i = 0; i < m; i++) {
            mstCost += cost[i];
        }

        for(int i = 0 ; i < m ; i++) {
            cout << cost[i] << " ";
        }
        cout << "\n";
        cout << totalCost << "\n";
        cout << mstCost << "\n";


        cout << totalCost - mstCost << "\n";
    }
}
