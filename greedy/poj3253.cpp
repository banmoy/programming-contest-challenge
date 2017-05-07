// Sample Input
// 3
// 8
// 5
// 8
// 
// Sample Output
// 34

#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef long long ll;

#define MAXN 20001

int N;

ll solve_n2() {
    ll len[MAXN];
    for(int i=0; i<N; ++i)
        scanf("%lld", &len[i]);
    ll ret = 0;
    while(N>1) {
        int m1=0, m2=1;
        if(len[m1] > len[m2])
            swap(m1, m2);
        for(int i=2; i<N; ++i) {
            if(len[i]<len[m1]) {
                m2 = m1;
                m1 = i;
            } else if(len[i]<len[m2]) {
                m2 = i;
            }
        }
        if(m1>m2) swap(m1, m2);
        len[m1] += len[m2];
        len[m2] = len[N-1];
        ret += len[m1];
        --N;
    }
    return ret;
}

ll solve_nlogn() {
    priority_queue<ll, vector<ll>, greater<ll> > q;
    ll l;
    for(int i=0; i<N; ++i) {
        scanf("%lld", &l);
        q.push(l);
    }
    ll ret = 0;
    while(q.size()>1) {
        ll l1 = q.top();
        q.pop();
        ll l2 = q.top();
        q.pop();
        ret += l1 + l2;
        q.push(l1+l2);
    }
    return ret;
}


int main() {
    scanf("%d", &N);
    
    // printf("%lld\n", solve_n2());
    printf("%lld\n", solve_nlogn());
}