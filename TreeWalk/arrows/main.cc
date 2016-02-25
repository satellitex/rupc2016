#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int n;
vector<int> G[MAX];

vector<int> bfs(int s)
{
    vector<int> d(n, MAX); d[s] = 0;
    queue<int> Q; Q.push(s);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < (int)G[v].size(); i++) {
            int to = G[v][i];
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                Q.push(to);
            }
        }
    }
    return d;
}

bool check(int u, int v)
{
    if (n & 1) return 0;
    if (n == 2) return 1;
    
    vector<int> d1, d3, deg(4, 0);
    for (int i = 0; i < n; i++) {
        int d = G[i].size();
        if (d == 1) d1.push_back(i);
        if (d == 3) d3.push_back(i);
        if (d > 3) return 0;        
        ++deg[d];
    }
    if (deg[1] > 4) return 0;
    vector<int> d = bfs((deg[1] != 3 ? d1[0] : d3[0]));
    if (deg[1] == 2) { 
        for (int i = 0; i < n; i++) {
            if (d[i] == (n-1)/2) {
                d1.push_back(i);
                for (int j = 0; j < (int)G[i].size(); j++) {
                    if (d[G[i][j]] == (n-1)/2+1) {
                        d1.push_back(G[i][j]); break;
                    }
                }
                break;
            }
        }
    } else if (deg[1] == 3) {
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (d[i] == n/2) {                    
                j = i; break;
            }
        }
        d = bfs(j);
        int mini = MAX, mv = -1;
        for (int i = 0; i < (int)G[d3[0]].size(); i++) {
            int vv = G[d3[0]][i];
            if (d[vv] < mini) {
                mini = d[vv]; mv = vv;                
            }
        }
        if (mv == -1) return 0;
        d1.push_back(mv);
    }
    if (d1.size() != 4) return 0;
    int ui = -1, vi = -1;
    for (int i = 0; i < 4; i++) {
        if (d1[i] == u) ui = i;
        if (d1[i] == v) vi = i;
    }
    if (ui == -1 || vi == -1) return 0;
    vector<int> w;
    for (int i = 0; i < 4; i++) {
        if (d1[i] != u && d1[i] != v) {
            w.push_back(d1[i]);
        }
    }
    if (w.size() != 2) return 0;
    
    vector<int> us = bfs(d1[ui]), vs = bfs(d1[vi]);
    if (us[w[0]] == vs[w[1]] && us[w[0]] == (n-1)/2) return 1;
    if (us[w[1]] == vs[w[0]] && us[w[1]] == (n-1)/2) return 1;
    return 0;
}

int main()
{
    int u, v, a, b;
    cin >> n >> u >> v; u--; v--;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b; a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }    
    cout << (check(u, v) ? "Yes" : "No") << endl;
    return 0;
}
