/*
  O(N^4)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

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
    for (int i = l; i <= r-1; i++) {
        for (int j = i+1; j <= r; j+=2) {
            res = max(res, solve(l, i-1) + solve(i+1, j-1) + solve(j+1, r) + A[i]*A[j]);
        }
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
