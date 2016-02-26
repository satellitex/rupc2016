#include <bits/stdc++.h>
using namespace std;

struct Location {
  int x, y, z;
  Location() {
    return;
  }
  Location(int x, int y, int z) : x(x), y(y), z(z) {
    return;
  }
  bool operator < (const Location &s) const {
    if (x != s.x) return x < s.x;
    if (y != s.y) return y < s.y;
    return z < s.z;
  }
};

const int INF = 1<<28;
const int COST_MAX = 10;
int n;
Location src, dst;

pair<int, int> rotateR(int x, int y, int n) {
  return make_pair(n - y - 1, x);
}

pair<int, int> rotateL(int x, int y, int n) {
  return make_pair(y, n - x - 1);
}

int bfs() {
  map<Location, int> cost;
  queue<Location> que;
  cost[src] = 0;
  que.push(src);
  while (!que.empty()) {
    const Location s = que.front();
    que.pop();
    if (cost[s] >= COST_MAX) continue;
    vector<Location> next;
    pair<int, int> p;
    // x y rotation
    if (s.z != dst.z) {
      p = rotateR(s.x, s.y, n);
      next.push_back(Location(p.first, p.second, s.z));
      p = rotateL(s.x, s.y, n);
      next.push_back(Location(p.first, p.second, s.z));
    }
    // x z rotation
    if (s.y != dst.y) {
      p = rotateR(s.x, s.z, n);
      next.push_back(Location(p.first, s.y, p.second));
      p = rotateL(s.x, s.z, n);
      next.push_back(Location(p.first, s.y, p.second));
    }
    // y z rotation
    if (s.x != dst.x) {
      p = rotateR(s.y, s.z, n);
      next.push_back(Location(s.x, p.first, p.second));
      p = rotateL(s.y, s.z, n);
      next.push_back(Location(s.x, p.first, p.second));
    }
    // move
    {
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          for (int dz = -1; dz <= 1; ++dz) {
            if (abs(dx) + abs(dy) + abs(dz) != 1) continue;
            Location t(s.x + dx, s.y + dy, s.z + dz);
            if (t.x < 0 || t.x >= n) continue;
            if (t.y < 0 || t.y >= n) continue;
            if (t.z < 0 || t.z >= n) continue;
            next.push_back(t);
          }
        }
      }
    }
    // push
    for (int i = 0; i < next.size(); ++i) {
      if (cost.count(next[i])) continue;
      cost[next[i]] = cost[s] + 1;
      que.push(next[i]);
    }
  }

  int res = INF;
  for (map<Location, int>::iterator it = cost.begin();
       it != cost.end(); ++it) {
    Location s = it->first;
    int w = it->second;
    int dist = abs(dst.x - s.x) + abs(dst.y - s.y) + abs(dst.z - s.z);
    res = min(res, w + dist);
  }
  return res;
}

int main() {
  while (cin >> n) {
    cin >> src.x >> src.y >> src.z;
    cin >> dst.x >> dst.y >> dst.z;
    cout << bfs() << endl;
  }
  return 0;
}
