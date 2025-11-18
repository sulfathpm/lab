try:
    num=int(input("Enter a number:"))
    if(num<0):
        raise ValueError("Number should be non-negative.")
    if num!=0 and (num&(num-1)==0):
        print(num," is power of 2")
    else:
        print(num," isn't power of 2")
except Exception as e:
    print("Error : ",e)