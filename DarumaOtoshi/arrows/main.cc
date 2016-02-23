#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 514

int dp[MAX][MAX];

int solve(int l, int r, vector<int> &A)
{
    if (l >= r) return 0;
    int &res = dp[l][r];
    if (res != -1) {
        return res;
    }
    for (int i = l; i <= r-1; i += 2) {
        res = max(res, solve(l, i-1, A) + solve(i+2, r, A) + A[i]*A[i+1]);
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, N-1, A) << endl;
    return 0;
}
