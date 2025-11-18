
l=int(input("Enter the limit : "))
sum=0
a,b=0,1
for i in range(0,l):
    if(a%2==0):
        sum=sum+a
    a,b=b,a+b
print("Sum : ",sum)

        