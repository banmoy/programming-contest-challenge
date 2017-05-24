// Sample Input
// 7
// 1
// 3
// 2
// 4
// 5
// 3
// 9
// 
// Sample Output
// 3

#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAXN 2001
#define INF 0x3f3f3f3f

int N, M;
int A[MAXN];

// 每个元素最终取值为A中的某个值，思路为
// 1. 将A拷贝一份得到B
// 2. 将B进行排序，非递减序列按非递减排序，非递增序列按非递增排序
// 3. dp[i][j] : 前i个元素按非递减/非递增排序并以B[j]结尾的最小代价
//    dp[i][j] = min(dp[i-1][k]+abs(A[i]-B[j])) 0<=k<=j
ll solve() {
    int B[MAXN];
    ll dp[MAXN], ret;

    memcpy(B, A, sizeof(int)*N);
    sort(B, B+N);
    M = unique(B, B+N) - B;

    memset(dp, 0, sizeof(ll)*M);
    for(int i=0; i<N; ++i) {
        ll pre = LLONG_MAX;
        for(int j=0; j<M; ++j) {
            pre = min(pre, dp[j]);
            dp[j] = pre + abs(A[i]-B[j]);
        }
    }
    ret = *min_element(dp, dp+M);

    memset(dp, 0, sizeof(ll)*M);
    for(int i=0; i<N; ++i) {
        ll pre = LLONG_MAX;
        for(int j=M-1; j>=0; --j) {
            pre = min(pre, dp[j]);
            dp[j] = pre + abs(A[i]-B[j]);
        }
    }
    ret = min(*min_element(dp, dp+M), ret);

    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d", &A[i]);
    printf("%lld\n", solve());
    return 0;
}