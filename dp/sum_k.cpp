// 有N种不同大小的数字ai, 每种各mi个，是否可以从中选出若干使它们的和为K
// 
// Sample Input
// 3 17(N, K)
// 3 3(a, m)
// 5 2
// 8 2
// 
// Sample Output
// 1

#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXK 1001

int N, K;
int a[MAXN], m[MAXN];
int dp[MAXK];


// dp(i, j) 当前i个数组成j时，第i个数剩余的最大数量，如果不能组成j，则为-1
//            |---- mi dp(i-1, j)>=0
// dp(i, j) = |---- -1 j<ai || dp(i, j-ai)<=0
//            |---- dp(i, j-ai)-1
int solve() {
    memset(dp, -1, sizeof(int)*(K+1));
    dp[0] = 0;
    for(int i=1; i<=N; ++i) {
        for(int j=0; j<=K; ++j) {
            if(dp[j]>=0)
                dp[j] = m[i];
            else if(j<a[i] || dp[j-a[i]]<=0)
                dp[j] = -1;
            else
                dp[j] = dp[j-a[i]]-1;
        }
    }
    return dp[K]>=0;
}


int main() {
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; ++i)
        scanf("%d%d", &a[i], &m[i]);
    printf("%d\n", solve());
}