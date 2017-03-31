'''
https://www.hackerrank.com/challenges/maxsubarray
The_Maximum_Subarray.py
HacckerrankPy
'''

'''
Solution. Fully accepted

Kadane's algorithm

https://en.wikipedia.org/wiki/Maximum_subarray_problem
'''

import sys

if __name__ == '__main__':
    T=int(input())

    for t in range(T):
        max_cont_sum=curr_max=-sys.maxsize-1
        N=int(input())
        arr=[int(i) for i in input().split()]
        for i in range(N):
            curr_max=max(arr[i],curr_max+arr[i])
            max_cont_sum=max(curr_max,max_cont_sum)
        if (max_cont_sum<0):
            max_sum=max_cont_sum
        else:
            max_sum=sum([x if x>0 else 0 for x in arr])
        print ("%d %d" % (max_cont_sum,max_sum))
        #also
        #print (str(max_cont_sum)+' '+str(max_sum))