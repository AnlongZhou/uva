#include <bits/stdc++.h>
using namespace std;

int n, a, b, pos[30];
string s1, s2;
deque<int> block[30];

void ini(int p, int v) {
  for (auto it = block[p].rbegin(); *it != v; it++) {
    block[*it].push_front(*it);
    pos[*it] = *it;
    block[p].pop_back();
  }
}

void pile(int p, int v, int des) {
  auto it = block[p].begin();
  while (*it != v && it != block[p].end())
    it++;
  for (auto i = it; i != block[p].end(); i++) {
    block[des].push_back(*i);
    pos[*i] = des;
  }
  block[p].erase(it, block[p].end());
}

int main() {
  while (cin >> n) {

    for (int i = 0; i < n; i++) {
      block[i].clear();
      block[i].push_back(i);
      pos[i] = i;
    }
    while (cin >> s1, s1 != "quit") {
      cin >> a >> s2 >> b;
      if (pos[a] == pos[b])
        continue;

      if (s1 == "move") {
        if (s2 == "onto" && block[pos[b]].back() != b)
          ini(pos[b], b);
        if (block[pos[a]].back() != a)
          ini(pos[a], a);
        block[pos[b]].push_back(a);
        block[pos[a]].pop_back();
        pos[a] = pos[b];
      } else {
        if (s2 == "onto" && block[pos[b]].back() != b)
          ini(pos[b], b);
        pile(pos[a], a, pos[b]);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << i << ":";
      for (int &x : block[i]) {
        cout << " " << x;
      }
      cout << "\n";
    }
  }
}
