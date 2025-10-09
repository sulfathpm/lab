n=int(input('enter a limit : '))
print("fibonacci series upto ",n,":")
a,b=0,1
for i in range(n):
    print(a,end=' ')
    a,b=b,a+b
print(' ')

