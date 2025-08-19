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


from graphviz import Digraph

# 创建有向图
dot = Digraph(comment="Trinity 聚类流程图", format="png")
dot.attr(rankdir="LR", size="8")

# 节点定义
dot.node("E", "① Item Embedding 提取\n(从标题/标签/多模态特征生成 embedding)", shape="box", style="rounded,filled", color="lightblue", fontname="Microsoft YaHei")
dot.node("C", "② Codebook 初始化\n(Primary/Secondary cluster 向量)", shape="box", style="rounded,filled", color="lightgreen", fontname="Microsoft YaHei")
dot.node("M", "③ Item → Cluster 映射\n(最近邻搜索 ANN)", shape="box", style="rounded,filled", color="lightyellow", fontname="Microsoft YaHei")
dot.node("T", "④ Cluster 训练优化\n(BCE 损失更新 codebook)", shape="box", style="rounded,filled", color="lightpink", fontname="Microsoft YaHei")
dot.node("S", "⑤ 存储映射\n(Item ID → Cluster ID)\n(KV 存储)", shape="box", style="rounded,filled", color="lightgrey", fontname="Microsoft YaHei")
dot.node("U", "⑥ 用户兴趣直方图构建\n(基于用户行为统计 cluster 权重)", shape="box", style="rounded,filled", color="lightsalmon", fontname="Microsoft YaHei")
dot.node("R", "→ Trinity-M / Trinity-LT / Trinity-L\n多兴趣/长尾/长期兴趣召回", shape="box", style="rounded,filled", color="gold", fontname="Microsoft YaHei")

# 连线
dot.edges([("E", "C"), ("C", "M"), ("M", "T"), ("T", "S"), ("S", "U"), ("U", "R")])

# 渲染并展示
file_path = "/mnt/data/trinity_clustering_flowchart"
dot.render(file_path, cleanup=True)
file_path + ".png"
