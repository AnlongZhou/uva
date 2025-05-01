#include <string>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

int main() {
  string s1, s2, s3;
  map<string, string> mp;
  stringstream ss;
  while (getline(cin, s1), s1 != "") {
    ss << s1;
    ss >> s2 >> s3;
    mp[s3] = s2;
  }
  string str;
  while (cin >> str) {
    if (mp[str] == "") {
      cout << "eh\n";
    } else {
      cout << mp[str] << "\n";
    }
  }
}
