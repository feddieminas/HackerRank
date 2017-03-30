'''
https://www.hackerrank.com/challenges/decorators-2-name-directory
Decorators_2_Name_Directory.py
HacckerrankPy
'''

import operator
from itertools import groupby

people=[input().split() for i in range(int(input()))]

def person_lister(func):
    def inner(people):
        #1)
        #return [func(person) for person in sorted(people, key=operator.itemgetter(2))] #sort by age
        #2)
        people.sort(key=operator.itemgetter(2)) #groupby func below needs to be presented sorted
        return [func(item) for age,items in groupby(people, lambda x: x[-2]) for item in items] 
    return inner

@person_lister
def name_format(person):
    return ("Mr. " if person[-1] == "M" else "Ms. ") + " ".join(person[:-2])

print(*name_format(people), sep='\n')