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

#define MAXN 1001

int N, D, D2;
pii island[MAXN];

double bound(pii p) {
    int x = p.first, y = p.second;
    return x + sqrt(D2-y*y);
}

double dist(pii p, double c) {
    int dx = p.first-c, dy = p.second;
    return sqrt(dx*dx + dy*dy);
}

int solve() {
    bool no = false;
    int x, y, i, j, ret;
    double c, c1;
    for(i=0; i<N; ++i) {
        scanf("%d%d", &x, &y);
        island[i] = pii(x, y);
        if(y>D) no = true;;
    }
    if(no) return -1;
    sort(island, island+N);
    for(i=1, j=0; i<N; ++i) {
        if(island[i].first == island[j].first)
            island[j] = island[i];
        else
            island[++j] = island[i];
    }
    N = j+1;
    D2 = D*D;
    ret = 0;
    for(i=0; i<N; ) {
        c = bound(island[i++]);
        while(i<N && island[i].first<=c) {
            c1 = bound(island[i]);
            if(c1<c) {
                c = c1;
                break;
            }
            ++i;
        }
        while(i<N && dist(island[i], c)<=D) ++i;
        ++ret;
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