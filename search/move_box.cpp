// 
// 玩家的walk最少(包括push)
// 
// Sample Input
// 1 7
// SB....T
// 1 7
// SB..#.T
// 7 11
// ###########
// #T##......#
// #.#.#..####
// #....B....#
// #.######..#
// #.....S...#
// ###########
// 8 4
// ....
// .##.
// .#..
// .#..
// .#.B
// .##S
// ....
// ###T
// 0 0
//
// Sample Output
// Maze #1
// EEEEE
//
// Maze #2
// Impossible.
//
// Maze #3
// eennwwWWWWeeeeeesswwwwwwwnNN
//
// Maze #4
// NwnneSSSS

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct Pos {
    int sr;
    int sc;
    int br;
    int bc;
    string pt;
    Pos() {};
    Pos(int i, int j, int p, int q) {
        sr = i, sc = j, br = p, bc = q;
    }
};

#define MAXR 21
#define MAXC 21

// up down left right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char push[] = {'N', 'S', 'W', 'E'};
char walk[] = {'n', 's', 'w', 'e'};

int R, C, tr, tc, sr, sc, br, bc;
char mat[MAXR][MAXC];
bool mem[MAXR][MAXC][MAXR][MAXC];

bool valid(int r, int c) {
    return r>=0 && r<R && c>=0 && c<C && mat[r][c]!='#';
}

string solve() {
    memset(mem, 0, sizeof(mem));
    queue<Pos> q;
    q.push(Pos(sr, sc, br, bc));
    while(!q.empty()) {
        int n =q.size();
        while(n--) {
            Pos pp = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                Pos p = pp;
                int r=p.sr+dr[i], c=p.sc+dc[i];
                if(valid(r, c)) {
                    if(r==p.br && c==p.bc) {
                        int r1=p.br+dr[i], c1=p.bc+dc[i];
                        if(valid(r1, c1)) {
                            if(r1==tr && c1==tc)
                                return p.pt+push[i];
                            if(!mem[r][c][r1][c1]) {
                                mem[r][c][r1][c1] = true;
                                p.sr = r;
                                p.sc = c;
                                p.br = r1;
                                p.bc = c1;
                                p.pt.push_back(push[i]);
                                q.push(p);
                            }
                        }
                    } else {
                        if(!mem[r][c][p.br][p.bc]) {
                            mem[r][c][p.br][p.bc] = true;
                            p.sr = r;
                            p.sc = c;
                            p.pt.push_back(walk[i]);
                            q.push(p);
                        }
                    }
                }
            }
        }
    }
    return string("Impossible.");
}

int main() {
    int n = 0;
    while(scanf("%d%d", &R, &C)) {
        if(R==0 && C==0) break;
        if(n) printf("\n");
        for(int i=0; i<R; ++i) {
            getchar();
            for(int j=0; j<C; ++j) {
                scanf("%c", &mat[i][j]);
                if(mat[i][j] == 'S')
                    sr = i, sc = j;
                else if(mat[i][j] == 'B')
                    br = i, bc = j;
                else if(mat[i][j] == 'T')
                    tr = i, tc = j;
            }
        }
        printf("Maze #%d\n", ++n);
        printf("%s\n", solve().c_str());
    }
    return 0;
}