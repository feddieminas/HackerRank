'''
https://www.hackerrank.com/challenges/beautiful-3-set
Beautiful_3_Set.py
HacckerrankPy
'''

'''
Solution. Fully accepted
'''

from itertools import islice,count,product,repeat

myinput=int(input())

k=int((2*myinput)/3)
print(k+1)  

y=int((2*k)%myinput)

n = islice(count(), myinput) 
prods = product(n, repeat=3)

#mysums=[]
prodyinit=False
a,b,c = y, myinput, 0
for prod in prods:
    if(sum(prod)==myinput): 
        #print(prod)
        #mysums.append(prod)
        if (prod[0]==y+1 and prod[1]==0 and prodyinit==False): 
            i,j,l = prod
            prodyinit=True
            break
        if (prod[0]==y and prod[2]==0 and prodyinit==False):
            a,b,c = prod

#prodsy=[]
#prodsy.append((i,j,l))
print(i, j, l)
yloop=i+1
while(yloop<k+1):
    i, j, l = i+1, j+1, l-2
    print(i, j, l)
    #prodsy.append((i,j,l))
    yloop+=1

#print(prodsy)  

#prodsx=[]
#prodsx.append((a,b,c))
print(a,b,c)
while(a>0):
    a, b, c = a-1, b-1, c+2
    print(a,b,c)
    #prodsx.append((a,b,c))
    
#print(prodsx) 