// Sample Input
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 2 1
// 1 1 1 1 1
//
// Sample Output
// 15

#include <cstdio>
#include <set>

using namespace std;

#define N 5

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int grid[N][N];
set<int> ss;

bool valid(int x, int y) {
    return x>=0 && x<N && y>=0 && y<N;
}

void dfs(int x, int y, int s, int hop) {
    s = s*10 + grid[x][y];
    if(hop==N) {
        ss.insert(s);
        return;
    }
    for(int i=0; i<4; ++i) {
        int xx = x+dx[i], yy = y+dy[i];
        if(valid(xx, yy))
            dfs(xx, yy, s, hop+1);
    }
}

int solve() {
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            dfs(i, j, 0, 0);
    return ss.size();
}

int main() {
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            scanf("%d", &grid[i][j]);
    printf("%d\n", solve());
    return 0;
}