try:
    n=int(input("enter number: "))
    if n<0:
        raise ValueError("negative number ..")
    while n>1 and n%2==0:
        n//=2
    if n==1:
        print("power of 2")
    else:
        print("not power of 2")    
except Exception as e:
    print("error",e)