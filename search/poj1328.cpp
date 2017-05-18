// Sample Input
// 3 2
// 1 2
// -3 1
// 2 1
//
// 1 2
// 0 2
//
// 0 0
//
// Sample Output
// Case 1: 2
// Case 2: 1

#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define MAXN 1001

int N, D, D2;
pii island[MAXN];

pdd bound(pii p) {
    int x = p.first, y = p.second;
    double dx = sqrt(D2-y*y);
    return pdd(x-dx, x+dx);
}

int solve() {
    bool no = false;
    int x, y, i, j, ret;
    pdd prev, cur;
    for(i=0; i<N; ++i) {
        scanf("%d%d", &x, &y);
        island[i] = pii(x, y);
        if(y>D) no = true;;
    }
    if(no) return -1;
    sort(island, island+N);
    D2 = D*D;
    ret = 0;
    for(i=0; i<N;) {
        ++ret;
        prev = bound(island[i]);
        ++i;
        while(i<N) {
            cur = bound(island[i]);
            if(cur.first > prev.second) break;
            prev = pdd(max(prev.first, cur.first), min(prev.second, cur.second));
            ++i;
        }
    }
    return ret;
}

int main() {
    int t = 0;
    while(true) {
        scanf("%d%d", &N, &D);
        if(N==0 && D==0) break;
        printf("Case %d: %d\n", ++t, solve());
    }
    return 0;
}