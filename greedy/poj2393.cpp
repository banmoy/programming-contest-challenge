// Sample Input
// 4 5
// 88 200
// 89 400
// 97 300
// 91 500
// 
// Sample Output
// 126900

#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAXN 10001

ll N, S;
ll C[MAXN], Y[MAXN];

ll solve() {
    for(int i=0; i<N; ++i) {
        scanf("%lld%lld", &C[i], &Y[i]);
        C[i] += (N-1-i) * S;
    }

    ll ret=0, minc=LLONG_MAX, d=(N-1)*S;
    for(int i=0; i<N; ++i) {
        minc = min(minc, C[i]);
        ret += Y[i] * (minc-d);
        d -= S;
    }
    return ret;
}

int main() {
    scanf("%lld%lld", &N, &S);
    printf("%lld\n", solve());
    return 0;
}