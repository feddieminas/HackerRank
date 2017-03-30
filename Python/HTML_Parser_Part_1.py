'''
https://www.hackerrank.com/challenges/html-parser-part-1
HTML_Parser_Part_1.py
HacckerrankPy
'''

import re
from html.parser import HTMLParser

class MyHTMLParser1(HTMLParser):      
    def handle_starttag(self,tag,attributes):
        print("Start : " + tag)
        for name, value in attributes: 
            print("-> " + name + " > " + str(value))

    def handle_endtag(self,tag):
        print("End   : " + tag)
        
    def handle_comment(self, data):
        pass

    def handle_startendtag(self,tag,attributes):
        print("Empty : " + tag)
        for name, value in attributes: 
            print("-> " + name + " > " + str(value))

html=""
for i in range(int(input())):
	html +=input().rstrip()+ '\n'

'''
re (remove HTML comment tags context).. For Note: section
\ matches an expression.Below match both < and ! there prob a comment
. match any single char no newline
* match char zero or more times
? match char zero or one time
ex.     weblink: tutorialspoint
<.*>	Greedy repetition: matches "<python>perl>"
<.*?>	Nongreedy: matches "<python>" in "<python>perl>"
'''    
html = re.sub(r"\<\!--.*?--\>","",html) 

parser = MyHTMLParser1()
parser.feed(html)
parser.close()