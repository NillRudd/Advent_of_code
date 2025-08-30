#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include <climits>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <string>
#include <limits>


enum Dir { UP=0, RIGHT=1, DOWN=2, LEFT=3, NONE=4 };

struct State {
    int cost, x, y;
    Dir dir;
    bool operator<(State const& o) const { return cost > o.cost; }
};

int solve(const std::vector<std::string>& grid, int sx, int sy, int ex, int ey) {
    int H = grid.size(), W = grid[0].size();
    const int INF = std::numeric_limits<int>::max() / 2;
    
    std::vector<std::vector<std::array<int,5>>> dist(
        H, std::vector<std::array<int,5>>(W)
    );
    for (auto &row : dist)
        for (auto &arr : row)
            arr.fill(INF);

    std::priority_queue<State> pq;
    dist[sx][sy][NONE] = 0;
    pq.push({0, sx, sy, NONE});

    
    int dx[4] = {-1, 0, +1,  0};
    int dy[4] = { 0, +1,  0, -1};

    while (!pq.empty()) {
        auto [c, x, y, dir] = pq.top();
        pq.pop();
        if (c > dist[x][y][dir]) continue;
        if (x == ex && y == ey) return c;

        for (int nd = 0; nd < 4; ++nd) {
            int nx = x + dx[nd], ny = y + dy[nd];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (grid[nx][ny] == '#') continue;
            
            int step = (dir == NONE || dir == nd) ? 1 : 1001;
            int nc = c + step;
            if (nc < dist[nx][ny][nd]) {
                dist[nx][ny][nd] = nc;
                pq.push({nc, nx, ny, static_cast<Dir>(nd)});
            }
        }
    }

    return -1; 
}

int main(){
    
    std::vector<std::string> grid;
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        grid.push_back(line);
    }

    
    int sx=-1, sy=-1, ex=-1, ey=-1;
    for (int i = 0; i < (int)grid.size(); ++i) {
        for (int j = 0; j < (int)grid[i].size(); ++j) {
            if (grid[i][j] == 'S') { sx = i; sy = j; }
            if (grid[i][j] == 'E') { ex = i; ey = j; }
        }
    }

    int result = solve(grid, sx, sy, ex, ey);
    std::cout << result << "\n";
    return 0;
}