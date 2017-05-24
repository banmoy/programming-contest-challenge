// Sample Input
// 3 5 70
// 30 25
// 50 21
// 20 20
// 5 18
// 35 30
// 
// Sample Output
// 35

#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

#define MAXC 100001

int N, C, F;
pii cow[MAXC];

int solve1() {
    int left[MAXC], right[MAXC];
    int s, f, n, ret;
    priority_queue<int> q;

    n = N>>1;
    sort(cow, cow+C);

    // left
    s = 0;
    for(int i=0; i<n; ++i) {
        s += cow[i].second;
        q.push(cow[i].second);
    }
    for(int i=n; i+n<C; ++i) {
        left[i] = s;
        f = cow[i].second;
        if(q.empty() || q.top()>f) {
            if(!q.empty()) {
                s -= q.top();
                q.pop();
            }
            q.push(f);
            s += f;
        }
    }

    // right
    q = priority_queue<int>();
    s = 0;
    for(int i=C-1; i>=C-n; --i) {
        s += cow[i].second;
        q.push(cow[i].second);
    }
    for(int i=C-n-1; i>=n; --i) {
        right[i] = s;
        f = cow[i].second;
        if(q.empty() || q.top()>f) {
            if(!q.empty()) {
                s -= q.top();
                q.pop();
            }
            q.push(f);
            s += f;
        }
    }

    for(int i=C-n-1; i>=n; --i)
        if(left[i]+right[i]+cow[i].second <= F)
            return cow[i].first;
    return -1;
}

int solve2() {
    int left[MAXC];
    int s, f, n, ret;
    priority_queue<int> q;

    n = N>>1;
    sort(cow, cow+C);

    // left
    s = 0;
    for(int i=0; i<n; ++i) {
        s += cow[i].second;
        q.push(cow[i].second);
    }
    for(int i=n; i+n<C; ++i) {
        left[i] = s;
        f = cow[i].second;
        if(q.empty() || q.top()>f) {
            if(!q.empty()) {
                s -= q.top();
                q.pop();
            }
            q.push(f);
            s += f;
        }
    }

    // right
    q = priority_queue<int>();
    s = 0;
    for(int i=C-1; i>=C-n; --i) {
        s += cow[i].second;
        q.push(cow[i].second);
    }
    for(int i=C-n-1; i>=n; --i) {
        if(left[i]+cow[i].second+s <= F)
            return cow[i].first;
        f = cow[i].second;
        if(q.empty() || q.top()>f) {
            if(!q.empty()) {
                s -= q.top();
                q.pop();
            }
            q.push(f);
            s += f;
        }
    }

    return -1;
}

int main() {
    scanf("%d%d%d", &N, &C,&F);
    for(int i=0; i<C; ++i)
        scanf("%d%d", &cow[i].first, &cow[i].second);
    // printf("%d\n", solve1());
    printf("%d\n", solve2());
    return 0;
}