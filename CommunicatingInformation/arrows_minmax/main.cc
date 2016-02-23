#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 100000

int main()
{
    int n, m, a;
    cin >> n >> m;
    vector<int> min_times(n, INF);
    for (int i = 0; i < m; i++) {
        cin >> a; a--;
        min_times[a] = 0;
    }
    
    int res = 0;
    for (int i = 1; i < n; i++) {
        min_times[i] = min(min_times[i], min_times[i-1] + 1);
    }

    for (int i = n-2; i >= 0; i--) {
        min_times[i] = min(min_times[i], min_times[i+1] + 1);
    }

    for (int i = 0; i < n; i++) {
        res = max(res, min_times[i]);
    }
    
    cout << res << endl;
    return 0;
}
