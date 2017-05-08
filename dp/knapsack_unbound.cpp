// Sample Input
// 3 7(N, W)
// 2 3(w, v)
// 3 4
// 4 5
//
// Sample Output
// 10

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXW 10001

int N, W;
int w[MAXN], v[MAXN];

// dp(n, w) and two-dimensional array
// maximum value the first i objects can acheive when the total weigt is not greater than j
//            |----- dp[i-1][j], j<w[i]
// dp(i, j) = |
//            |----- max(dp[i-1][j], dp[i][j-w[i]]+v[i]), j>=w[i]
int solve1() {
    int dp[MAXN][MAXW];
    memset(dp, 0, sizeof(dp[0]));
    for(int i=1; i<=N; ++i) {
        for(int j=0; j<=W; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j>=w[i])
                dp[i][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
        }
    }
    return dp[N][W];
}

// dp(n, w) and one-dimensional array
// maximum value the first i objects can acheive when the total weigt is not greater than j
//            |----- dp[i-1][j], j<w[i]
// dp(i, j) = |
//            |----- max(dp[i-1][j], dp[i][j-w[i]]+v[i]), j>=w[i]
int solve2() {
    int dp[MAXW];
    memset(dp, 0, sizeof(dp[0]));
    for(int i=1; i<=N; ++i) {
        for(int j=w[i]; j<=W; ++j) {
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    return dp[W];
}


int main() {
    scanf("%d%d", &N, &W);
    for(int i=1; i<=N; ++i)
        scanf("%d%d", &w[i], &v[i]);
    // printf("%d\n", solve1());
    printf("%d\n", solve2());
}