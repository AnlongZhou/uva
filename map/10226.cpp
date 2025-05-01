#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.get();
  cin.get();
  while (n--) {
    map<string, double> mp;
    string str;
    int count = 0;
    while(getline(cin, str) && str != "") {
      count++;
      mp[str]++;
    }
    for(auto i : mp) {
      cout << i.first << " " << setprecision(4) << fixed << 100 * (i.second / count) << "\n";
    }
    if(n) cout << "\n";
  }
}
