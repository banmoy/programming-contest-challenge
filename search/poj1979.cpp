// Sample Input
// 6 9
// ....#.
// .....#
// ......
// ......
// ......
// ......
// ......
// #@...#
// .#..#.
// 11 9
// .#.........
// .#.#######.
// .#.#.....#.
// .#.#.###.#.
// .#.#..@#.#.
// .#.#####.#.
// .#.......#.
// .#########.
// ...........
// 11 6
// ..#..#..#..
// ..#..#..#..
// ..#..#..###
// ..#..#..#@.
// ..#..#..#..
// ..#..#..#..
// 7 7
// ..#.#..
// ..#.#..
// ###.###
// ...@...
// ###.###
// ..#.#..
// ..#.#..
// 0 0
// 
// Sample Output
// 45
// 59
// 6
// 13

#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define MAXW 21
#define MAXH 21

int H, W, x, y;
char mat[MAXH][MAXW];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int xx, int yy) {
    return xx>=0 && xx<H && yy>=0 && yy<W && mat[xx][yy]=='.';
}

int solve_bfs() {
    int ret = 1;
    queue<pii> q;
    q.push(pii(x, y));
    mat[x][y] = '#';
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int xx = p.first+dx[i], yy = p.second+dy[i];
            if(valid(xx, yy)) {
                ++ret;
                mat[xx][yy] = '#';
                q.push(pii(xx, yy));
            }
        }
    }
    return ret;
}

int dfs(int xx, int yy) {
    int ret = 1;
    mat[xx][yy] = '#';
    for(int i=0; i<4; ++i) {
        int xxx = xx+dx[i], yyy = yy+dy[i];
        if(valid(xxx, yyy))
            ret += dfs(xxx, yyy);
    }
    return ret;
}

int solve_dfs() {
    return dfs(x, y);
}

int main() {
    while(true) {
        scanf("%d%d", &W, &H);
        if(W==0 && H==0) break;
        for(int i=0; i<H; ++i) {
            getchar();
            for(int j=0; j<W; ++j) {
                scanf("%c", &mat[i][j]);
                if(mat[i][j]=='@') {
                    mat[i][j] = '.';
                    x = i, y = j;
                }
            }
        }
        // printf("%d\n", solve_bfs());
        printf("%d\n", solve_dfs());
    }
    return 0;
}