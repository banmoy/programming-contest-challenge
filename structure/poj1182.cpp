/*
 * Sample Input
 * 100 7
 * 1 101 1 
 * 2 1 2
 * 2 2 3 
 * 2 3 3 
 * 1 1 3 
 * 2 3 1 
 * 1 5 5
 * 
 * Sample Output
 * 3
 */

#include <cstdio>

using namespace std;

#define MAXN 50001

int N, K;
int id[3*MAXN], w[3*MAXN];

int root(int i) {
    while(i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void unite(int x, int y) {
    int px = root(x);
    int py = root(y);
    if(w[px]<w[py]) {
        id[px] = id[py];
        w[py] += w[px];
    } else {
        id[py] = id[px];
        w[px] += w[py];
    }
}

bool find(int x, int y) {
    return root(x) == root(y);
}

int solve() {
    int d, x, y;
    int ret = 0;
    for(int i=1; i<=N; ++i) {
        id[i] = i;
        id[i+N] = i+N;
        id[i+2*N] = i+2*N;
        w[i] = 1;
        w[i+N] = 1;
        w[i+2*N] = 1;
    }
    for(int i=0; i<K; ++i) {
        scanf("%d%d%d", &d, &x, &y);
        if(x>N || y>N) {
            ++ret;
        } else if(d==1) {
            if(find(x, y+N) || find(x, y+2*N))
                ++ret;
            else {
                unite(x, y);
                unite(x+N, y+N);
                unite(x+2*N, y+2*N);
            }
        } else {
            if(find(x, y) || find(x, y+2*N))
                ++ret;
            else {
                unite(x, y+N);
                unite(x+N, y+2*N);
                unite(x+2*N, y);
            }
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &N, &K);
    printf("%d\n", solve());
}