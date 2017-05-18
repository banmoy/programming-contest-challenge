// Sample Input
// 4 16
// 
// Sample Output
// 3 1 2 4

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 11

int N, S;
int d1[MAXN];
int d2[MAXN];

bool game() {
    memcpy(d2, d1, sizeof(int)*N);
    for(int i=N; i>1; --i) {
        for(int j=0; j+1<i; ++j) {
            d2[j] += d2[j+1];
        }
    }
    return d2[0] == S;
}

void solve() {
    for(int i=0; i<N; ++i)
        d1[i] = i+1;
    while(true) {
        if(game()) return;
        next_permutation(d1, d1+N);
    }
}

int main() {
    scanf("%d%d", &N, &S);
    solve();
    for(int i=0; i+1<N; ++i)
        printf("%d ", d1[i]);
    printf("%d\n", d1[N-1]);
    return 0;
}