# 6.	Write a program that count the number of strings where string length is 2 or more and the first and last characters are same.
s=input('Enter a list of string : ').split()
count=0
for i in s:
    if(len(i)>1 and i[0]==i[-1]):
        count+=1
        # print('strings with length  2 or more and the first and last characters are same : ',i)

print('Number strings with length  2 or more and the first and last characters are same : ',count)