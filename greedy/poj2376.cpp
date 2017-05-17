// Sample Input
// 3 10
// 1 7
// 3 6
// 6 10
// 
// Sample Output
// 2

#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 25001

int N, T;
pii cow[MAXN];


int solve() {
    sort(cow, cow+N);
    int pe=1, c=0, i=0;
    while(i<N && pe<=T) {
        int ne=-1;
        while(i<N && cow[i].first<=pe) {
            ne = ne==-1 ? cow[i].second : max(ne, cow[i].second);
            ++i;
        }
        if(ne < pe) return -1;
        ++c;
        pe = ne+1;
    }
    return pe<=T ? -1 : c;
}


int main() {
    scanf("%d%d", &N, &T);
    int s, e;
    for(int i=0; i<N; ++i) {
        scanf("%d%d", &s, &e);
        cow[i] = pii(s, e);
    }
    printf("%d\n", solve());
    return 0;
}