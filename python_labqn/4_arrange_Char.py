s=input("Enter a string:")
lower=""
upper=""
for ch in s: 
    if(ch.islower()):
        lower+=ch
    else:
        upper+=ch
print("Arranged characters :",lower+upper)