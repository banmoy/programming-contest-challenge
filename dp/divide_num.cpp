// 有n个无区别的物品，将它们划分成不超过m组，求出划分方法数模M的余数
// 
// Sample Input
// 4 3 10000(n, m, M)
// 
// Sample Output
// 4

#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1001
#define MAXM 1001

int n, m, M;
int dp[MAXN][MAXM];


// dp(i, j) 将i个数划分为最多j组时的个数
// i个数最多划分成i组，所以如果j>i，则dp(i, j) = dp(i, i)
// 当j<=i时，有两种划分方法:　
//  １、将i个数划成j组，那么每组至少有一个，剩下i-j个数分到最多j个组中，共dp(i-j, j)
//  ２、将i个数最多划分成j-1组，共dp(i, j-1)
//            |---- dp(i, i) j>i
// dp(i, j) = |
//            |---- dp(i-j, j) + dp(i, j-1) j<=i
int solve() {
    for(int i=0; i<=m; ++i)
        dp[0][i] = 1;
    for(int i=1; i<=n; ++i) {
        dp[i][0] = 0;
        for(int j=1; j<=m; ++j) {
            if(j > i)
                dp[i][j] = dp[i][i];
            else
                dp[i][j] = (dp[i-j][j] + dp[i][j-1])%M;
        }
    }
    return dp[n][m];
}


int main() {
    scanf("%d%d%d", &n, &m, &M);
    printf("%d\n", solve());
}