



def setup(m,memo,start,n):

    for i in range(n):
        if i == start:
            continue

        memo[i][1 << i | 1 << start] = m[start][i]

def solve(m,memo,start,n):

    for r in range(3,n + 1):
        for subset in subsets(r,n):
            if notIn(start,subset):
                continue

            for next_node in range(n):
                if next_node == start or notIn(next_node,subset):
                    continue

                state = subset ^ (1 << next_node)
                
                minimum  = float("inf")
                for end in range(n):
                    if end == next_node or end == start or notIn(end,subset):
                        continue

                    minimum = min(minimum,memo[end][state] + m[end][next_node])


                memo[next_node][subset] = minimum







def notIn(i,subset):

    return (1 << i) & subset == 0
def subsets(r,n):
    numbers = []
    number = 0

    subsets_helper(r,n,0,number,numbers)


def subsets_helper(r,n,n_index,number,numbers):

    if r == 0:
        numbers.append(number)
        return

    for i in range(n_index,n):

        number |= (1 << i)

        subsets_helper(r - 1,n,i + 1,number,numbers)

        number &= ~(1 << i)


def find_optimal_cost(m,memo,start,n):

    minimum = float("inf")
    end_state = (1 << n) - 1
    for i in range(n):
        if i == start:
            continue

        minimum = min(minimum,memo[i][end_state][0] + m[i][start])

    return minimum

def find_optimal_path(m,memo,start,n):
    pass

def tsp(m,start):
    n = len(m)
    memo = [[[float("inf"),None] for _ in range(2**n)] for _ in range(n)]

    setup(m,memo,start,n)

    solve(m,memo,start,n)

