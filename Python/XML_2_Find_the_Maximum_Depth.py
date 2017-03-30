'''
https://www.hackerrank.com/challenges/xml2-find-the-maximum-depth
XML_2_Find_the_Maximum_Depth.py
HacckerrankPy
'''

'''
Solution. Fully accepted. Used Python 2

Links:
Python docs
http://eli.thegreenplace.net/2012/03/15/processing-xml-in-python-with-elementtree
http://www.diveintopython3.net/xml.html
'''

import xml.etree.ElementTree as etree

#if height no need of recurse for below function. just a counter of how many 
#for child in root
#if depth then we recurse depth(child) since we loop for every child of the upper parent 
#node and find how many sub childs does it have

def depth(root):
    #1)
    #return max([0] + [depth(child)+1 for child in root])
    #or
    #2)
    return max(map(depth, root)) + 1 if root else 0 #root and goes through each child node

N= int(raw_input())
xml=""
for i in range(N):
    xml +=str(raw_input())

tree=etree.ElementTree(etree.fromstring(xml))
root= tree.getroot() #like xml parse starting as a head the parent of all child nodes

print depth(root)