n=int(input('enter the limit : '))
fact=1
if(n>0):
    for i in range(1,n+1):
        fact*=i
    print("factorial of values upto %d : %d",n,fact)
else:
    print('can\'t find factorial of negative ')