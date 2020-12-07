# This code definitely deserves some improvements.

N = int(input())
M = int(input())
edges = []
A = [0]*(N+1)
B = [0]*(N+1)


for a in range(M):
    e = tuple(int(b) for b in input().split(' '))
    if a == 0:
        A[e[0]] = 1
        B[e[1]] = 1
        continue
    edges.append(e)

def bipartite_graph(edges, A, B):
    unknown_edges = []
    for edge_num in range(len(edges)):
        if A[edges[edge_num][0]] == 1:
            if A[edges[edge_num][1]] == 1:
                return 'Nelze'
            B[edges[edge_num][1]] = 1
        elif B[edges[edge_num][0]] == 1:
            if B[edges[edge_num][1]] == 1:
                return 'Nelze'
            A[edges[edge_num][1]] = 1
        elif A[edges[edge_num][1]] == 1:
            if A[edges[edge_num][0]] == 1:
                return 'Nelze'
            B[edges[edge_num][0]] = 1
        elif B[edges[edge_num][1]] == 1:
            if B[edges[edge_num][0]] == 1:
                return 'Nelze'
            A[edges[edge_num][0]] = 1
        else:
            unknown_edges.append(edges[edge_num])
    if len(unknown_edges) > 0:
        return bipartite_graph(unknown_edges, A, B)
    return ' '.join(map(lambda x: str(x),filter(lambda x: x != 0, [a if A[a] !=0 else 0 for a in range(1, N+1)]))) + '\n' + ' '.join(map(lambda x: str(x), filter(lambda x: x !=0, [a if B[a] !=0 else 0 for a in range(1, N+1)])))
if N == 0:
    print('Nelze')
else:
    print(bipartite_graph(edges, A, B))