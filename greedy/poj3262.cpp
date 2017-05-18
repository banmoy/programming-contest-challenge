// Sample Input
// 6
// 3 1
// 2 5
// 2 3
// 3 2
// 4 1
// 1 6
// 
// Sample Output
// 86

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define MAXN 100001

ll N;
pll cow[MAXN];

bool comp(const pll& c1, const pll& c2) {
    return c1.first*c2.second < c1.second*c2.first;
}

ll solve() {
    ll ret=0, s=0;
    sort(cow, cow+N, comp);
    for(int i=N-1; i>=0; --i) {
        ret += s*2*cow[i].first;
        s += cow[i].second;
    }
    return ret;
}

int main() {
    scanf("%lld", &N);
    for(int i=0; i<N; ++i)
        scanf("%lld%lld", &cow[i].first, &cow[i].second);
    printf("%lld\n", solve());
}