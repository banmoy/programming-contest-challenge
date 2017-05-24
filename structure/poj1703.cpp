// Sample Input
// 1
// 5 5
// A 1 2
// D 1 2
// A 1 2
// D 2 4
// A 1 4
// 
// Sample Output
// Not sure yet.
// In different gangs.
// In the same gang.

#include <cstdio>

using namespace std;

#define MAXN 100010

int T, N, M;
int idx[2*MAXN];
int w[2*MAXN];

int root(int a) {
    while(idx[a] != a) {
        idx[a] = idx[idx[a]];
        a = idx[a];
    }
    return a;
}

void unite(int a, int b) {
    int pa = root(a);
    int pb = root(b);
    if(pa == pb) return;
    if(w[pa] < w[pb]) {
        idx[pa] = pb;
        w[pb] += w[pa];
    } else {
        idx[pb] = pa;
        w[pa] += w[pb];
    }
}

bool same(int a, int b) {
    return root(a)==root(b);
}

void init() {
    for(int i=1; i<=2*N; ++i) {
        idx[i] = i;
        w[i] = 1;
    }
}

void solve() {
    char op;
    int a, b;
    init();
    getchar();
    for(int i=0; i<M; ++i) {
        scanf("%c%d%d", &op, &a, &b);
        if(op == 'D') {
            unite(a, b+N);
            unite(a+N, b);
        } else {
            if(same(a, b))
                printf("%s\n", "In the same gang.");
            else if(same(a, b+N))
                printf("%s\n", "In different gangs.");
            else
                printf("%s\n", "Not sure yet.");
        }
        getchar();
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        solve();
    }
    return 0;
}