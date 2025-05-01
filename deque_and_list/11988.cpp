#include <iostream>
#include <list>
using namespace std;

int main() {
  string str;
  while(getline(cin, str)) {
    list<char> li;
    auto it = li.begin();
    for(char &c:str) {
      switch (c) {
        case '[':
          it = li.begin();
          break;
        case ']':
          it = li.end();
          break;
        default:
          li.insert(it, c);
          break;
      }
    }
    for(char &x : li) {
      cout << x;
    }
    cout << "\n";
    str.clear();
  }
}
