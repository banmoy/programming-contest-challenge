// Sample Input
// 7
//
// Sample Output
// 6

#include <cstdio>

using namespace std;

#define MOD 1000000000LL
#define MAXN 1000001

int N;
int dp[MAXN];

int solve() {
    dp[0] = dp[1] = 1;
    for(int i=2; i<=N; ++i) {
        if(i&1)
            dp[i] = dp[i-1];
        else
            dp[i] = (dp[i-2] + dp[i>>1]) % MOD;
    }
    return dp[N];
}

int main() {
    scanf("%d", &N);
    printf("%d\n", solve());
    return 0;
}