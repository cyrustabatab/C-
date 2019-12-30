from collections import deque

class Edge:

    def __init__(self,capacity=0):
        self.capacity = capacity
        self.flow = 0

    @property
    def remaining_capacity(self):
        return self.capacity - self.flow

    
    def augment(self,amount):
        self.flow += amount

    def __repr__(self):
        return f"Edge({self.capacity},{self.flow})"

class FlowNode:


    def __init__(self,_id):
        self._id = _id
        self.neighbors = {}
        self.bottleneck = float("inf")
        self.predecessor = None


    @property
    def id(self):
        return self._id


    def get_neighbors(self):
        return self.neighbors.keys()

    def add_neighbor(self,node,capacity=0):
        self.neighbors[node] = Edge(capacity)

    def get_remaining_capacity(self,node):
        if node in self.neighbors:
            return self.neighbors[node].remaining_capacity


    def get_capacity(self,node):
        if node in self.neighbors:
            return self.neighbors[node].capacity

    def get_flow(self,node):
        if node in self.neighbors:
            return self.neighbors[node].flow
    
    def augment(self,node,amount):
        self.neighbors[node].augment(amount)
        node.neighbors[self].augment(-amount)

    def __repr__(self):
        return f"FlowNode({self.id})"





class FlowGraph:

    def __init__(self):
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


    def add_vertex(self,_id):
        if _id not in self.node_list:
            node = FlowNode(_id)
            self.node_list[_id] = node


    def add_edge(self,n1,n2,capacity=0):
        if n1 not in self.node_list:
            self.add_vertex(n1)

        if n2 not in self.node_list:
            self.add_vertex(n2)

        self.node_list[n1].add_neighbor(self.node_list[n2],capacity)
        self.node_list[n2].add_neighbor(self.node_list[n1])
    

    def __iter__(self):
        return iter(self.node_list.values())

    def __getitem__(self,_id):
        return self.node_list.get(_id)

    def __repr__(self):
        g =''
        for node in self:
            g += f"{node.id}: "
            g += ','.join(str(neighbor.id) for neighbor in node.get_neighbors()) + '\n'

        return g


def dfs_visit(node,target,visited,bottleneck=float("inf")):
    
    if node is target:
        return bottlneck

    visited.add(node.id)

    current_bottleneck = bottleneck

    for neighbor in node.get_neighbors():
        if neighbor.id not in visited and node.get_remaining_capacity(neighbor) > 0:
            bottleneck = dfs_visit(neighbor,target,visited,min(current_bottleneck,node.get_remaining_capacity(neighbor)))

            if bottleneck > 0:
                node.augment(neighbor,bottleneck)

                return bottleneck


def bfs_visit(node,target):

    visited = set()
    visited.add(node.id)
    queue.append(node)

    while queue:
        current_node = queue.popleft()

        if current_node is target:
            break


        for neighbor in node.get_neighbors():
            if neighbor.id not in visited and node.get_remaining_capacity(neighbor) > 0:
                visited.add(neighbor.id)
                neighbor.bottleneck = min(node.bottleneck,node.get_remaining_capacity(neighbor))
                neighbor.predecessor= node
    







def edmonds_karp(g,source,sink):

    flow = 0
    while True:

        bottleneck = bfs_visit(g[source],g[sink])


def max_flow(g,source,sink):

    flow = 0
    
    
    while True:

        visited = set()

        dfs_visit(g[source],g[sink],visited)
