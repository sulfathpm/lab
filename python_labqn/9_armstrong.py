print("Armstrong number between 100 and 500: ")
for num in range(100,500):
    temp=num
    digits=len(str(num))
    sum=0
    while(temp>0):
        d=temp%10
        sum+=d**digits
        temp//=10
    if(sum==num):
        print(num)