#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Neighbor {
    int id, cost;
    Neighbor(int i, int c) : id(i), cost(c) {}
};

struct HeapNode {
    int id, cost;

    HeapNode(int i = 0, int c = 0) : id(i), cost(c) {}

    bool operator>(const HeapNode right) const { return cost > right.cost; }
};

const int inf = 2147483647;
const int MAX = 200005;
vector<Neighbor> adjList[MAX];
int cost[MAX];
int m;

void Prim() {
    for (int u = 1; u < m; u++)
        cost[u] = inf;
    cost[0] = 0;

    vector<bool> inQ(m, true);
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> Q;
    for (int u = 0; u < m; u++)
        Q.push(HeapNode(u, cost[u]));

    while (!Q.empty()) {
        HeapNode u = Q.top();
        Q.pop();
        inQ[u.id] = false;
        for (Neighbor v : adjList[u.id])
            if (cost[v.id] > v.cost && inQ[v.id]) {
                cost[v.id] = v.cost;
                Q.push(HeapNode(v.id, cost[v.id]));
            }
    }
}

int main() {
    int n;
    cin >> m >> n;
    while (m > 0 || n > 0) {
        for (int u = 0; u < m; ++u)
            adjList[u].clear();

        int totalCost = 0;
        for (int i = 0; i < n; ++i) {
            int u, v, z;
            cin >> u >> v >> z;
            adjList[u].push_back({v, z});
            adjList[v].push_back({u, z});
            totalCost += z;
        }

        Prim();

        int mstCost = 0;
        for (int u = 0; u < m; ++u)
            mstCost += cost[u];
        for(int i = 0 ; i < m ; i++) {
            cout << cost[i] << " ";
        }


        cout << totalCost << "\n";
        cout << mstCost << "\n";

        cout << totalCost - mstCost << endl;
        cin >> m >> n;
    }

    return 0;
}
