'''
https://www.hackerrank.com/challenges/validating-credit-card-number
Validating_Credit_Card Numbers.py
HacckerrankPy
'''

import re

creditcards=[input() for i in range(int(input()))]

for cardnum in creditcards:
    cardvalid='Invalid'
    valid456=bool(re.match(r'^[4-6]',cardnum)) #card starts with 4,5,6
    #print(valid456)
    if(valid456==True):
        valid16dsingle=bool(re.match(r'^[0-9]{16}$',cardnum)) #count no hyphen has 16 digits
        #print(valid16d)
        valid4groups=bool(re.search(r'^([0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4})$',cardnum)) #count yes hyphen has 16 digits
        #print(valid4groups)
        valids=(valid16dsingle,valid4groups)
        if any(valid == True for valid in valids): #if either yes/no hyphen is true(depending on your card input)
            valid4repeat=bool(re.findall(r'(?=([0-9])\1{3,})',"".join(cardnum.split('-')))) #use ?= to explore 4 and more consecutive nums.Can use also ?:
            if valid4repeat==False:
                cardvalid='Valid'
    print(cardvalid)

