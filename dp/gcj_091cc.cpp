// Sample Input
// 2
// 8 1
// 3
// 20 3
// 3 6 14
//
// Sample Output
// Case #1: 7
// Case #2: 35

#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXQ 110

int N, P, Q;
int a[MAXQ];
int dp[MAXQ][MAXQ];

int solve() {
    a[0] = 0;
    a[Q+1] = P+1;
    for(int i=0; i<=Q; ++i)
        dp[i][i+1] = 0;
    for(int l=2; l<=Q+1; ++l) {
        for(int i=0; i+l<=Q+1; ++i) {
            int j=i+l;
            dp[i][j] = INT_MAX;
            for(int k=i+1; k<j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+a[j]-a[i]-2);
            }
        }
    }
    return dp[0][Q+1];
}

int main() {
    scanf("%d", &N);
    for(int n=1; n<=N; ++n) {
        scanf("%d%d", &P, &Q);
        for(int i=1; i<=Q; ++i)
            scanf("%d", &a[i]);
        printf("Case #%d: %d\n", n, solve());
    }
}