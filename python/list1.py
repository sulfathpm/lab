# sum of elements of a list

lst=input('enter a list : ').split()
# l=list(map(int,lst.))
sum=0
if(len(lst)==0):
    print('')
else:
    for i in lst:
        if i.isalpha():
            continue
        else:
            sum=sum+float(i)
print('sum : ',sum)