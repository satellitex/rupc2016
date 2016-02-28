#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y, z;
    
    Point() {}
    Point(int x, int y, int z) :
        x(x), y(y), z(z) {}
    
    bool operator < (const Point &p) const {
        if (x != p.x) {
            return x < p.x;
        } else if (y != p.y) {
            return y < p.y;
        }
        return z < p.z;        
    }

    bool operator != (const Point &p) const {
        return (x != p.x || y != p.y || z != p.z);
    }
};

istream &operator >> (istream &is, Point &p)
{
    return is >> p.x >> p.y >> p.z;
}

struct State {
    Point p, q;

    State() {}
    State (const Point &p, const Point &q) :
        p(p), q(q) {}

    bool operator < (const State &s) const {
        if (p != s.p) {
            return p < s.p;
        } else {
            return q < s.q;
        }
    }
};

int manhattan_distance(const Point &a, const Point &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

Point roll_x(const Point &p, int N)
{
    return Point(N-p.y-1, p.x, p.z);
}

Point roll_x(const Point &p, int n, int N)
{
    Point np = p;
    for (int i = 0; i < n; i++) {
        np = roll_x(np, N);
    }
    return np;
}

Point roll_y(const Point &p, int N)
{
    return Point(p.x, N-p.z-1, p.y);
}

Point roll_y(const Point &p, int n, int N)
{
    Point np = p;
    for (int i = 0; i < n; i++) {
        np = roll_y(np, N);
    }
    return np;
}

Point roll_z(const Point &p, int N)
{
    return Point(N-p.z-1, p.y, p.x);
}

Point roll_z(const Point &p, int n, int N)
{
    Point np = p;
    for (int i = 0; i < n; i++) {
        np = roll_z(np, N);
    }
    return np;
}

int main()
{
    int N;
    Point s, t;
    cin >> N >> s >> t;
    
    queue<Point> Q;
    Q.push(s);

    map<Point, int> dist; dist[s] = 0;
    
    int mdist = (1<<29);
    while (!Q.empty()) {
        Point p = Q.front(); Q.pop();
        int d = dist[p];

        mdist = min(mdist, manhattan_distance(p, t) + d);

        if (d == 10) {
            continue;
        }

        Point np;
        int x[3] = {1, 0, 0}, y[3] = {0, 1, 0}, z[3] = {0, 0, 1};
        for (int i = 0; i < 3; i++) {
            np = Point(p.x+x[i], p.y+y[i], p.z+z[i]);
            if (dist.count(np) == 0) {
                dist[np] = d + 1;
                Q.push(np);
            }                
        }

        int r[2] = {1, 3};
        if (p.z != t.z) { 
            // x回転  x回転 rev
            for (int i = 0; i < 2; i++) {
                np = roll_x(p, r[i], N);
                if (dist.count(np) == 0) {
                    dist[np] = d + 1;
                    Q.push(np);
                }                
            }
        }
        
        if (p.x != t.x) { 
            // y回転 y回転 rev
            for (int i = 0; i < 2; i++) {
                np = roll_y(p, r[i], N);
                if (dist.count(np) == 0) {
                    dist[np] = d + 1;
                    Q.push(np);
                }                
            }
        }
        
        if (p.y != t.y) {
            // z回転 z回転 rev
            for (int i = 0; i < 2; i++) {
                np = roll_z(p, r[i], N);
                if (dist.count(np) == 0) {
                    dist[np] = d + 1;
                    Q.push(np);
                }                
            }
        }
    }
    cout << mdist << endl;
    return 0;
}
