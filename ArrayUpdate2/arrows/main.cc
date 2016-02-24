#include <iostream>
#include <vector>

using namespace std;

inline bool between(int l, int m, int r)
{
    return (l <= m && m <= r);
}

int main()
{
    int N, a, d, M, K;
    cin >> N >> a >> d >> M;
    vector<int> x(M), y(M), z(M);
    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i] >> z[i]; y[i]--; z[i]--;
    }
    
    cin >> K; K--;
    // まず、最終的にK項目となるもののスタート位置を求める。
    // これは、クエリを後ろから実行するとわかる。
    for (int i = M-1; i >= 0; i--) {
        if (x[i] != 0 || !between(y[i], K, z[i])) {
            continue;
        }
        K = z[i] - K + y[i];
    }
   
    // 上記で求めたスタート位置(K)とその値(v)を使い、各クエリを実行する。
    // これは、クエリを前から実行する。
    int v = a + K*d;
    for (int i = 0; i < M; i++) {
        if (!between(y[i], K, z[i])) {
            continue;
        }
        
        switch (x[i]) {
            case 0: {
                K = z[i] - K + y[i];
                break;
            }   
            case 1: {
                v++;
                break;
            }   
            case 2: {
                v /= 2;
                break;
            }
        }
    }
    cout << v << endl;
    return 0;
}
