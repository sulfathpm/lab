# 8.	Write a function to get a new string from a given string by adding 
# ‘Is’ to the beginning of the input string. If the given string already begins
# with ‘Is’, return the input string unchanged.

def addIs(s):
    for i in s:
        if(s.startswith('Is')):return s
        else:return 'Is'+s

s=input('enter a list of string : ')
result=addIs(s)
print('result: ',result)
