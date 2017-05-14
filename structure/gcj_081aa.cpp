#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAXN 100001

int T, N;
ll v1[MAXN], v2[MAXN];


ll solve() {
    sort(v1, v1+N);
    sort(v2, v2+N);
    ll ret = 0;
    for(int i=0; i<N; ++i)
        ret += v1[i] * v2[N-i-1];
    return ret;
}


int main() {
    scanf("%d", &T);
    for(int i=1; i<=T; ++i) {
        scanf("%d", &N);
        for(int n=0; n<N; ++n)
            scanf("%lld", &v1[n]);;
        for(int n=0; n<N; ++n)
            scanf("%lld", &v2[n]);
        printf("Case #%d: %lld\n", i, solve());
    }
}