#include <bits/stdc++.h>

using namespace std;

int main()
{
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    
    int ux = 0, uy = 0, ud = 0;
    int rx = 0, ry = 1, rd = 0;

    // right down left (up)
    const int dx[] = {+1, +0, -1, +0};
    const int dy[] = {+0, +1, +0, -1};
    
    int adj_count = 0;
    for (int i = 0; i < N; i++) {
        if (p[i] == 0) {
            ux += dx[ud];
            uy += dy[ud];
            if ((ud == 0 && ux == W-1) ||
                (ud == 1 && uy == H-1)) {
                ud++;
            } 
        } else {
            rx += dx[rd];
            ry += dy[rd];
            if ((rd == 0 && rx == W-2) ||
                (rd == 1 && ry == H-2)) {
                rd++;
            }
        }
        for (int j = 0; j < 4; j++) {
            int nx = ux + dx[j];
            int ny = uy + dy[j];
            if (nx == rx && ny == ry) {
                adj_count++;
                break;
            }
        }
    }
    cout << adj_count << endl;
    return 0;
}
