// 有n种物品，第i种物品有ai个。不同种类的物品可以互相区分但相同种类的无法区分。从中选出m个，取法种数
//
// Sample Input
// 3 3 10000(n, m, M)
// 1 2 3(ai)
// 
// Sample Output
// 6

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1001
#define MAXM 1001

int n, m, M;
int a[MAXN];


// dp(i, j) 从前i个物品种取出j个的取法
//            |---- 0 sum(a1...ai)<j
// dp(i, j) = |
//            |---- sum(dp(i-1, j-k), k=0,1,...,min(j, ai)) sum(a1...ai)>=j
// complexity: O(nm^2)
int solve1() {
    int dp[MAXN][MAXM];
    memset(dp, 0, sizeof(dp[0]));
    dp[0][0] = 1;
    int sum = 0;
    for(int i=1; i<=n; ++i) {
        sum += a[i];
        for(int j=0; j<=min(sum, m); ++j) {
            for(int k=0; k<=min(j, a[i]); ++k) {
                dp[i][j] += dp[i-1][j-k];
            }
            dp[i][j] %= M;
        }
        if(m>sum)
            memset(dp[i]+sum+1, 0, sizeof(int)*(m-sum));
    }
    return dp[n][m];
}


// dp(i, j) 从前i个物品中取出j个的取法
// dp(i, j) = sum(dp(i-1, j-k), k=0,1,...,min(j, ai))
// 优化：
// j>ai, dp(i, j) = dp(i-1, j)+dp(i-1, j-1)+dp(i-1, j-2) + ... + dp(i-1, j-ai)
//       dp(i, j-1) = dp(i-1, j-1) + dp(i-1, j-2)　＋ ... + dp(i-1, j-1-ai)
//   *** dp(i, j) = dp(i-1, j) + dp(i, j-1) - dp(i-1, j-1-ai)
// j<=ai, dp(i, j) = dp(i-1, j)+dp(i-1, j-1)+dp(i-1, j-2) + ... + dp(i-1, 0)
//        dp(i, j-1) = dp(i-1, j-1) + dp(i-1, j-2) + ... + dp(i-1, 0)
//   *** dp(i, j) = dp(i-1, j) + dp(i, j-1)
//              |---- 1, j==0
//              |---- 0, i==0 && j!=0
//  dp(i, j) =  |
//              |---- dp(i-1, j) + dp(i, j-1) j<=ai
//              |---- dp(i-1, j) + dp(i, j-1) - dp(i-1, j-1-ai) j>ai
// Complexity: O(nm)
int solve2() {
    int dp[MAXN][MAXM];
    memset(dp, 0, sizeof(dp[0]));
    dp[0][0] = 1;
    for(int i=1; i<=n; ++i) {
        dp[i][0] = 1;
        for(int j=1; j<=m; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - (j<=a[i] ? 0 : dp[i-1][j-1-a[i]]);
        }
    }
    return dp[n][m];
}


int main() {
    scanf("%d%d%d", &n, &m, &M);
    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    // printf("%d\n", solve1());
    printf("%d\n", solve2());
}