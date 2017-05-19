// Sample Input
// 7 2
// 2
// 1
// 1
// 2
// 2
// 1
// 1
// 
// Sample Output
// 6

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXT 1000
#define MAXW 30

int T, W;
int apple[MAXT];

// dp[i][j][w]: 时刻i，初始位置在第j(0下标开始)棵树下，并且剩余移动次数为w时能获得的最大苹果数
// 0<=i<=T-1, j=0,1, 0<=w<=W
//               |---- dp[i+1][j][w]+1 apple[i]==j+1
// dp[i][j][w] = |
//               |---- max(dp[i+1]dp[1-j][w], dp[i+1][j][w-1]+1) apple[i]=2-j
int solve() {
    // [apple][person][walk]
    int dp[MAXT][2][MAXW+1];
    for(int i=T-1; i>=0; --i) {
        int j1, j2;
        for(int w=0; w<=W; ++w) {
            j1 = apple[i]-1;
            j2 = 2-apple[i];
            if(i==T-1) {
                dp[i][j1][w] = 1;
                dp[i][j2][w] = w>0 ? 1 : 0;
            } else {
                dp[i][j1][w] = dp[i+1][j1][w] + 1;
                dp[i][j2][w] = max(dp[i+1][j2][w], (w>0 ? dp[i+1][j1][w-1]+1 : 0));
            }
        }
    }
    return dp[0][0][W];
}

int main() {
    scanf("%d%d", &T, &W);
    for(int i=0; i<T; ++i)
        scanf("%d", &apple[i]);
    printf("%d\n", solve());
    return 0;
}
