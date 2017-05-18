// Sample Input
// 5
// 1 10
// 2 4
// 3 6
// 5 8
// 4 7
//
// Sample Output
// 4
// 1
// 2
// 3
// 2
// 4

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 50001

struct Cow {
    int s;
    int e;
    int id;
};

bool compCow(const Cow& c1, const Cow& c2) {
    return c1.s<c2.s || (c1.s==c2.s && c1.id<c2.id);
}

struct Time {
    int val;
    int se; // 0: start, 1: end
    int id;
};

bool compTime(const Time& t1, const Time& t2) {
    if(t1.val != t2.val) return t1.val < t2.val;
    // 应该先处理开始时间
    if(t1.se != t2.se) return t1.se < t2.se;
    return t1.id < t2.id;
}

int N, T;
int stall[MAXN];

// 按开始时间最小进行排序 + 优先队列
void solve1() {
    Cow cow[MAXN];
    priority_queue<pii, vector<pii>, greater<pii> > q;

    for(int i=0; i<N; ++i) {
        scanf("%d%d", &cow[i].s, &cow[i].e);
        cow[i].id = i;
    }

    sort(cow, cow+N, compCow);
    T = 0;
    for(int i=0; i<N; ++i) {
        pii p;
        if(q.empty() || q.top().first>=cow[i].s) {
            ++T;
            p.second = T;
        } else {
            p = q.top();
            q.pop();
        }
        p.first = cow[i].e;
        stall[cow[i].id] = p.second;
        q.push(p);
    }
}

// 将开始时间和结束时间均排序 + 队列
void solve2() {
    Time t[MAXN<<1];
    queue<int> q;

    for(int i=0; i<N; ++i) {
        int j = i<<1;
        scanf("%d%d", &t[j].val, &t[j+1].val);
        t[j].id = t[j+1].id = i;
        t[j].se = 0;
        t[j+1].se = 1;
    }

    sort(t, t+N*2, compTime);

    for(int i=0; i<(N<<1); ++i) {
        if(t[i].se) {
            q.push(stall[t[i].id]);
        } else {
            int j;
            if(q.empty()) {
                j = ++T;
            } else {
                j = q.front();
                q.pop();
            }
            stall[t[i].id] = j;
        }
    }
}

int main() {
    scanf("%d", &N);

    // solve1();
    solve2();

    printf("%d\n", T);
    for(int i=0; i<N; ++i)
        printf("%d\n", stall[i]);
    return 0;
}