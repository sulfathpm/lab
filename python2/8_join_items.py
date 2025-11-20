def join_items(s):
    if(s==""):return ""
    else:
        return "-".join(s[0:])

s=input("Enter a list : ").split()
print("New list : ",join_items(s))