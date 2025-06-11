#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

string sdata;
bool adj[26][26], check[26], have;

void dfs(string s) {

  if (s.size() == sdata.size()) {
    for (int i = 0; i < s.size(); i++) {
      cout << s[i];
      cout << (i != s.size() - 1 ? " " : "\n");
    }
    have = true;
    return;
  }

  for (int i = 0; i < sdata.size(); i++) {
    if (!check[sdata[i] - 'A']) {

      int j = 0;

      for (; j < s.size(); j++) {
        if (adj[sdata[i] - 'A'][s[j] - 'A']) {
          break;
        }
      }

      if (j == s.size()) {
        check[sdata[i] - 'A'] = true;
        dfs(s + sdata[i]);
        check[sdata[i] - 'A'] = false;
      }
    }
  }
}

int main() {
  int t;
  string str;
  cin >> t;
  cin.ignore();

  while (t--) {
    getline(cin, str);
    sdata.clear();
    have = false;
    memset(adj, false, sizeof(adj));
    memset(check, false, sizeof(check));

    getline(cin, str);
    stringstream ss(str);
    while (ss >> str) {
      sdata += str;
    }
    sort(sdata.begin(), sdata.end());

    getline(cin, str);
    ss.clear();
    ss << str;
    while (ss >> str) {
      adj[str[0] - 'A'][str[2] - 'A'] = 1;
    }

    dfs("");
    if (!have)
      cout << "NO";
    if (t)
      cout << "\n";
  }
}
