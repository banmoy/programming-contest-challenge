// Sample Input
// 3 6
// 10 1
// 1 100
// 5 120
// 
// Sample Output
// 111

#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define MAXN 21

ll N, C;
pll coin[MAXN];
ll need[MAXN];


ll solve() {
    ll ret=0, left, i, j;
    sort(coin, coin+N);
    while(N && coin[N-1].first>=C)
        ret += coin[--N].second;
    while(true) {
        left = C;
        memset(need, 0, sizeof(ll)*N);

        for(i=N-1; i>=0 && left; --i) {
            if(coin[i].first<=left && coin[i].second) {
                j = min(coin[i].second, left/coin[i].first);
                left -= coin[i].first * j;
                need[i] = j;
            }
        }

        if(left>0) {
            for(i=0; i<N && !(coin[i].second-need[i]); ++i);
            if(i==N) break;
            ++need[i];
        }

        j = LLONG_MAX;
        for(i=0; i<N; ++i)
            if(need[i])
                j = min(j, coin[i].second/need[i]);

        ret += j;
        for(i=0; i<N; ++i)
            if(need[i])
                coin[i].second -= need[i]*j;
    }
    return ret;
}


int main() {
    scanf("%lld%lld", &N, &C);
    for(int i=0; i<N; ++i)
        scanf("%lld%lld", &coin[i].first, &coin[i].second);
    printf("%lld\n", solve());
    return 0;
}