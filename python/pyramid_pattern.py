
#      *
#    *   *
# *    *   *



n=int(input('limit = ?'))

for i in range(0,n):
    # for j in range(0,2*(n-i-1)+1):
    # To repeat a string multiple times, you need to use the * operator
    print(' ' * (n - 1 - i), end='')    
    # for k in range(0,i+1):
    print(' * ' * (i + 1))
