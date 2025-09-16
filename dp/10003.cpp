#include <iostream>
#include <climits>
using namespace std;

int main() {
    int l, n;
    while(cin >> l, l) {
        cin >> n;
        int dp[52][52] = {0};
        int *table = new int[n + 2];
        n++;
        table[0] = 0; table[n] = l;
        for(int i = 1 ; i < n ; i++) {
            cin >> table[i];
            for(int r = 2 ; r <= n ; ++r) {
                for(int b = 0 ; b < n ; b++) {
                    int e = b + r;
                    if(e > n) break;
                    dp[b][e] = INT_MAX;
                    for(int c = b+1 ; c < e ; c++) {
                        int temp = dp[b][c] + dp[c][e] + table[e] - table[b];
                        if(temp < dp[b][e]) dp[b][e] = temp;
                    }
                }
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][n]);
    }
}
