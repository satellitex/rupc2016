#include <bits/stdc++.h>

using namespace std;

#define MAX 300
#define MAX_Y 600
#define OFFSET 300

int dp[2][MAX+1][MAX_Y+1];

void chmax(int &a, int &b)
{
    if (a < b) a = b;
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
        int cur = i%2, next = (i+1)%2;
        for (int j = 0; j <= MAX; j++) {
            for (int k = 0; k <= MAX_Y; k++) {
                if (dp[cur][j][k] == -1) continue;
                
                int gold = dp[cur][j][k];
                chmax(dp[next][j][k], gold);
                if (j-a[i] >= 0) {
                    chmax(dp[next][j-a[i]][k+b[i]], gold);
                    if (k+b[i] >= OFFSET) {
                        chmax(res, dp[next][j-a[i]][k+b[i]]);                       
                    }
                }
                gold += d[i];
                if (k-c[i] >= 0) {
                    chmax(dp[next][j][k-c[i]], gold);
                    if (k-c[i] >= OFFSET) {
                        chmax(res, dp[next][j][k-c[i]]);   
                    }   
                }
            }
        }
        memset(dp[cur], -1, sizeof(dp[cur]));
    }
    cout << res << endl;
    return 0;
}
