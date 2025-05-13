#include <bits/stdc++.h>
using namespace std;

int main() {
    long long multiples[3] = {2, 3, 5};
    long long number;
    set<long long> st;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    pq.push(1);
    st.insert(1);

    for(int i = 1 ; i <= 1500 ; i++) {
        number = pq.top();
        pq.pop();
        for(int j = 0 ; j < 3 ;j++) {
            if(!st.count(number * multiples[j])) {
                st.insert(number * multiples[j]);
                pq.push(number * multiples[j]);
            }
        }
    }

    printf("The 1500'th ugly number is %lld.\n", number);
}
