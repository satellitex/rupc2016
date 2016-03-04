#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, a, d, M, K;
    cin >> N >> a >> d >> M;
    
    vector<int> arr(N);
    arr[0] = a;
    for (int i = 1; i < N; i++) {
        arr[i] = arr[i-1] + d;
    }
    
    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z; y--; z--;
        if (x == 0) {
            reverse(arr.begin()+y, arr.begin()+z+1);
        } else if (x == 1) {
            for (int j = y; j <= z; j++) {
                arr[j]++;
            }
        } else {
            for (int j = y; j <= z; j++) {
                arr[j] /= 2;
            }
        }
    }
    
    cin >> K; K--;
    cout << arr[K] << endl;
    return 0;
}
