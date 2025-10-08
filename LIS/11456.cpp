#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int dp[2001], previous[2001], nums[2001];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++) {
            cin >> nums[i];
        }

        dp[0] = 1;
        int max_length = 1;
        for(int i = 1 ; i < n ; i++) {
            dp[i] = 1;
            for(int j = 0 ; j < i ; j++) {
                if(nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            max_length = max(max_length, dp[i]);
        }
        cout << max_length << "\n";
    }
}
