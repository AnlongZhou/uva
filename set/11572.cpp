#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
  int N, n, inp;
  size_t length = 0;
  unordered_set<int> snow;
  vector<int> vec;
  cin >> N;
  while (N--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> inp;
      if (snow.count(inp)) {
        length = max(length, snow.size());
      }
      while (snow.count(inp)) {
        snow.erase(*vec.begin());
        vec.erase(vec.begin());
      }
      snow.insert(inp);
      vec.push_back(inp);
    }
    length = max(length, snow.size());

    cout << length << "\n";
    length = 0;
    snow.clear();
    vec.clear();
  }
}
