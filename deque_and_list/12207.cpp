#include <deque>
#include <iostream>
using namespace std;

int main() {
  int P, C;
  int Case = 1;
  while(cin >> P >> C, P != 0 && C != 0) {
    cout << "Case " << Case++ << ":\n";
    deque<int> deck;
    for(int i = 1 ; i <= min(P, C); i++) {
      deck.push_back(i);
    }
    while(C--) {
      char command;
      cin >> command;
      if(command == 'N') {
        cout << deck.front() << "\n";
        deck.push_back(deck.front());
        deck.pop_front();
      } else {
        int x;
        cin >> x;
        deck.push_front(x);
        for(auto it = deck.begin()+1 ; it != deck.end() ; it++) {
          if(*it == x) {
            deck.erase(it);
            break;
          }
        }
      }
    }
  }
}
