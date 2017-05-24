// Sample Input
// 4 1
// 0 1
// 0 2
// 0 3
// 0 4
// O 1
// O 2
// O 4
// S 1 4
// O 3
// S 1 4
// 
// Sample Output
// FAIL
// SUCCESS

#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 1010

int N, D, D2;
pii lab[MAXN];
int idx[MAXN];         // idx[i]为负表示未修好
int w[MAXN];

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

bool dist(int i, int j) {
    int dx = lab[i].first-lab[j].first;
    int dy = lab[i].second-lab[j].second;
    return dx*dx + dy*dy <= D2;
}

void init_uf() {
    for(int i=1; i<=N; ++i) {
        idx[i] = -i;
        w[i] = 1;
    }
}

void solve1() {
    char op;
    int a, b;
    int table[MAXN][MAXN]; // table[i]表示与第i个labtop在规定范围内的labtop编号数组
    int cnt[MAXN];         // cnt[i]表示table[i]的大小

    // 预处理距离
    memset(cnt, 0, sizeof(int)*(N+1));
    for(int i=1; i<N; ++i) {
        for(int j=i+1; j<=N; ++j) {
            if(dist(i, j)) {
                table[i][cnt[i]++] = j;
                table[j][cnt[j]++] = i;
            }
        }
    }

    init_uf();

    getchar();
    while(~scanf("%c", &op)) {
        if(op == 'O') {
            scanf("%d", &a);
            if(idx[a] < 0) {
                idx[a] = -idx[a];
                for(int i=0; i<cnt[a]; ++i)
                    if(idx[table[a][i]]>0)
                        unite(a, table[a][i]);
            }
        } else {
            scanf("%d%d", &a, &b);
            if(idx[a]>0 && idx[b]>0 && same(a, b))
                printf("%s\n", "SUCCESS");
            else
                printf("%s\n", "FAIL");
        }
        getchar();
    }
}

void solve2() {
    char op;
    int a, b;

    init_uf();

    getchar();
    while(~scanf("%c", &op)) {
        if(op == 'O') {
            scanf("%d", &a);
            if(idx[a] < 0) {
                idx[a] = -idx[a];
                for(int i=1; i<=N; ++i)
                    if(i!=a && idx[i]>0 && dist(a, i))
                        unite(a, i);
            }
        } else {
            scanf("%d%d", &a, &b);
            if(idx[a]>0 && idx[b]>0 && same(a, b))
                printf("%s\n", "SUCCESS");
            else
                printf("%s\n", "FAIL");
        }
        getchar();
    }
}

int main() {
    scanf("%d%d", &N, &D);
    D2 = D * D;
    for(int i=1; i<=N; ++i)
        scanf("%d%d", &lab[i].first, &lab[i].second);
    // solve1();
    solve2();
    return 0;
}