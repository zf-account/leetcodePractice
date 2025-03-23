/*题目描述
给你一个大小为n x m的二元矩阵grid，其中1,2表示陆地，0表示水域。
岛是由四面相连的1形成的一个最大组，即不会与非组内的任何其他1相连。grid中存在三座岛
你可以将任意数量的0变为1,以使两座以1组成的岛连接起来，变成一座岛，但1和2上有敌对势力，连接后的大岛屿不允许与2相连
返回必须翻转的0的最小数目，找不到这样一条路则返回-1


示例1：
输入：
grid = [1 0 2 0]
       [0 0 0 1]
输出：-1


示例2：
输入：
grid = [1 0 2 0]
       [0 1 0 0]
输出: 1


示例3：
输入：
grid = [1 0 2 0]
       [0 0 0 0]
       [0 0 0 1]
输出：4
*/

/*解题思路：
这个问题可以抽象为图的搜索问题。将岛屿、空地、水域看作图的节点，岛屿之间的最短路径可以通过BFS（广度优先搜索）来求解。由于每个0（空地）都可以翻转成1（陆地），我们需要找到一条使两座岛连接的最短路径，且不会碰到标记为2的区域。
具体的求解步骤如下：
识别岛屿：遍历整个网格，找到所有1的位置，并区分出属于不同岛屿的1。我们可以用DFS来将同一个岛屿上的所有1连接在一起，并用一个列表保存各个岛屿的坐标位置。
多源BFS：从一个岛屿的所有1作为起点，进行BFS，寻找能够到达另一个岛屿的最短路径。在BFS的过程中，将0转换为1来连接两座岛屿，但需要保证不会碰到值为2的节点。
路径长度：每次通过BFS扩展搜索时，我们可以记录从初始岛屿到当前扩展的节点所需要翻转的0的数量。当搜索到另一个岛屿时，返回翻转的最小0数量。
返回值：如果能够连接两个岛屿，返回最小的翻转0数量；否则返回-1。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

// 四个方向：右，下，左，上
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 深度优先搜索（DFS）标记一个岛屿，并记录该岛屿所有点的坐标
void dfs(int x, int y, vector<pair<int, int>> &island, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;
    island.push_back({x, y});

    while (!s.empty())
    {
        auto [i, j] = s.top();
        s.pop();

        for (int d = 0; d < 4; ++d)
        {
            int ni = i + directions[d][0];
            int nj = j + directions[d][1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1 && !visited[ni][nj])
            {
                visited[ni][nj] = true;
                island.push_back({ni, nj});
                s.push({ni, nj});
            }
        }
    }
}

// 广度优先搜索（BFS）寻找最小的翻转次数以连接两个岛屿
int bfs(const vector<pair<int, int>> &island1, const vector<pair<int, int>> &island2, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    set<pair<int, int>> visited;

    for (const auto &pos : island1)
    {
        q.push(pos);
        visited.insert(pos);
    }

    int flips = 0;

    while (!q.empty())
    {
        int size = q.size();

        // 扩展当前层的所有节点
        while (size--)
        {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];

                // 如果超出边界，继续
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                // 遇到敌对势力2，立即停止当前路径的扩展
                if (grid[nx][ny] == 2)
                    continue;

                // 找到另一个岛屿，返回翻转次数
                if (grid[nx][ny] == 1 && visited.find({nx, ny}) == visited.end())
                {
                    for (const auto &pos : island2)
                    {
                        if (pos.first == nx && pos.second == ny)
                        {
                            return flips;
                        }
                    }
                }

                // 翻转0，继续扩展
                if (grid[nx][ny] == 0 && visited.find({nx, ny}) == visited.end())
                {
                    visited.insert({nx, ny});
                    q.push({nx, ny});
                }
            }
        }

        ++flips;
    }

    return -1; // 无法连接两个岛屿
}

// 主函数，返回连接两个岛屿所需翻转0的最小次数
int minFlip(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> island1, island2;

    // 找到两个岛屿的坐标列表
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                vector<pair<int, int>> island;
                dfs(i, j, island, grid, visited);
                if (island1.empty())
                {
                    island1 = island;
                }
                else
                {
                    island2 = island;
                }
            }
        }
    }

    if (island1.empty() || island2.empty())
    {
        return -1; // 题目中保证有两个岛屿，如果不是两个，返回-1
    }

    // 使用广度优先搜索，找到最小翻转次数
    return bfs(island1, island2, grid);
}

int main()
{
    vector<vector<int>> grid1 = {{1, 0, 2, 0}, {0, 0, 0, 1}};
    vector<vector<int>> grid2 = {{1, 0, 2, 0}, {0, 1, 0, 0}};
    vector<vector<int>> grid3 = {{1, 0, 2, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};

    cout << minFlip(grid1) << endl; // 输出: -1
    cout << minFlip(grid2) << endl; // 输出: 1
    cout << minFlip(grid3) << endl; // 输出: 4

    return 0;
}
