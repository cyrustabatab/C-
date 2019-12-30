from collections import deque


def sliding_max(a,k):

    queue = deque()
    result = []

    for i in range(k):
        number = a[i]
        while queue and number > a[queue[-1]]:
            queue.pop()

        queue.append(i)

    result.append(a[queue[0]])



    for i in range(k,len(a)):
        number = a[i]

        while queue and number > a[queue[-1]]:
            queue.pop()


        while queue and queue[0] < i - k:
            queue.popleft()
        
        queue.append(i)
        result.append(a[queue[0]])


    print(result)

if __name__ == "__main__":
    

    a = [5,1,2,7,4,10,11,11,4,12]
    k = 3
    print(a)
    print(k)
    sliding_max(a,k)

    
