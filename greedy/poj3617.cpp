// Sample Input
// 6
// A
// C
// D
// B
// C
// B
// 
// Sample Output
// ABCBCD

#include <cstdio>

using namespace std;

#define MAXN 2001

int N;
char ocow[MAXN], ncow[MAXN];


void solve() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%1s", ocow+i);
    int i=0, j=N-1, k=0;
    while(i<=j) {
        int p=i, q=j;
        while(p<=q && ocow[p]==ocow[q])
            ++p, --q;
        if(p<=q && ocow[p]<ocow[q])
            ncow[k++] = ocow[i++];
        else
            ncow[k++] = ocow[j--];
    }
    for(int n=0; n<N; ++n) {
        printf("%c", ncow[n]);
        if(n%80 == 79) printf("\n");
    }
    if(N%80) printf("\n");
}

int main() {
    solve();
}