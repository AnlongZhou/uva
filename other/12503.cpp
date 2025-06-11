#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

void act(string &ins, int &p, vector<string> &vec) {
  if(ins[0] == 'L') 
    p--;
  else if(ins[0] == 'R')
    p++;
  else {
    string str;
    int x;
    for(int i = 8 ; i < ins.size() ; i++) {
      str.push_back(ins[i]);
      x = stoi(str);
    }
    act(vec[x], p, vec);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    vector<string> vec;
    vec.push_back("*");
    int n, p = 0;
    cin >> n;
    cin.ignore();
    while (n--) {
      string ins;
      getline(cin, ins);
      vec.push_back(ins);
      act(ins, p, vec);
    }
    cout << p << "\n";
 }
}
