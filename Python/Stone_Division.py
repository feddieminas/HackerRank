'''
https://www.hackerrank.com/challenges/stone-division
Stone_Division.py
HacckerrankPy
'''

'''
Solution. All testcases passed apart from last testcase 15 (Terminated due to timeout)

ex. testcase 0
15 3
5 2 3
'''

from collections import defaultdict

def plays(mymap,si,round):
    solutions=set()
    for key in mymap: #create tuples of divisibles (3 and 5) of stone piles (15)
        for div in si: #the stone pile(15) can be broken to 3 and 5.
                       #stone pile(3) can be broken to 3.stone pile(5) can be broken to 5 
            if(key%div==0):
                solutions.add((key,div)) #fyi set is an unordered tuple ex. 
                						 #(15,3),(15,5),(5,5),(3,3)

    if len(solutions)<1: return round 

    #print (solutions)

    for sol in solutions:
        defmap=mymap.copy()

        '''
        print (sol[0])
        print (sol[1])
        print (defmap)
        '''
        
        if sol[0] in defmap:
            if(defmap[sol[0]]>1): 
                defmap[sol[0]]=defmap[sol[0]]-1 #if num(dict value) is higher than one, 
                                                #reduce by one to indicate alternate turn 
                                                #(see num below)
            else:
                defmap.pop(sol[0]) #if one pile of stones, remove "initial" as we break 
                				   #into further piles. Player who removes, it reduces the 
                				   #available moves to next turn person
        
        k=sol[0]//sol[1] #Piles to break
        num=sol[1]%2     #if odd num first lose, if even num second loses

        if(k in defmap):
            defmap[k]=defmap[k]+num #if k piles included in dict, 
            						#increase its current value with num above
        else:
            if(num>0):
                defmap[k]=num #insert k piles breaken not included in dict. 
                              #Num=1(first has broken it to k piles, then after turns,
                              #first remains with no available moves and loses.Second wins)
                              #Num=0(vise versa od Num=1 and first wins)   

        #print (defmap)

        wholose=plays(defmap,si,round+1) #analyse piles breaken with divisible stones

        if(wholose%2!=round%2): #if person that loses(int wholose) is not the person that 
            return round+1      #is currently playing,return the "game over" round+1
                                #else return round
    return round

if __name__ == '__main__':
    
    N, M = map(int,input().strip().split())

    arr = [int(i) for i in input().split()]
    
    mydivset=[]
    for i in range(M):
        mydivset.append(arr[i])

    mymap={}
    mymap=defaultdict(lambda:N)
    mymap[N]=1 #15 stones in 1 pile

    '''
    print (mymap.keys())
    print (mymap.values())
    '''

    round=1
    wholose=plays(mymap,mydivset,round)

    if(wholose%2==1):
        print ("Second") #if wholose is odd, first lose and second wins (see num explan above)
    else:
        print ("First")  #if wholose is even, second lose and first wins (see num explan above)

