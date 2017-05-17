// Sample Input
// 4
// 0 0 2
// 2 1 2
// 1 1 2
// 0 3 5
// 
// Sample Output
// 5

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;


#define INF  0x3f3f3f3f
#define MAXX 305
#define MAXY 305

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int M;  
int mat[MAXX][MAXY];

bool valid(int x, int y) {
    return x>=0 && y>=0;
}

int solve() {
    int x, y, t;
    memset(mat, INF, sizeof(mat));
    for(int i=0; i<M; ++i) {
        scanf("%d%d%d", &x, &y, &t);
        mat[x][y] = min(mat[x][y], t);
        for(int k=0; k<4; ++k) {
            int xx=x+dx[k], yy=y+dy[k];
            if(valid(xx, yy))
                mat[xx][yy] = min(mat[xx][yy], t);
        }
    }
    queue<pii> q;
    q.push(pii(-1, 0));
    t = -1;
    while(!q.empty()) {
        ++t;
        int n = q.size();
        while(n--) {
            pii p = q.front();
            q.pop();
            x = p.first, y = p.second;
            for(int j=0; j<4; ++j) {
                int xx=x+dx[j], yy=y+dy[j];
                if(valid(xx, yy) && mat[xx][yy]!=-1) {
                    if(mat[xx][yy] == INF) return t;
                    if(mat[xx][yy]>t)
                        q.push(pii(xx, yy));
                    mat[xx][yy] = -1;
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &M);
    printf("%d\n", solve());
}