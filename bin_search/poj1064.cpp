// Sample input
// 4 11
// 8.02
// 7.43
// 4.57
// 5.39
//
// Sample output
// 2.00

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

namespace SOLVE_INT {
    int N, K;
    int cable[10001];

    bool isvalid(int l) {
        int k = 0, p = N-1;
        while(p>=0 && cable[p]>=l && k<K)
            k += cable[p--]/l;
        return k>=K;
    }

    float solve() {
        scanf("%d%d", &N, &K);
        float tmp;
        for(int i=0; i<N; ++i) {
            scanf("%f", &tmp);
            cable[i] = tmp * 100;
        }
        sort(cable, cable+N);
        int i=1, j=cable[N-1], l;
        int m = 0;
        while(i<=j) {
            l = (i + j)/2;
            if(isvalid(l)) {
                m = max(m, l);
                i = l+1;
            } else {
                j = l-1;
            }
        }
        return (float)m/100;
    }
}

namespace SOLVE_FLOAT {
    int N, K;
    float cable[10001];

    bool isvalid(float l) {
        int k = 0, p = N-1;
        while(p>=0 && cable[p]>=l && k<K)
            k += (int)(cable[p--]/l);
        return k>=K;
    }

    float solve() {
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; ++i)
            scanf("%f", &cable[i]);
        sort(cable, cable+N);
        float i=0, j=cable[N-1], l;
        for(int loop=0; loop<100; ++loop) {
            // float运算，当且仅当i==j时,l==i==j，否则i<l<j
            // 因此无论是i=l，还是j=l，都会将区间缩小
            l = (i + j)/2;
            if(isvalid(l))
                i = l;
            else
                j = l;
        }
        return (long)(i*100)/100.0;
    }
}

int main() {
    // printf("%.2f\n", SOLVE_INT::solve());
    printf("%.2f\n", SOLVE_FLOAT::solve());
}