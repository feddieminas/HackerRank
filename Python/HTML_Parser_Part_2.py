'''
https://www.hackerrank.com/challenges/html-parser-part-2
HTML_Parser_Part_2.py
HacckerrankPy
'''

from html.parser import HTMLParser

class MyHTMLParser2(HTMLParser):
    def handle_starttag(self,tag,attributes):
        pass
        #print("Start : " + tag)
        #for name, value in attributes: 
            #print("-> " + name + " > " + str(value))

    def handle_endtag(self,tag):
        pass
        #print("End   : " + tag)
        
    def handle_comment(self, data):
        comments=data.split('\n')
        print(">>> Single-line Comment") if len(comments)==1 else print(">>> Multi-line Comment")
        for com in comments: 
            if(com.strip()): #or com!="\n"
                print(com) 

    def handle_startendtag(self,tag,attributes):
        pass
        #print("Empty : " + tag)
        #for name, value in attributes: 
            #print("-> " + name + " > " + str(value)) 
            
    def handle_data(self, data):
        if data.strip(): print(">>> Data" + '\n' + data)  #or data!="\n"
            
html = ""       
for i in range(int(input())):
    html += input().rstrip()
    html += '\n'
    
parser = MyHTMLParser2()
parser.feed(html)
parser.close()