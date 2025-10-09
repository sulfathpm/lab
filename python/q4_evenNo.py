# 4.	Write a program to print all even numbers from a given list in the given order until you reach number 237 or end of the list. 

def evenNo(n):
    for item in n:
        if(item==237):
            # print('\nencountered 237.Exiting...')
            break
        elif not item%2:print(item,end=' ')

n=input('Enter a list')
n=list(map(int,n.split()))
evenNo(n)