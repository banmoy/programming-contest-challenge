// Sample Input
// 4
// 6
// 4
// 2
// 6
// 3
// 1
// 5
// 10
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 1
// 8
// 8
// 7
// 6
// 5
// 4
// 3
// 2
// 1
// 9
// 5
// 8
// 9
// 2
// 3
// 1
// 7
// 4
// 6
// Sample Output
//
// 3
// 9
// 1
// 4

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXP 40001

int T, P;
int map[MAXP];

int solve() {
    int ret = 0;
    for(int i=0; i<P; ++i) {
        int j = upper_bound(map, map+ret, map[i]) - map;
        map[j] = map[i];
        if(j==ret) ++ret;
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &P);
        for(int i=0; i<P; ++i)
            scanf("%d", &map[i]);
        printf("%d\n", solve());
    }
    return 0;
}