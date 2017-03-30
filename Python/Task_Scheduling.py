'''
https://www.hackerrank.com/challenges/task-scheduling
Task_Scheduling.py
HacckerrankPy
'''

'''
Solution. Fully Accepted

Segment Tree 

Explanation:
https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

Have original inputs (index rank,deadline,minutes) and based on it, 
sort ascending the deadlines to reorder your orig inputs and index rank (vec_idm)
Vector_rank is the order of your original inputs after deadlines been sorted (vec_idm) 
Vector_reorder have negative inputs since you will then maximise values (vec_idm d column)

testcase 0
original inputs   vec_idm          vec_rnk    
idx  | d  | m     idx  | d  | m    idx | rnk        
 0   | 2  | 2      1   | 1  | 1      1 | 0   
 1   | 1  | 1      0   | 2  | 2      0 | 1   
 2   | 4  | 3      4   | 2  | 1      4 | 2   
 3   | 10 | 1      2   | 4  | 3      2 | 3   
 4   | 2  | 1      3   | 10 | 1      3 | 4   

Create your Interval nodes. If left and right values match each other upon recursion, you 
have your deadline(vec_d_reorder) node value set, otherwise going upwards(back to front) 
it's the max value of its left_tree and right_tree interval children value node. 

Go thru the tree to match your original input minutes rank range with its parent and 
children left_tree and/or right_tree interval nodes. You break your left and right range 
to smaller segments if minutes rank range do not exactly match. Once you find and update 
the matched interval node values and mark your nodes as visited(lazy_flag>0), you are 
going upwards to parents and retrieve the max overshoot value. Lazy_flag then helps for 
further input loops to update the accumulation minutes from parent node last visit to 
children nodes. Lazy_flag will then be marked as unvisited as default(lazy_flag=0)
'''


#import sys

class SegTree(object):

    def __init__(self, left, right,myvec_d_sort):
        self.left=left
        self.right=right
        self.lazy_flag=0
        self.left_tree=self.right_tree=self
        if(left==right):
            self.max_value=myvec_d_sort[left]
        else:
            self.mid=(left+right)//2
            self.left_tree=SegTree(left,self.mid,myvec_d_sort)
            self.right_tree=SegTree(self.mid+1,right,myvec_d_sort)
            self.__parent_up()
        #print(self.max_value)

    def update(self,left,right,vec_m_val):
        if(self.left==left and self.right==right):
            self.__leaf_update(vec_m_val)
        else:
            self.__children_down()
            if(left<=self.mid):
                if(right>=self.mid+1):
                    self.left_tree.update(left,self.mid,vec_m_val)
                    self.right_tree.update(self.mid+1,right,vec_m_val)
                else:
                    self.left_tree.update(left,right,vec_m_val)
            else:
                self.right_tree.update(left,right,vec_m_val)
            self.__parent_up()

    def query(self,left,right):
        if(self.left==left and self.right==right):
            return self.max_value
        else:
            self.__children_down()
            if(left<=self.mid):
                if(right>=self.mid+1):
                    self.__max_value_l=self.left_tree.query(left,mid)
                    self.__max_value_r=self.right_tree.query(mid+1,right)
                    return max(self.__max_value_l,self.__max_value_r)
                else:
                    return self.left_tree.query(left,right)
            else:
                return self.right_tree.query(left,right)
    
    def __parent_up(self):
        self.max_value=max(self.left_tree.max_value,self.right_tree.max_value)

    def __children_down(self):
        if(self.lazy_flag>0):
            self.left_tree.__leaf_update(self.lazy_flag)
            self.right_tree.__leaf_update(self.lazy_flag)
            self.lazy_flag=0

    def __leaf_update(self,val):
        self.lazy_flag+=val
        self.max_value+=val

if __name__ == '__main__':
    
    numlines = int(input())
    lines = ""
    for i in range(numlines):
        lines+=input()+"\n"
        
    data=lines.strip().split()
    
    '''
    k=0
    for i in range(numlines):
        print (data[0+k])
        print (data[1+k])
        k+=2
    exit(0)
    '''

    vec_idm=[]

    k=0
    for i in range(numlines):
        (i,d,m)=(i,data[0+k],data[1+k])
        vec_idm.append((i,int(d),int(m)))

        k+=2

    vec_idm.sort(key=lambda x: x[1])

    vec_rnk=[0]*numlines

    for i in range(numlines):
        vec_rnk[vec_idm[i][0]]=i

    vec_d_reorder=[0]*numlines

    for i in range(numlines):
        vec_d_reorder[i]= int(vec_idm[i][1]) * int(-1)
        #vec_d_reorder[i]= int(data[vec_idm[i][0]*int(2)]) * int(-1) #vec_d  reorder
                          #int(data[(vec_idm[i][0]*int(2))+1])       #vec_m  reorder
                          #(int(vec_idm[vec_rnk[i]][2]))             #vec_m  original 

    '''
    for i in range(numlines):
        print("idx ", vec_idm[i][0])
        print("rnk ", vec_rnk[i])
        print("reord ", vec_d_reorder[i])
    '''
    
    #sys.setrecursionlimit(10000000);

    tree=SegTree(0,numlines-1,vec_d_reorder) 
    
    
    for i in range(numlines):
        #print (int(vec_idm[vec_rnk[i]][2]))
        tree.update(vec_rnk[i],numlines-1,int(vec_idm[vec_rnk[i]][2]))
        ans=tree.query(0,numlines-1)
        print(max(0,ans))