// Sample Input
// 3
// 7 40 3
// 5 23 8
// 2 52 6
// 
// Sample Output
// 48

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXK 401
#define MAXA 40001

struct Elevator {
    int h;
    int c;
    int a;
};

bool operator < (const Elevator& e1, const Elevator& e2) {
    return e1.a < e2.a;
}

int N;
Elevator ele[MAXK];
int dp[MAXA];

// 多重背包
int solve() {
    int a, h, c;
    sort(ele, ele+N);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=0; i<N; ++i) {
        h = ele[i].h, a = ele[i].a, c = ele[i].c;
        for(int j=0; j<=a; ++j) {
            if(dp[j]>=0) {
                dp[j] = 0;
            } else if(j>=h && dp[j-h]>=0 && dp[j-h]<c) {
                dp[j] = dp[j-h] + 1;
            }
        }
    }
    for(int i=ele[N-1].a; i>=0; --i)
        if(dp[i]>=0) return i;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d%d%d", &ele[i].h, &ele[i].a, &ele[i].c);
    printf("%d\n", solve());
    return 0;
}