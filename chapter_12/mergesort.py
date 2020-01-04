import random


def mergesort(a):

    return mergesort_helper(a,0,len(a) - 1)


def mergesort_helper(a,low,high):

    if low == high:
        return [a[low]]

    
    mid = (low + high) // 2

    return merge(mergesort_helper(a,low,mid),mergesort_helper(a,mid +1,high))



def merge(a,b):

    i =j = 0
    
    merged = []
    while i < len(a) or j < len(b):
        if j == len(b) or (i < len(a) and a[i] <= b[j]):
            merged.append(a[i])
            i += 1
        else:
            merged.append(b[j])
            j += 1


    return merged


if __name__ == "__main__":
    

    a = [random.randint(1,500) for _ in range(100)]

    print(a)

    a = mergesort(a)

    print(a)
