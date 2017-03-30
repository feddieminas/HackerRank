'''
https://www.hackerrank.com/challenges/xml-1-find-the-score
XML_1_Find_the_Score.py
HacckerrankPy
'''

'''
Solution. Fully accepted. Inserted three different methods below. Used Python 2

Links:
Python docs
http://eli.thegreenplace.net/2012/03/15/processing-xml-in-python-with-elementtree
http://www.diveintopython3.net/xml.html
'''

import xml.etree.ElementTree as etree

N = int(raw_input())
xml= ""
for i in range(N):
    xml+=str(raw_input()) #create the six lines of the xml root and nodes
    
tree = etree.ElementTree(etree.fromstring(xml)) #generate xml string and root parsing
count=0
#1)
'''
for element in tree.iter():
    #count+=len(element.attrib)
'''

#2)

def traverse(node):
    return len(node.attrib) + sum(map(traverse, node))  #need also inner loops for childs 
    													#inside

count=traverse(tree.getroot())


#3)
'''
root=tree.getroot()
count = len(root.attrib) #root count
elements = root.findall(".//*") #.//* to get all elements and its childs apart from root
for item in elements: 
    count += len(item.attrib)
'''    

    
print count

