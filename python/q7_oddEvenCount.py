# 7.	 Write a program that counts odd and even numbers in a given list.

def oddEvenC(n):
    oddC=0
    evenC=0
    for i in n:
        if(not i%2):
            evenC+=1
        else:
            oddC+=1
    print('count of odd numbers : ',oddC,'\nCount of even numvers: ',evenC)

n=input('Enter a list of numbers : ')
n=list(map(int,n.split()))
oddEvenC(n)
