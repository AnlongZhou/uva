#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, max_num = 1;
  map<string, int> mp;
  string s;
  while (cin >> n, n) {
    mp.clear();
    cin.ignore();
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      sort(s.begin(), s.end());
      if (mp.count(s)) {
        max_num = max(max_num, ++mp[s]);
      } else {
        mp[s]++;
      }
    }
    cout << max_num << "\n";
  }
}
