#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1145

class Union_Find{
  public:
    int par[MAX], rank[MAX], size[MAX];
    
    Union_Find(int N) {
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x, int y)
    {
        x = find(x); y = find(y);
        
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    Union_Find uf(N);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
        uf.unite(a[i], b[i]);
    }

    for (int i = 0; i < M; i++) {
        for (int j = i+1; j < M; j++) {
            if (a[i] == a[j]) {
                uf.unite(b[i], b[j]);
            }
            if (a[i] == b[j]) {
                uf.unite(b[i], a[j]);
            }
            if (b[i] == a[j]) {
                uf.unite(a[i], b[j]);
            }
            if (b[i] == b[j]) {
                uf.unite(a[i], a[j]);
            }
        }
    }
    int tap = 0, slide = 0;
    bool used[MAX] = {0};
    for (int i = 0; i < N; i++) {
        int par = uf.find(i);
        if (used[par]) {
            continue;
        }
        used[par] = 1;
        if (uf.size[par] == 1) {
            tap++;
        } else {
            slide++;
        }
    }
    cout << abs(tap - slide) << endl;
    return 0;
}
