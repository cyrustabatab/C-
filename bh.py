


class LLNode:

    def __init__(self,tree=None):
        self.tree = tree


    @property
    def order(self):
        if self.tree:
            return self.tree.order

    @property
    def key(self):
        if self.tree:
            return self.tree.key

class LL:

    def __init__(self):
        self.head = LLNode(tree)
        self.tail = self.head
        self.minimum = None
    

    def min(self):
        return self.minimum


    def _set_minimum(self):
        minimum = float("inf")
        min_node = None

        current = self.head.next

        while current:
            if current.key < minimum:
                minimum = current.key
                min_node = current
            current = current.next


        self.minimum = min_node
    def _merge(self,ll):


        current_1,current_2 = self.head.next,ll.head.next

        new_ll = LL()
        while current_1 or current_2:
            if not current_2 or (current_1 and current_1.order <= current_2.order):
                temp = current_1.next
                new_ll._add_front(current_1)
                current_1 = temp
            else:
                temp = current_2.next
                new_ll._add_front(current_2)
                current_2 = temp



        self.head,self.tail = new_ll.head,new_ll.tail
        self.union()


    def union(self):

        current = self.head.next

        previous = self.head
        

        minimum = float("inf")
        min_node = None
        while current and current.next:
            if current.key < minimum:
                minimum = current.key
                min_node = current
            if current.order != current.next.order:
                previous = current
                current = current.next
            else:
                if current.next.next and current.order == current.next.next.order:
                    previous = current
                    current = current.next
                elif current.key <= current.next.key:
                    current.tree.add_child(current.next.tree)
                    current.next = current.next.next
                else:
                    current.next.add_child(current.tree)
                    previous.next = current.next
                    current = current.next
        

        self.minimum = current if current and current.key < minimum else min_node
    
    def _remove_min(self):

        current = self.minimum.left_most_child
        
        self.minimum.prev.next = self.minimum.next

        if self.minimum.next:
            self.minimum.next.prev = self.minimum.prev
        new_ll = LL()
        while current:
            temp = current.right_sibling
            current.right_sibling = None
            new_ll._add_end(temp)
            current = temp
        

        self._merge(new_ll)
    

    def _add_end(self,tree):
        node = LLNode(tree)
        self.tail.next = node
        self.tail = node

    def _add_front(self,node):

        node.next = self.head.next
        if not node.next:
            self.tail = node

        self.head.next = node

    def _insert(self,tree):
        node = LLNode(tree)

        self._add_front(node)
        self.union()




class BinomialTree:

    def __init__(self,_id,key,predecessor):
        self.id = _id
        self.key = key
        self.predecessor = predecessor
        self.left_most_child = self.right_sibling = None
        self.parent = None
        self.order = 0


    def __repr__(self):
        return f"BinomialTree({self.id},{self.key},{self.predecessor})"


class BinomialHeap:


    def __init__(self):
        self.ll = LL()
        self.map = {}
        self.size = 0
    
    @property
    def empty(self):
        return self.size == 0

    def __len__(self):
        return self.size
    

    def merge(self,heap):
        if isinstance(heap,BinomialHeap):
            if heap.empty:
                return

            if self.empty:
                self.ll = other.ll
                self.size = other.size

            self.ll._merge(other.ll)
            self.size += other.size

    def add(self,_id,key=float("inf"),predecessor=None):
        tree = BinomialTree(_id,key,predecessor)
        self.size += 1
        self.map[_id] = tree
        self.ll._insert(tree)
    

    def remove_min(self):

        self.ll._remove_min()

    
    def decrease_key(self,_id,key,predecessor=None):
        tree =self.map[_id]
        if key >= tree.key:
            return

        tree.key = key
        tree.predecessor = predecessor
    
        current = tree
        while current.parent and current.key < current.parent.key:
            current.key,current.parent.key = current.parent.key,current.key
            current = current.parent
        

        self.ll._set_minimum()

    def _delete(self,_id):
        self.decrease_key(_id,float("-inf"))

