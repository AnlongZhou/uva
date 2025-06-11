#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> square;
vector<pair<int, int>> mv;
int r, c, m, n, w;

void dfs(int x, int y) {
  if (square[x][y]++ != 0)
    return;

  for (int i = 0, nx, ny ; i < 8 ; i++) {
    nx = x + mv[i].first;
    ny = y + mv[i].second;

    if (nx < r && nx >= 0 && ny >= 0 && ny < c && square[nx][ny] != -1) {
      dfs(nx, ny);
    }
    if(i == 1 && mv[i].first == mv[i].second) i += 4;
    if(i == 3 && (!mv[i].first || !mv[i].second)) break;
  }
}

int main() {
  int caseNum = 1;
  int t;
  cin >> t;
  while (t--) {
    cin >> r >> c >> m >> n >> w;
    square.clear();
    square.assign(r, vector<int>(c));
    mv.clear();
    mv.emplace_back(m, n);
    mv.emplace_back(-m, -n);
    mv.emplace_back(n, m);
    mv.emplace_back(-n, -m);
    mv.emplace_back(-n, m);
    mv.emplace_back(n, -m);
    mv.emplace_back(-m, n);
    mv.emplace_back(m, -n);

    while (w--) {
      int a, b;
      cin >> a >> b;
      square[a][b] = -1;
    }

    dfs(0, 0);
    square[0][0]++;
    int even = 0, odd = 0;

    for (auto i : square) {
      for (auto j : i) {
        if (j > 0) {
          j & 1 ? odd++ : even++;
        }
      }
    }
    printf("Case %d: ", caseNum++);
    cout << even << " " << odd << "\n";
  }
}
