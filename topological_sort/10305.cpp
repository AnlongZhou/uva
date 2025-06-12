#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

vector<int> adj[101], result;
bool visit[101], linked[101];

void dfs(int num) {
  visit[num] = true;
  for(int &i : adj[num]) {
    if(!visit[i]) dfs(i);
  }
  result.push_back(num);
}

int main() {
  int n, m;
  while(cin >> n >> m, n || m) {
    fill(adj, adj + 101, vector<int>());
    memset(visit, false, sizeof(visit));
    memset(linked, false, sizeof(linked));
    result.clear();

    while(m--) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      linked[b] = true;
    }

    for(int i = 1 ; i <= n ; i++) {
      if(!linked[i]) dfs(i);
    }

    for(int i = result.size() - 1; i >= 0; i--) {
      cout << result[i];
      if(i > 0) cout << " ";
    }
    cout << "\n";
  }
}
