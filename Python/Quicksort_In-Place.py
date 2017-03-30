'''
https://www.hackerrank.com/challenges/quicksort3
Quicksort_In-Place.py
HacckerrankPy
'''

'''
Solution. Fully accepted

QSort Lomuto Partition
'''

def swap(A,left,right):
    tmp=A[left]
    A[left]=A[right]
    A[right]=tmp

def partition(A, start, end):
    pivot = A[end]
    pindex = start
    for i in range(start, end):
        if A[i] <= pivot:
            swap(A,pindex,i)  #ex. testcase 0: 1 with 1, 3 with 3 and 2 with 9 swap
            #or
            #A[i], A[pindex] = A[pindex], A[i]
            pindex += 1
        else:
            continue #ex. testcase 0: 9, 8 and 7 elements greater than pivot 5 which upon 
                                      #loop remain where they are

    A[pindex], A[end] = A[end], A[pindex] #ex. testcase 0: 8 with 5 swap

    print (' '.join(str(i) for i in A)) #my print partition array

    return pindex #last index pindex acts as your "median"

def quick_sort(A, start, end):
    if(end-start)<1:
        return
    else: #start < end
        pindex = partition(A, start, end)
        quick_sort(A, start, pindex - 1)
        quick_sort(A, pindex + 1, end)

    return A

if __name__ == '__main__':
    n=int(input())
    arr=list(map(lambda x: int(x), input().strip().split()))
    quick_sort(arr,0,len(arr)-1)