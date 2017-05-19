// Sample Input
// 5
// 7
// 3 8
// 8 1 0
// 2 7 4 4
// 4 5 2 6 5
// 
// Sample Output
// 30

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 360

int N;

// from bottom to up
int solve1() {
    int tri[MAXN][MAXN];

    for(int i=0; i<N; ++i)
        for(int j=0; j<=i; ++j)
            scanf("%d", &tri[i][j]);

    for(int i=N-2; i>=0; --i) {
        for(int j=0; j<=i; ++j) {
            tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
        }
    }

    return tri[0][0];
}

// from up to bottom
int solve2() {
    int tri[MAXN];
    for(int i=0; i<N; ++i) {
        int prev=0;
        tri[i] = 0;
        for(int j=0; j<=i; ++j) {
            int cur = max(prev, tri[j]);
            prev = tri[j];
            scanf("%d", &tri[j]);
            tri[j] += cur;
        }
    }
    int ret = 0;
    for(int i=0; i<N; ++i)
        ret = max(ret, tri[i]);
    return ret;
}

int main() {
    scanf("%d", &N);
    // printf("%d\n", solve1());
    printf("%d\n", solve2());
}
