// Sample Input
// 12 4 2
// 1 2 8
// 10 12 19
// 3 6 24
// 7 10 31
// 
// Sample Output
// 43

#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAXM 1010

struct Interval {
    int s;
    int e;
    ll eff;
};

bool comp(const Interval& it1, const Interval& it2) {
    return it1.e < it2.e;
}

int N, M, R;
Interval inter[MAXM];
int end[MAXM];
ll dp[MAXM];

ll solve() {
    sort(inter, inter+M, comp);
    end[0] = INT_MIN;
    dp[0] = 0;
    for(int i=0; i<M; ++i) {
        int pe = inter[i].s-R;
        int j = upper_bound(end, end+i+1, pe)-end-1;
        end[i+1] = inter[i].e;
        dp[i+1] = max(dp[j]+inter[i].eff, dp[i]);
    }
    return dp[M];
}

int main() {
    scanf("%d%d%d", &N, &M, &R);
    for(int i=0; i<M; ++i)
        scanf("%d%d%lld", &inter[i].s, &inter[i].e, &inter[i].eff);
    printf("%lld\n", solve());
    return 0;
}