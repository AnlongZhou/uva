#include <iostream>
using namespace std;

// uva 10128 - Queue
// dp[i][j][k] = number of ways to arrange i people in a queue with j people in front of person A and k people behind person B
// explanation 
// - if person A is at the front of the queue, then there are dp[i-1][j][k-1] ways to arrange the remaining i-1 people with j people in front of person A and k-1 people behind person B
// - if person B is at the back of the queue, then there are dp[i-1][j-1][k] ways to arrange the remaining i-1 people with j-1 people in front of person A and k people behind person B
// - if person A and person B are both in the middle of the queue, then there are dp[i-1][j][k] * (i-2) ways to arrange the remaining i-1 people with j people in front of person A and k people behind person B, since there are (i-2) positions to place the new person


int dp[14][14][14] = {0};

int main() {
    dp[1][1][1] = 1;


    for(int i = 2 ; i < 14 ; i++) {
        for(int j = 1 ; j <= i ; j++) {
            for(int k = 1 ; k <= i ; k++) {
                dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k] * (i - 2);
            }
        }
    }
}
