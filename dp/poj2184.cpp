// Sample Input
// 5
// -5 7
// 8 -6
// 6 -3
// 2 1
// -8 -5
// 
// Sample Output
// 8

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 101
#define MAXS 100000

int N;
int S[MAXN];
int F[MAXN];

// smartness : weight, funness : value
// dp[i][j] : 前i头cow的smartness为j时的最大funness
// dp[i][j] = max(dp[i-1][j], f[i]+dp[i-1][j-s[i]])
// j的范围为[-100000, 100000]
int solve1() {
    int dp[2][2*MAXS + 1], ret = 0, cur, pre;
    memset(dp[1], INF, sizeof(dp[1]));
    dp[1][MAXS] = 0;
    for(int i=0; i<N; ++i) {
        cur=i&1, pre=(i&1)^1;
        for(int j=0; j<=2*MAXS; ++j) {
            dp[cur][j] = dp[pre][j];
            int k = j-S[i];
            if(k>=0 && k<=2*MAXS && dp[pre][k]!=INF) {
                int f = dp[pre][k] + F[i];
                dp[cur][j] = dp[cur][j]==INF ? f : max(dp[cur][j], f);
            }
        }
    }
    cur = (N-1)&1;
    for(int i=MAXS; i<=2*MAXS; ++i)
        if(dp[cur][i]!=INF && dp[cur][i]>=0)
            ret = max(ret, i-MAXS+dp[cur][i]);
    return ret;
}

int solve2() {
    int dp[2*MAXS + 1], ret=0, k;
    for(int i=0; i<=2*MAXS+1; ++i)
        dp[i] = -INF;
    dp[MAXS] = 0;
    for(int i=0; i<N; ++i) {
        if(S[i]>=0) {
            // from right to left
            for(int j=2*MAXS; j>=S[i]; --j) {
                k = j-S[i];
                if(dp[k]!=-INF) {
                    dp[j] = max(dp[j], dp[k]+F[i]);
                }
            }
        } else {
            // from left to right
            for(int j=0; j<=2*MAXS+S[i]; ++j) {
                k = j-S[i];
                if(dp[k]!=-INF) {
                    dp[j] = max(dp[j], dp[k]+F[i]);
                }
            }
        }
    }

    for(int i=MAXS; i<=2*MAXS; ++i)
        if(dp[i]!=-INF && dp[i]>=0)
            ret = max(ret, i-MAXS+dp[i]);

    return ret;
}

int solve3() {
    int dp[2*MAXS + 1], ret=0, k, l, r;
    memset(dp, -1, sizeof(dp));
    dp[MAXS] = MAXS;

    l = r = MAXS;
    for(int i=0; i<N; ++i) {
        if(S[i]>=0) {
            // from right to left
            r += S[i];
            for(int j=r; j>=l+S[i]; --j) {
                k = j-S[i];
                if(dp[k]!=-1) {
                    dp[j] = max(dp[j], dp[k]+F[i]);
                }
            }
        } else {
            // from left to right
            l += S[i];
            for(int j=l; j<=r+S[i]; ++j) {
                k = j-S[i];
                if(dp[k]!=-1) {
                    dp[j] = max(dp[j], dp[k]+F[i]);
                }
            }
        }
    }

    for(int i=MAXS; i<=2*MAXS; ++i)
        if(dp[i] >= MAXS)
            ret = max(ret, i+dp[i]);
    ret -= 2*MAXS;

    return ret;
}


int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d%d", &S[i], &F[i]);
    // printf("%d\n", solve1());
    // printf("%d\n", solve2());
    printf("%d\n", solve3());
    return 0;
}