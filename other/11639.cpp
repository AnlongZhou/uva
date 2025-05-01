#include <iostream>
using namespace std;

struct Rec {
  int x1, x2, y1, y2;
};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, Case = 1;
  cin >> n;
  while(n--) {
    cout << "Night " << Case++ << ": ";
    Rec r1, r2;
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
    int A, B, C, D;
    A = max(r1.x1, r2.x1);
    B = max(r1.y1, r2.y1);
    C = min(r1.x2, r2.x2);
    D = min(r1.y2, r2.y2);
    int strong = (C - A) * (D - B);
    if(A > C || B > D) strong = 0;
    int weak = (r1.x2 - r1.x1) * (r1.y2 - r1.y1) + (r2.x2 - r2.x1) * (r2.y2 - r2.y1) - 2 * strong; 
    int unsecured = 10000 - strong - weak;
    cout << strong << " " << weak << " " << unsecured << "\n";
  }
}
