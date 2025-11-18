s=input("Enter a string: ")
if(len(s)<7 and len(s)%2==0):
    print("Enter a string of length greater than 7.")
else:
    mid=len(s)//2
    print("new string:",s[mid-1:mid+2])