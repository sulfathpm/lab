# 3.	Write a program to search an item in a given list and display the number of occurrences of the given item. 

l=input('Enter a list : ').split()
x=input('Enter an item to search : ')
c=l.count(x)
if(c>0): 
    print('item',x,' found. occurence = ',c)
else: 
    print('item not found',x)