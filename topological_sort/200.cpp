#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> adj[26];
vector<char> result;
bool visit[26], path[26];

void dfs(int num) {
  visit[num] = true;
  for(int i : adj[num]) {
    if(!visit[i]) dfs(i);
  }
  result.emplace_back(num + 'A');
}

int main() {
  string str1, str2;
  unordered_set<int> s;
  cin >> str1;
  while (cin >> str2, str2 != "#") {

    for (int i = 0; str1[i] && str2[i]; i++) {

      s.emplace(str1[i] - 'A');
      s.emplace(str2[i] - 'A');

      if (str1[i] != str2[i]) {
        adj[str1[i] - 'A'].emplace_back(str2[i] - 'A');
        path[str2[i] - 'A'] = 1;
        break;
      }
    }

    str1 = str2;
  }

  for (int i : s) {
    if(!path[i]) dfs(i);
  }

  for(auto it = result.rbegin() ; it != result.rend() ; it++) {
    cout << *it;
  }
  cout << "\n";
}
