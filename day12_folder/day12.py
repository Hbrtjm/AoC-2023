import os

print(os.getcwd())

with open(os.getcwd()+"\\infile12.txt") as instream:
    contents = instream.read()
    instream.close()

for line in contents:
    print(line)

def solve():
    
