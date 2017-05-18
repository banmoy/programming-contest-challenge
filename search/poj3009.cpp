// Sample Input
// 2 1
// 3 2
// 6 6
// 1 0 0 2 1 0
// 1 1 0 0 0 0
// 0 0 0 0 0 3
// 0 0 0 0 0 0
// 1 0 0 0 0 1
// 0 1 1 1 1 1
// 6 1
// 1 1 2 1 1 3
// 6 1
// 1 0 2 1 1 3
// 12 1
// 2 0 1 1 1 1 1 1 1 1 1 3
// 13 1
// 2 0 1 1 1 1 1 1 1 1 1 1 3
// 0 0
// 
// Sample Output
// 1
// 4
// -1
// 4
// 10
// -1

#include <cstdio>
#include <queue>

using namespace std;


#define MAXW 21
#define MAXH 21

int H, W, sx, sy, gx, gy;
int mat[MAXH][MAXW];
int move;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};


bool valid(int x, int y) {
    return x>=0 && x<H && y>=0 && y<W;
}

void dfs(int x, int y, int mov) {
    ++mov;
    if(mov>10) return;
    for(int i=0; i<4; ++i) {
        int xx=x+dx[i], yy=y+dy[i];
        if(valid(xx, yy) && mat[xx][yy]==1) continue;
        while(valid(xx, yy) && mat[xx][yy]==0) {
            if(xx==gx && yy==gy) {
                if(move==-1 || move>mov)
                    move = mov;
                return;
            }
            xx += dx[i];
            yy += dy[i];
        }
        if(valid(xx, yy)) {
            mat[xx][yy] = 0;
            dfs(xx-dx[i], yy-dy[i], mov);
            mat[xx][yy] = 1;
        }
    }
}

int solve() {
    move = -1;
    dfs(sx, sy, 0);
    return move;
}

int main() {
    while(true) {
        scanf("%d%d", &W, &H);
        if(W==0 && H==0) break;
        for(int i=0; i<H; ++i) {
            for(int j=0; j<W; ++j) {
                scanf("%d", &mat[i][j]);
                if(mat[i][j]==2) {
                    mat[i][j] = 0;
                    sx = i, sy = j;
                } else if(mat[i][j]==3) {
                    mat[i][j] = 0;
                    gx = i, gy = j;
                }
            }
        }
        printf("%d\n", solve());
    }
    return 0;
}