from collections import defaultdict

def rabin_karp(s1:str,s2:str) -> int:

    assert len(s1) >= len(s2)

    x = 53
    current_hash = target_hash = 0
    same = True

    
    for i in range(len(s2)):
        if same and s1[i] != s2[i]:
            same = False

        current_hash = current_hash * x + ord(s1[i])
        target_hash = target_hash * x+ ord(s2[i])


    if same:
        return 0


    power = x**(len(s2) - 1)


    for i in range(len(s2),len(s1)):
        letter_to_remove,letter_to_add = s1[i - len(s2)],s1[i]
        current_hash = (current_hash - power * ord(letter_to_remove)) * x + ord(letter_to_add)
        if current_hash == target_hash and s1[i - len(s2):i + 1] == s2:
            return i - len(s2) + 1
    

    return -1




class DisjointSet:

    def __init__(self,keys):
        self.a = {key: [key,0] for key in keys}
    

    def union(self,key_1,key_2):
        root_1,root_2 = self.find(key_1),self.find(key_2)

        if root_1 != root_2:
            rank_1,rank_2 = self.a[root_1][1],self.a[root_2][1]

            if rank_1 > rank_2:
                self.a[root_2][0] = root_1
            elif rank_2 > rank_1:
                self.a[root_1][0] = root_2
            else:
                self.a[root_2][0] = root_1
                self.a[root_1][1] += 1


    def find(self,key):

        keys = []

        while self.a[key][0] != key:
            keys.append(key)
            key = self.a[key][0]


        for k in keys:
            self.a[k][0] = key

        return key

class Vertex:

    def __init__(self,_id,key=float("inf"),predecessor=None):
        self.id = _id
        self.key = key
        self.predecessor = predecessor
    

    def __lt__(self,vertex):
        if isinstance(vertex,Vertex):
            return self.key <= vertex.key

    def __repr__(self):
        return f"Vertex({self.id},{self.key})"



