#include <bits/stdc++.h>

using namespace std;

#define MAX 514

int dp[MAX][MAX];
vector<int> A;

int solve(int l, int r)
{
    if (l >= r) return 0;
    
    int &res = dp[l][r];    
    if (res != -1) return res;
    
    res = 0;
    for (int i = l+1, j = 0; i <= r; i++, j++) {
        if ((i-l)&1) res = max(res, solve(l, i) + solve(i+1, r));           
        res = max(res, solve(l+1, i-1) + solve(i, r-1) + A[l]*A[r]);
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, N-1) << endl;
    return 0;
}
