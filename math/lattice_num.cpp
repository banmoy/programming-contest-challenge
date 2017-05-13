// 给定两个格点P1(x1, y1)和P2(x2, y2)，线段P1P2上除P1和P2外还有几个格点
//
// Sample Input
// 1 11
// 5 3
//
// Sample Output
// 3

#include <cstdio>
#include <cstdlib>

using namespace std;

int x1, y1, x2, y2;

int gcd(int x, int y) {
    int t;
    while(!x) {
        t = x;
        x = y%x;
        y = t;
    }
    return y;
}

int solve() {
    if(x1 == x2)
        return y1==y2 ? 0 : abs(y1-y2)-1;
    if(y1 == y2)
        return abs(x1-x2)-1;
    int b = abs(x1-x2), a = abs(y1-y2);
    return (b-1)/(b/gcd(a, b));
    /* why */
    // return gcd(a, b) - 1;
}

int main() {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", solve());
}