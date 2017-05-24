// Sample Input
// 3 
// 5 
// 4 9 5 2 2 1 3 5 1 4 
// 3 
// 2 2 1 1 2 2 
// 3 
// 1 3 2 2 3 1 
// 
// Sample Output
// 2
// 1
// 3

#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 5001
#define INF 0x3f3f3f3f

int T, N;
pii stick[MAXN];
int dp[MAXN];

bool comp(const pii& p1, const pii& p2) {
    return p1.first>p2.first || (p1.first==p2.first && p1.second>p2.second);
}

int solve1() {
    int ret = 0;
    sort(stick, stick+N);
    for(int i=0; i<N; ++i) {
        dp[i] = 1;
        for(int j=0; j<i; ++j) {
            if(stick[i].second < stick[j].second)
                dp[i] = max(dp[i], dp[j]+1);
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}

int solve2() {
    memset(dp, INF, sizeof(int)*(N+1));
    sort(stick, stick+N, comp);
    for(int i=0; i<N; ++i) {
        *lower_bound(dp, dp+N, stick[i].second) = stick[i].second;
    }
    return lower_bound(dp, dp+N, INF) - dp;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i=0; i<N; ++i)
            scanf("%d%d", &stick[i].first, &stick[i].second);
        // printf("%d\n", solve1());
        printf("%d\n", solve2());
    }
    return 0;
}