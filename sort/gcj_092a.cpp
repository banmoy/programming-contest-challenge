// Sample Input
// 3
// 2
// 10
// 11
// 3
// 001
// 100
// 010
// 4
// 1110
// 1100
// 1100
// 1000
//
// Sample Output
// Case #1: 0
// Case #2: 2
// Case #3: 4

#include <cstdio>
#include <utility>

using namespace std;

#define MAXN 41

int T, N;
int m[MAXN];

int solve() {
    char ch;
    int ret = 0;
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        getchar();
        m[i] = 0;
        for(int j=1; j<=N; ++j) {
            scanf("%c", &ch);
            if(ch == '1') m[i] = j;
        }
    }
    for(int i=1; i<=N; ++i) {
        int j;
        for(j=i; j<=N; ++j)
            if(m[j]<=i)
                break;
        ret += j-i;
        for(;j>i; --j)
            swap(m[j], m[j-1]);
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    for(int t=1; t<=T; ++t) {
        printf("Case #%d: %d\n", t, solve());
    }
}