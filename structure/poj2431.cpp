// Sample Input
// 4
// 4 4
// 5 2
// 11 5
// 15 10
// 25 10
// 
// Sample Output
// 2

#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

#define MAXN 10001

int N;
ll L, P;
pair<ll, ll> stop[MAXN];

int solve() {
    int ret = 0;
    stop[N].first = stop[N].second = 0;
    sort(stop, stop+N+1, greater<pair<ll, ll> >());
    priority_queue<ll> q;
    for(int i=0; i<=N; ++i) {
        ll d = L - stop[i].first;
        while(d>P && !q.empty()) {
            P += q.top();
            q.pop();
            ++ret;
        }
        P -= d;
        if(P<0) return -1;
        q.push(stop[i].second);
        L = stop[i].first;
    }
    return ret;
}


int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%lld%lld", &stop[i].first, &stop[i].second);
    scanf("%lld%lld", &L, &P);
    printf("%d\n", solve());
}