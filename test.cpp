
#include <iostream>

#include <string>

#include <sstream>

#include <algorithm>

#include <memory.h>

using namespace std;

bool graph[26][26];

bool check[26];

bool t;

string sdata;

void dfs(string s)

{

  if (s.size() == sdata.size()) {

    for (int i = 0; i < s.size(); ++i)

      cout << s[i] << (i != s.size() - 1 ? " " : "\n");

    t = true;

    return;
  }

  for (size_t i = 0; i < sdata.size(); ++i)

    if (!check[sdata[i] - 'A']) {

      int j = 0;

      for (; j < s.size(); ++j)

        if (graph[sdata[i] - 'A'][s[j] - 'A'])
          break;

      if (j == s.size()) {

        check[sdata[i] - 'A'] = true;

        dfs(s + sdata[i]);

        check[sdata[i] - 'A'] = false;
      }
    }
}

int main()

{

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  cout.tie(nullptr);

  int T;

  string str;

  cin >> T;

  cin.ignore();

  while (T--) {

    getline(cin, str);

    sdata.clear();

    t = false;

    memset(graph, false, sizeof(graph));

    memset(check, false, sizeof(check));

    getline(cin, str);

    stringstream ss;

    ss << str;

    while (ss >> str)
      sdata += str;

    sort(sdata.begin(), sdata.end());

    getline(cin, str);

    ss.clear();

    ss << str;

    while (ss >> str)
      graph[str[0] - 'A'][str[2] - 'A'] = true;

    dfs("");

    if (!t)
      cout << "NO\n";

    if (T)
      cout << "\n";
  }

  return 0;
}
