// longest increasing subsequence
//
// Sample Input
// 5
// 4 2 3 1 5
// 
// Sample Output
// 3

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1001

int N;
int num[MAXN];


int solve_n2() {
    int dp[MAXN], ret=0;
    for(int i=0; i<N; ++i) {
        dp[i] = 1;
        for(int j=i-1; j>=0; --j) {
            if(num[i]>num[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}


int solve_nlogn() {
    int ret = 0;
    for(int i=0; i<N; ++i) {
        int l = lower_bound(num, num+ret, num[i]) - num;
        num[l] = num[i];
        if(l==ret) ++ret;
    }
    return ret;
}


int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d", &num[i]);
    // printf("%d\n", solve_n2());
    printf("%d\n", solve_nlogn());
}