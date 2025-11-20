f=None
try:
    f=open('b.txt','r')
    lines=f.readlines()
    lines=[x for x in lines if x.startswith('a') and x.strip().endswith('e')]
    lines.pop()
    f.seek(0)
    print("lines removed")
except Exception as e:
    print("Error : ",e)
finally:
    if f is not None:f.close()