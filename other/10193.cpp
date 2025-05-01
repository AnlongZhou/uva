#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int tobin(string &str) {
  int binary = 0, power = str.size() - 1;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1') {
      binary += pow(2, power);
    }
    power--;
  }
  return binary;
}

int main() {
  int n, pair = 1, b1, b2;
  string s1, s2;
  cin >> n;
  while (n--) {
    cin >> s1 >> s2;
    b1 = tobin(s1);
    b2 = tobin(s2);
    cout << "Pair #" << pair++ << ": ";
    if (__gcd(b1, b2) != 1) {
      cout << "All you need is love!\n";
    } else {
      cout << "Love is not all you need!\n";
    }
  }
}