class MinHeap:


    def __init__(self):
        self.a = [None]
        self.map = {}
    
    def __len__(self):
        return self.size
    

    def min(self):
        try:
            return self.a[1]
        except:
            raise ValueError("Empty Heap")
    @property
    def size(self):
        return len(self.a) - 1
    
    def remove_min(self):
        try:
            value = self.a[1]
        except:
            raise ValueError("Empty Heap")


        self._swap(1,self.size)

        del self.map[self.a[self.size].id]
        del self.a[self.size]
        self.sink()
        return value

    def sink(self):
        i = 1

        while i * 2 <= self.size:
            j = i * 2
            if j + 1 <= self.size and self.a[j + 1] < self.a[j]:
                j += 1

            if self.a[j] < self.a[i]:
                self._swap(i,j)
                i = j
            else:
                return
    def add(self,vertex):
        self.a.append(vertex)
        self.map[vertex.id] = self.size
        self.swim()

    def swim(self):
        i = self.size

        while i // 2 >= 1 and self.a[i] < self.a[i//2]:
            self._swap(i,i//2)
            i //= 2


    def _swap(self,i,j):
        self.a[i],self.a[j] = self.a[j],self.a[i]
        self.map[self.a[i].id] = i
        self.map[self.a[j].id] = j


class Node:


    def __init__(self,_id):
        self._id = _id
        self.neighbors = {}

    @property
    def id(self):
        return self._id


    def get_neighbors(self):
        return self.neighbors.keys()


    def add_neighbor(self,node,weight=0):
        self.neighbors[node] = weight


    def get_weight(self,node):
        return self.neighbors.get(node)


    def __repr__(self):
        return f"Node({self.id})"




class Graph:

    def __init__(self,directed=False):
        self.directed = directed
        self.node_list = {}
        self._edges = 0


    @property
    def num_edges(self):
        return self._edges


    @property
    def num_vertices(self):
        return len(self.node_list)


    @property
    def vertices(self):
        return self.node_list.keys()
    

    def get_edges(self):
        for node in self:
            for neighbor in node.get_neighbors():
                yield (node.id,neighbor.id)

    def add_vertex(self,_id):
        if _id not in self.node_list:
            node = Node(_id)
            self.node_list[_id] = node


    def add_edge(self,n1,n2,weight=0):
        if n1 not in self.node_list:
            self.add_vertex(n1)

        if n2 not in self.node_list:
            self.add_vertex(n2)


        self.node_list[n1].add_neighbor(self.node_list[n2],weight)

        if not self.directed:
            self.node_list[n2].add_neighbor(self.node_list[n1],weight)

        self._edges += 1
    
    def __iter__(self):
        return iter(self.node_list.values())

    def __getitem__(self,_id):
        return self.node_list.get(_id)

    def __repr__(self):
        g = ''

        for node in self:
            g += f"{node.id}: "
            g += ','.join(str(neighbor.id) for neighbor in node.get_neighbors()) + '\n'

        return g


def johnsons(g):

    source = "*"


    for v in list(g.vertices):
        g.add_edge(source,v)

    bellman_distances = bellman_ford(g,source)

    for s,e in g.get_edges():
        g.add_edge(s,e,g[s].get_weight(g[e]) + bellmam_distances[s] - bellman_distances[e])


    distances = {}

    for v in g.vertices:
        distances[v] = dijkstra(v)
        for end in distances[v]:
            distances[v][end] = distances[v][end] - bellman_distances[v] + bellman_distances[end]




def floyd_warshall(g):
    n = len(g)
    distances = [[0 if i == j else float("inf") for j in range(n + 1)] for i in range(n + 1)]
    predecessors = [[None for _ in range(n + 1)] for _ in range(n + 1)]

    for s,e in g.get_edges():
        distances[s][e] = g[s].get_weight(g[e])
        predecessors[s][e] = s


    for k in range(1,n + 1):
        for i in range(1,n + 1):
            for j in range(1,n + 1):
                distance = distances[i][k] + distances[k][j]
                if distance < distances[i][j]:
                    distances[i][j] = distance
                    predecessors[i][j] = predecessors[k][j]
def bellman_ford(g,source,target=None):

    distances,predecessors = {},{}

    for v in g.vertices:
        distances[v] = float("inf")
        predecessors[v] = None

    distances[v] = 0


    for i in range(g.num_vertices):
        stabilized = True
        for s,e in g.get_edges():
            distance = distances[s] + g[s].get_weight(g[e])
            if distance < distances[e]:
                distances[e] = distance
                predecessors[e] = s
                stabilized = False

        if stabilized:
            return distances


    print("Negative Cycle Detected")



def dijkstra(g,source,target=None):

    min_heap = MinHeap()

    min_heap.add(Vertex(source,0))

    for v in g.vertices:
        if v == source:
            continue

        min_heap.add(Vertex(v))

    distances = {}
    while min_heap:
        minimum_vertex = min_heap.remove_min()
        distances[minimum_vertex.id] = (minimum_vertex.key,minimum_vertex.predecessor)

        for neighbor in g[minimum_vertex.id].get_neighbors():
            if neighbor.id not in distances:
                distance = minimum_vertex.key + g[minimum_vertex.id].get_weight(neighbor)
                min_heap.updateIfLessThan(neighbor.id,distance,minimum_vertex.id)



def kruskals(g):

    ds = DisjointSet(g.vertices)

    sorted_edges = sorted(list(g.get_edges()),key=lambda x:g[x[0]].get_weight(g[x[1]]))

    for s,e in sorted_edges:
        if ds.find(s) != ds.find(e):
            edges.add((s,e))
            ds.union(s,e)

    
    return edges


def prims(g):

    edges = set()
    X = set()

    start = random.choice(list(g.vertices))

    X.add(start)
    min_heap = MinHeap()
    for v in g.vertices:
        if v == start:
            continue

        if g[v] in g[start].get_neighbors():
            min_heap.add(Vertex(v,g[start].get_weight(g[v]),start))
        else:
            min_heap.add(Vertex(v))


    while min_heap:
        minimum_vertex = min_heap.remove_min()
        X.add(minimum_vertex.id)
        edges.add((minimum_vertex.predecessor,minimum_vertex.id))

        for neighbor in g[minimum_vertex.id].get_neighbors():
            if neighbor.id not in X:
                distance = g[minimum_vertex.id].get_weight(neighbor)
                min_heap.updateIfLessThan(neighbor.id,distance,minimum_vertex.id)
   


def dfs_visit_articulation(root,node,parent,visited,label,articulation_points):
    if parent is root:
        edge_count[0] += 1
    visited.add(node.id)
    node.label = label[0]
    node.low = node.label
    label[0] += 1

    for neighbor in node.get_neighbors():
        if neighbor is parent:
            continue
        if neighbor.id not in visited:
            dfs_visit(root,neighbor,node,visited,label,articulation_points)
            
            node.low = min(node.low,neighbor.low)

            if node is not root:

                if node.label <= neighbor.low:
                    articulation_points.add(node.id)
        else:
            node.low = min(node.low,neighbor.low)








def find_articulation_points(g):

    articulation_points = set()
    visited = set()
    label = [0]

    for node in g:
        if node.id not in visited:
            edge_count[0]
            dfs_visit_articulation(node,node,None,visited,label,articulation_points)
            if edge_count[0] > 1:
                articulation_points.add(node.id)





def dfs_visit_bridge(node,parent,visited,label,bridges):
    visited.add(node.id)
    node.label = label[0]
    node.low = node.label
    label[0] += 1

    for neighbor in node.get_neighbors():
        if neighbor is parent:
            continue

        if neighbor.id not in visited:
            dfs_visit_bridge(neighbor,node,visited,label,bridges)

            node.low = min(node.low,neighbor.low)

            if node.label < neighbor.low:
                bridges.append((node.id,neighbor.id))
        else:
            node.low = min(node.low,neighbor.low)



def find_bridges(g):
    bridges = []
    visited = set()
    label = [0]

    for node in g:
        if node.id not in visited:
            dfs_visit_bridge(node,None,visited,label,bridges)


def dfs_visit(node,visited,stack):

    visited.add(node.id)

    for neighbor in node.get_neighbors():
        if neighbor.id not in visited:
            dfs_visit(neighbor,visited,stack)

    stack.append(node.id)

def dfs_visit_2(node,visited,scc_num):
    visited.add(node.id)
    node.scc = scc_num
    
    for neighbor in node.get_neighbors():
        if neighbor.id not in visited:
            dfs_visit_2(neighbor,visited,scc_num)

def kosarajus(g):
    assert g.directed
    reveresed_graph = g.get_reversed_graph()

    stack = []
    visited = set()

    for node in g:
        if node.id not in visited:
            dfs_visit(ndoe,visited,stack)
    
    stack.reverse()
    visited.clear()
    scc_num = 0

    for node_id in stack:
        if node_id not in visited:
            dfs_visit_2(g[node_id],visited,scc_num)
            scc_num += 1
def dfs_visit_tarjan(node,visited,stack,label,sccs):
    node.onStack = True
    node.label = label[0]
    node.low = node.label
    stack.append(node)
    label[0] += 1

    for neighbor in node.get_neighbors():
        if neighbor.id not in visited:
            dfs_visit_tarjan(neighbor,visited,stack,label)

        if neighbor.onStack:
            node.low = min(node.low,neighbor.low)
    

    if node.label == node.low:

        while stack[-1].id != node.id:
            n = stack.pop()
            n.onStack = False
            sccs[n.low].append(n.id)

        n = stack.pop()
        n.onStack = False
        sccs[n.low].append(n.id)
def tarjans(g):

    stack = []
    visited = set()
    label = [0]
    sccs = defaultdict(list)

    for node in g:
        if node.id not in visited:
            dfs_visit_tarjan(node,visited,stack,label)


