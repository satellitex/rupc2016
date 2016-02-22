#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define INF (1<<29)

int main()
{
    int n, m, a;
    cin >> n >> m;
    vector<int> d(n, INF);
    queue<int> Q;
    for (int i = 0; i < m; i++) {
        cin >> a; a--;
        d[a] = 0;
        Q.push(a);
    }
    
    int res = 0;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        int l = v-1, r = v+1;
        if (l >= 0 && d[v] + 1 < d[l]) {
            d[l] = d[v] + 1;
            Q.push(l);
            res = max(res, d[l]);
        }
        if (r < n && d[v] + 1 < d[r]) {
            d[r] = d[v] + 1;
            Q.push(r);
            res = max(res, d[r]);
        }
    }
    cout << res << endl;
    return 0;
}
