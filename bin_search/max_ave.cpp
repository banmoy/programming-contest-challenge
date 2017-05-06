// 有n个物品的重量和价值分别是wi和vi，从中选出k个物品使得单位重量的价值最大
// 1<=k<=n<=10^4
// 1<=wi,vi<=10^6
//
// Sample input
// 3 2(n, k)
// 2 2(w, v)
// 5 3
// 2 1
// 
// Sample output
// 0.75

#include <cstdio>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

#define MAXN 10001

int N, K;
double w[MAXN], v[MAXN], d[MAXN];

bool valid(double ave) {
    for(int i=0; i<N; ++i)
        d[i] = v[i] - w[i]*ave;
    partial_sort(d, d+K, d+N, greater<double>());
    // 必须是0.0，不能是0
    return accumulate(d, d+K, 0.0)>=0;
}

double solve() {
    scanf("%d%d", &N, &K);
    double lb=0, ub=0, b;
    for(int i=0; i<N; ++i) {
        scanf("%lf%lf", &w[i], &v[i]);
        ub = max(ub, v[i]/w[i]);
    }
    for(int i=0; i<100; ++i) {
        b = (lb+ub)/2;
        if(valid(b))
            lb = b;
        else
            ub = b;
    }
    return lb;
}


int main() {
    printf("%.2lf\n", solve());
}