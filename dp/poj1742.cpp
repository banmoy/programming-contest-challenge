// Sample Input
// 3 10
// 1 2 4 2 1 1
// 2 5
// 1 4 2 1
// 0 0
// Sample Output
//
// 8
// 4

#include <cstdio>
#include <cstring>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAXN 101
#define MAXM 100010

int N, M;
int dp[MAXM];

// dp[i][j] 前i种coin组成j需要多少个第j种coin,如果不能组成j，则为-1
//            |---- -1, dp[i-1][j]==-1 && dp[i][j-A[i]]==-1 && dp[i][j-A[i]]==C[i]
// dp[i][j] = |---- 0, dp[i-1][j]>=0
//            |---- dp[i][j-A[i]]+1, other case
int solve1() {
    int A[MAXN], C[MAXN];
    int ret=0;
    ll s = 0;

    for(int i=0; i<N; ++i)
        scanf("%d", &A[i]);
    for(int i=0; i<N; ++i)
        scanf("%d", &C[i]);

    memset(dp, -1, sizeof(int)*(M+1));
    dp[0] = 0;
    for(int i=0; i<N; ++i) {
        s += A[i]*C[i];
        for(int j=0; j<A[i]; ++j)
            dp[j] = dp[j]>=0 ? 0 : -1;
        ll bound = min((ll)M, s);
        for(int j=A[i]; j<=bound; ++j) {
            int n = -1;
            if(dp[j]>=0)
                n = 0;
            else if(dp[j-A[i]]>=0 && dp[j-A[i]]<C[i])
                n = dp[j-A[i]] + 1;
            if(dp[j]==-1 && n!=-1)
                ++ret;
            dp[j] = n;
        }
    }
    return ret;
}

int solve2() {
    pii coin[MAXN];
    int ret=0, a, c;
    ll s = 0, bound;

    for(int i=0; i<N; ++i)
        scanf("%d", &coin[i].first);
    for(int i=0; i<N; ++i)
        scanf("%d", &coin[i].second);
    sort(coin, coin+N, greater<pii>());

    memset(dp, -1, sizeof(int)*(M+1));
    dp[0] = 0;
    for(int i=0; i<N; ++i) {
        a = coin[i].first;
        c = coin[i].second;
        s += a*c;
        bound = M<s ? M : s;
        for(int j=a; j<=bound; ++j) {
            int n = -1;
            if(dp[j]>=0)
                n = 0;
            else if(dp[j-a]>=0 && dp[j-a]<c)
                n = dp[j-a] + 1;
            if(dp[j]==-1 && n!=-1)
                ++ret;
            dp[j] = n;
        }
    }
    return ret;
}

int main() {
    while(true) {
        scanf("%d%d", &N, &M);
        if(N==0 && M==0) break;
        printf("%d\n", solve2());
    }
}