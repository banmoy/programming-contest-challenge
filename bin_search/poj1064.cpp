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
#include <iomanip>

using namespace std;

int N, K;
int cable[10001];

bool isvalid(int l) {
    int k = 0, p = N-1;
    while(p>=0 && cable[p]>=l && k<K)
        k += cable[p--]/l;
    return k>=K;
}

float solve() {
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

int main() {
    cin >> N >> K;
    float tmp;
    for(int i=0; i<N; ++i) {
        cin >> tmp;
        cable[i] = tmp * 100;
    }
    cout << fixed << setprecision(2) << solve() << endl;
}