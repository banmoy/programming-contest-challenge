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
// 8 9
// #########
// #......T#
// #.S.....#
// ##B######
// #.......#
// #.......#
// #.......#
// #########
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
// swwwnnnnnneeesssSSS
// 
// Maze #5
// SSwsseNNNNwnEEEEE

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <utility>

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
bool box[MAXR][MAXC][4];
bool person[MAXR][MAXC];

bool arrive;
string path;

bool valid(int r, int c) {
    return r>=0 && r<R && c>=0 && c<C && mat[r][c]!='#';
}

bool bfs_person(Pos& p, int r, int c) {
    if(p.sr==r && p.sc==c) return true;
    memset(person, 0, sizeof(person));
    queue<Pos> q;
    q.push(Pos(p.sr, p.sc, -1, -1));
    person[p.sr][p.sc] = true;
    while(!q.empty()) {
        Pos ppp = q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            Pos pp = ppp;
            int r1=pp.sr+dr[i], c1=pp.sc+dc[i];
            if(!valid(r1, c1) || (r1==p.br&&c1==p.bc) || person[r1][c1]) continue;
            pp.sr = r1;
            pp.sc = c1;
            pp.pt += walk[i];
            if(r1==r && c1==c) {
                p.pt += pp.pt;
                return true;
            }
            q.push(pp);
            person[r1][c1] = true;
        }
    }
    return false;
}

string solve() {
    if(br==tr && bc==tc) return string();
    memset(box, 0, sizeof(box));
    queue<Pos> q;
    q.push(Pos(sr, sc, br, bc));
    arrive = false;
    while(!q.empty()) {
        int n = q.size();
        while(n--) {
            Pos pp = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                Pos p = pp;
                int bbr=p.br+dr[i], bbc=p.bc+dc[i];
                if(!valid(bbr, bbc) || box[bbr][bbc][i]) continue;
                int ssr=p.br-dr[i], ssc=p.bc-dc[i];
                if(!valid(ssr, ssc) || !bfs_person(p, ssr, ssc)) continue;
                p.sr = p.br;
                p.sc = p.bc;
                p.br = bbr;
                p.bc = bbc;
                p.pt += push[i];
                if(bbr==tr && bbc==tc) { 
                    if(!arrive || path.size()>p.pt.size()) {
                        arrive = true;
                        path = p.pt;
                    }
                    continue;
                }
                box[bbr][bbc][i] = true;
                q.push(p);
            }
        }
        if(arrive) return path;
    }
    return "Impossible.";
}

int main() {
    int n = 0;
    while(true) {
        scanf("%d%d", &R, &C);
        if(R==0 && C==0) break;
        // if(n) printf("\n");
        for(int i=0; i<R; ++i) {
            getchar();
            for(int j=0; j<C; ++j) {
                scanf("%c", &mat[i][j]);
                if(mat[i][j] == 'S')
                    sr = i, sc = j, mat[i][j] = '.';
                else if(mat[i][j] == 'B')
                    br = i, bc = j, mat[i][j] = '.';
                else if(mat[i][j] == 'T')
                    tr = i, tc = j, mat[i][j] = '.';
            }
        }
        printf("Maze #%d\n", ++n);
        printf("%s\n\n", solve().c_str());
    }
    return 0;
}