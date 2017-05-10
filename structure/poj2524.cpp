/*
 * Sample Input
 * 10 9
 * 1 2
 * 1 3
 * 1 4
 * 1 5
 * 1 6
 * 1 7
 * 1 8
 * 1 9
 * 1 10
 * 10 4
 * 2 3
 * 4 5
 * 4 8
 * 5 8
 * 0 0
 *
 * Sample Output
 * Case 1: 1
 * Case 2: 7 
 */

#include <cstdio>

using namespace std;

#define MAXN 50001

int n, m, cnt;
int r[MAXN], w[MAXN];

int root(int x) {
    while(x != r[x]) {
        x = r[r[x]];
        x = r[x];
    }
    return x;
}

void unite(int x, int y) {
    int px = root(x);
    int py = root(y);
    if(w[px] < w[py]) {
        r[px] = py;
        w[py] += w[px];
    } else {
        r[py] = px;
        w[px] += w[py];
    }
}

bool find(int x, int y) {
    return root(x) == root(y);
}

int solve() {
    int x, y, ret = n;
    for(int i=1; i<=n; ++i) {
        r[i] = i;
        w[i] = 1;
    }
    for(int i=0; i<m; ++i) {
        scanf("%d%d", &x, &y);
        if(!find(x, y)) {
            --ret;
            unite(x, y);
        }
    }
    return ret;
}

int main() {
    cnt = 0;
    while(true) {
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        printf("Case %d: %d\n", ++cnt, solve());
    }
}