// Sample input
// 5 3
// 1
// 2
// 8
// 4
// 9
//
// Sample output
// 3

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int N, C;
long stall[100001];

bool isvalid(long d) {
    int c=1, p=0;
    for(int i=1; i<N && c<C; ++i) {
        if(stall[i]-stall[p]>=d) {
            ++c;
            p = i;
        }
    }
    return c==C;
}

long solve() {
    sort(stall, stall+N);
    long i=0, j=stall[N-1]-stall[0], m=0, d;
    while(i<=j) {
        d = (i+j)/2;
        if(isvalid(d)) {
            m = d;
            i = d+1;
        } else
            j = d-1;
    }
    return m;
}

int main() {
    scanf("%d%d", &N, &C);
    for(int i=0; i<N; ++i)
        scanf("%ld", &stall[i]);
    printf("%ld\n", solve());
}