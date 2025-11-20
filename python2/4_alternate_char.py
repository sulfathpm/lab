
def alternate_char(s):
    if(s==""):return ""
    else:
        return s[0]+alternate_char(s[2::1])

s=input("Enter a line of text : ")
print("New String : ",alternate_char(s))
