#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n;
  string str, line;
  while (cin >> n, n) {

    map<string, int> mp;
    int mostPopular = 0;

    while (n--) {

      vector<string> vec;
      str.clear();

      for (int i = 0; i < 5; i++) {
        cin >> line;
        vec.push_back(line);
      }
      sort(vec.begin(), vec.end());
      for(auto s : vec) {
        str += s;
      }
      mp[str]++;
      mostPopular = max(mostPopular, mp[str]);
    }

    int ans = 0;
    for (auto &p : mp) {
      if (p.second == mostPopular)
        ans += p.second;
    }
    cout << ans << "\n";
  }
}
