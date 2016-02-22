#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 300
#define MAX_Y 2000
#define OFFSET 1000

int dp[2][MAX+1][MAX_Y];

void chmax(int &a, int &b)
{
    a = max(a, b);
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    memset(dp, -1, sizeof(dp));    
    dp[0][x][y+OFFSET] = 0;

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= MAX; j++) {
            for (int k = MAX_Y-1; k >= 0; k--) {
                int ni = (i+1)%2, nk = k;
                if (dp[i%2][j][nk] == -1) {
                    continue;
                }
                int cost = dp[i%2][j][nk];
                
                if (j-a[i] >= 0 && nk+b[i] < MAX_Y) {
                    chmax(dp[ni][j-a[i]][nk+b[i]], cost);
                    if (nk+b[i] >= OFFSET) {
                        chmax(res, dp[ni][j-a[i]][nk+b[i]]);                       
                    }
                }
                nk -= c[i];
                if (nk >= 0) {
                    cost += d[i];
                    chmax(dp[ni][j][nk], cost);
                    if (nk >= OFFSET) {
                        chmax(res, dp[ni][j][nk]);   
                    }
                }
            }
        }
        for (int j = 0; j <= MAX; j++) {
            for (int k = 0; k < MAX_Y; k++) {
                dp[i%2][j][k] = -1;
            }
        }
    }
    
    cout << res << endl;
    return 0;
}
