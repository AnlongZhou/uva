#include <functional>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <utility>
#include <vector>
#define p pair<string, string>
using namespace std;

int main() {
  int n, cnt = 0;

  string str = "0123456789";

  while (cin >> n, n) {
    priority_queue<p, vector<p>, greater<p>> ans;

    for (int i = 98765; i >= 1234; i--) {
      if (i % n == 0) {
        int num = i / n;
        string s, s1, s2;
        stringstream ss1, ss2;
        ss1 << i;
        ss2 << num;
        ss1 >> s1;
        ss2 >> s2;
        s = s1 + s2;
        if (s.size() == 9)
          s += '0';
        sort(s.begin(), s.end());

        if(str == s) ans.push({s1, s2});
      }
    }

    if(cnt++) cout << "\n";
    if(ans.empty()) cout << "There are no solutions for " << n << ".\n";
    else {
        while(!ans.empty()) {
            string i = ans.top().first;
            string j = ans.top().second;
            cout << setw(5) << setfill('0') << i;
            cout << " / ";
            cout << setw(5) << setfill('0') << j;
            cout << " = " << n << "\n";
            ans.pop();
        }
    }
  }
}
