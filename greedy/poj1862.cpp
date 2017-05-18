// Sample Input
// 3
// 72
// 30
// 50
// 
// Sample Output
// 120.000

#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

#define MAXN 101

int N;

double solve() {
    priority_queue<double> q;
    double w, w1, w2;
    for(int i=0; i<N; ++i) {
        scanf("%lf", &w);
        q.push(w);
    }
    while(q.size()>1) {
        w1 = q.top();
        q.pop();
        w2 = q.top();
        q.pop();
        w = 2 * sqrt(w1 * w2);
        q.push(w);
    }
    return q.top();
}

int main() {
    scanf("%d", &N);
    printf("%.3f\n", (float)solve());
}