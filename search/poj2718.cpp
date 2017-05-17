// Sample Input
// 1
// 0 1 2 4 6 7
// 
// Sample Output
// 28

#include <cstdio>
#include <climits>
#include <cctype>
#include <algorithm>

using namespace std;

#define MAXN 11

int T, N;
int d[MAXN];

int solve() {
    int n=(N>>1), big, small;
    if(N&1) {
        // odd
        big = small = 0;
        for(int i=N-1; i>n; --i)
            small = small * 10 + d[i];
        if(d[0]==0) d[0] = d[1], d[1] = 0;
        for(int i=0; i<=n; ++i)
            big = big * 10 + d[i];
        return big-small;
    } else {
        // even
        if(N==2) return d[1]-d[0];
        int diff = INT_MAX;
        for(int i=(d[0]==0); i+1<N; ++i) {
            int j, k;
            small = d[i];
            j = N-1, k = 0;
            while(k+1<n) {
                if(j==i || j==i+1) {
                    --j;
                    continue;
                }
                small = small * 10 + d[j];
                --j;
                ++k;
            }
            big = d[i+1];
            j = 0, k = 0;
            while(k+1<n) {
                if(j==i || j==i+1) {
                    ++j;
                    continue;
                }
                big = big * 10 + d[j];
                ++j;
                ++k;
            }
            diff = min(diff, big-small);
        }
        return diff;
    }
}

int main() {
    char buf[30];
    int i;
    scanf("%d", &T);
    getchar();
    while(T--) {
        gets(buf);
        N = i = 0;
        while(buf[i]!='\0') {
            if(isdigit(buf[i]))
                d[N++] = buf[i]-'0';
            ++i;
        }
        printf("%d\n", solve());
    }
    return 0;
}