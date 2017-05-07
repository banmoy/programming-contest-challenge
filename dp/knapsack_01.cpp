// Sample Input
// 4 5(N, W)
// 2 3(w, v)
// 1 2
// 3 4
// 2 2

// Sample Output
// 7

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
//            |----- max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]), j>=w[i]
int solve1() {
    int dp[MAXN][MAXW];
    memset(dp, 0, sizeof(dp[0]));
    for(int i=1; i<=N; ++i) {
        for(int j=0; j<=W; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j>=w[i])
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
        }
    }
    return dp[N][W];
}

// dp(n, w) and one-dimensional array
//            |----- dp[i-1][j], j<w[i]
// dp(i, j) = |
//            |----- max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]), j>=w[i]
int solve2() {
    int dp[MAXW];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=N; ++i) {
        // backward
        for(int j=W; j>=0; --j) {
            if(j>=w[i]) dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    return dp[W];
}

// dp(n, w) and one-dimensional array and constant optimization
//            |----- dp[i-1][j], j<w[i]
// dp(i, j) = |
//            |----- max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]), j>=w[i]
int solve3() {
    int dp[MAXW];
    memset(dp, 0, sizeof(dp));
    int tw = 0;
    for(int i=1; i<=N; ++i)
        tw += w[i];
    for(int i=1; i<=N; ++i) {
        // backward
        // lower bound1: w[i]
        // lower bound2: W-sum(w[i+1], w[i+2],..., w[N])
        tw -= w[i];
        int bd = max(w[i], W-tw);
        for(int j=W; j>=bd; --j) {
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    return dp[W];
}

// dp(n, v) and one-dimensional array
// the minimum weight the first i objects weigh when they acheive valud j
// if they can not acheive j, then set dp(i, j) to INF
//            |----- dp[i-1][j], j<v[i]
// dp(i, j) = |
//            |----- min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]), j>=v[i]
int solve4() {
    int tval = 0;
    for(int i=1; i<=N; ++i)
        tval += v[i];
    int *dp = new int[tval+1];
    dp[0] = 0;
    for(int i=1; i<=tval; ++i)
        dp[i] = W + 1;
    for(int i=1; i<=N; ++i) {
        for(int j=tval; j>=v[i]; j--) {
            dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    for(int i=tval; i>=0; --i)
        if(dp[i]<=W)
            return i;
}

int main() {
    scanf("%d%d", &N, &W);
    for(int i=1; i<=N; ++i)
        scanf("%d%d", &w[i], &v[i]);
    // printf("%d\n", solve1());
    // printf("%d\n", solve2());
    printf("%d\n", solve3());
    // printf("%d\n", solve4());
}