#include <climits>
#include <iostream>
using namespace std;

int grid[76][76], sum[76], N;

int max1D() {
    int globalMax, localMax, globalMin, localMin, total;
    globalMax = localMax = globalMin = localMin = total = sum[0];

    for (int i = 1; i < N; i++) {

        localMax = max(sum[i], localMax + sum[i]);
        globalMax = max(globalMax, localMax);

        localMin = min(sum[i], localMin + sum[i]);
        globalMin = min(globalMin, localMin);

        total += sum[i];
    }

    return max(globalMax, total - globalMin);
}

int main() {
    int T;
    cin >> T;
    while (T--, cin >> N) {
        int Max = INT_MIN;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            fill(sum, sum + N, 0);

            for (int j = 0, t = i; j < N; j++, t++) {
                if (t == N)
                    t = 0;
                for (int k = 0; k < N; k++) {
                    sum[k] += grid[t][k];
                }

                Max = max(Max, max1D());
            }
        }
        cout << Max << endl;
    }
}
