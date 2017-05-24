// Sample Input
// 3 2
// 3 10
// 2 5
// 1 5
// 6 2
// 4 1
// 
// Sample Output
// 2

#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

#define MAXC 2501
#define MAXL 2501

int C, L;
pii cow[MAXC], bot[MAXL];

int solve() {
    int i, j, ret;
    priority_queue<int, vector<int>, greater<int> > q;

    sort(cow, cow+C);
    sort(bot, bot+L);

    i = j = ret = 0;
    while(j<L && (i<C || !q.empty())) {
        while(i<C && cow[i].first<=bot[j].first) {
            q.push(cow[i].second);
            ++i;
        }
        while(!q.empty() && bot[j].second) {
            if(q.top() >= bot[j].first) {
                ++ret;
                --bot[j].second;
            }
            q.pop();
        }
        ++j;
    }
    return ret;
}

int main() {
    scanf("%d%d", &C, &L);
    for(int i=0; i<C; ++i)
        scanf("%d%d", &cow[i].first, &cow[i].second);
    for(int i=0; i<L; ++i)
        scanf("%d%d", &bot[i].first, &bot[i].second);
    printf("%d\n", solve());
}