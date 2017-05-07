// Sample Input
// 0 3
// 10 20 20
// 10 7
// 70 30 1 7 15 20 50
// -1 -1
// 
// Sample Output
// 2
// 4

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1001

int N, R;
int pos[MAXN];

int solve() {
    sort(pos, pos+N);
    int s=0, e, ret=0;
    while(s<N) {
        ++ret;
        e = s + 1;
        while(e<N && pos[e]-pos[s]<=R) ++e;
        s = e-1;
        while(e<N && pos[e]-pos[s]<=R) ++e;
        s = e;
    }
    return ret;
}

int main() {
    while(true) {
        scanf("%d%d", &R, &N);
        if(R==-1 && N==-1) break;
        for(int i=0; i<N; ++i)
            scanf("%d", &pos[i]);
        printf("%d\n", solve());
    }
}