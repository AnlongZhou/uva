#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> done;

void dfs(int &length, int list[], int index, vector<bool> &visit) {

  visit[index] = 1;
  done[index] = 1;
  length++;
  if (!visit[list[index]])
    dfs(length, list, list[index], visit);
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t, caseNum = 1, n, u, v;
  cin >> t;

  while (t--) {
    cin >> n;
    int list[n + 1];

    for (int i = 0; i < n; i++) {
      cin >> u >> v;
      list[u] = v;
    }

    int maxDepth = 1;
    int ans;


    done.resize(n+1);
    done = {0};

    for (int i = 1; i <= n; i++) {

      if (!done[i]) {

        vector<bool> visit(n + 1);
        visit = {0};

        int length = 0;

        dfs(length, list, i, visit);

        if (length > maxDepth) {
          maxDepth = length;
          ans = i;
        }
      }
    }

    cout << "Case " << caseNum++ << ": " << ans << "\n";
  }
}
