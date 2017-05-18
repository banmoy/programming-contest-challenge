// Sample Input
// 0 0 4 0 0 1 
// 7 5 1 0 0 0 
// 0 0 0 0 0 0 
// 
// Sample Output
// 2 
// 1 

#include <cstdio>
#include <algorithm>

using namespace std;

int N = 6;
int num[7];

int solve1() {
    int ret=0, i, j;

    // 6*6
    ret += num[6];

    // 5*5
    ret += num[5];
    num[1] -= min(num[1], 11*num[5]);

    // 4*4
    ret += num[4];
    i = min(num[2], 5*num[4]);
    num[2] -= i;
    num[1] -= min(num[1], num[4]*20-i*4);

    // 3*3
    ret += (num[3]+3)/4;
    i = num[3]%4;
    int m[4] = {0, 5, 3, 1};
    if(i) {
        j = min(num[2], m[i]);
        num[2] -= j;
        num[1] -= min(num[1], 36-i*9-j*4);
    }

    // 2*2
    ret += (num[2]+8)/9;
    i = num[2]%9;
    if(i)
        num[1] -= min(num[1], 36-i*4);

    // 1*1
    ret += (num[1]+35)/36;

    return ret;
}

int solve2() {
    int ret, i, j;
    int m3[4] = {0, 5, 3, 1};
    ret = num[6] + num[5] + num[4] + (num[3]+3)/4;
    i = num[4]*5 + m3[num[3]%4];
    ret += i<num[2] ? ((num[2]-i)+8)/9 : 0;
    for(i=0, j=2; j<=6; ++j)
        i += num[j]*j*j;
    i = 36*ret - i;
    ret += i<num[1] ? ((num[1]-i)+35)/36 : 0;
    return ret;
}

int main() {
    bool end;
    while(true) {
        end = true;
        for(int i=1; i<=N; ++i) {
            scanf("%d", &num[i]);
            if(num[i]) end = false;
        }
        if(end) break;
        printf("%d\n", solve2());
    }
    return 0;
}