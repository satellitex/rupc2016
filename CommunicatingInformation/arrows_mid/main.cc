#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i]; a[i]--;
    }
    int res = max(a[0], n-a[m-1]-1); 
    for (int i = 1; i < m; i++) {
        res = max(res, (a[i]-a[i-1])/2);
    }
    cout << res << endl;
    return 0;
}
