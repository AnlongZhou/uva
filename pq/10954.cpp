#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, num, cost;

    while(cin >> n, n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        cost = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> num;
            pq.push(num);
        }

        while(1) {
            int first = pq.top(); pq.pop();
            int second = pq.top() ; pq.pop();
            int sum = first + second;
            cost += sum;
            if(pq.empty()) break;
            pq.push(sum);
        }
        cout << cost << "\n";
    }
}

