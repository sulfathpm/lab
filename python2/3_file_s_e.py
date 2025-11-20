f=None
try:
    f=open('a.txt','r')
    lines=f.readlines()
    lines=[x for x in lines if x.startswith('s') and x.strip().endswith('e')]
    print(lines)
except Exception as e:
    print("Error : ",e)
finally:
    if f is not None:f.close()