"""
Undirected graph with n node and n-1 edges
    1
  /    \ 
0      2
      /     \
    3        4
edges = [[0, 1], [2, 1], [2, 3], [2, 4]]
Target = 2
Return = 5
int SumDist(edges, target);
"""

from collections import deque

def SumDist(edges, target):
    p = {}
    for edge in edges:
        u = int(edge[0])
        v = int(edge[1])

        if u not in p:
            p[u] = []
        p[u].append(v)
        if v not in p:
            p[v] = []
        p[v].append(u)
    
    dis = {}
    seed = set()
    q = deque()
    # q = queue()

    # BFS
    dis[target] = 0
    seed.add(target)
    q.append(target)

    while q:
        cur = q.popleft()
        for neighbor in p.get(cur, []):
            if neighbor not in seed:
                seed.add(neighbor)
                dis[neighbor] = dis[cur] + 1
                q.append(neighbor)
    
    sum = 0
    for d in dis:
        if d != target:
            sum += dis[d]
    
    # return sum(dis)
    return sum

edges = [[0, 1], [2, 1], [2, 3], [2, 4]]
Target = 2
result = SumDist(edges, Target)
print(f"result:{result}")
