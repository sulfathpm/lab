# 9.	Write lambda functions:
# (a) To find largest of 2 numbers
# (b)  To check the input number is divisible by 5
# (c) To remove all strings with length < 5 from a list of strings
# (d)  To increment a list of integers by 10% if the number is greater than 1000 else by 5%.

largest=lambda x,y:x if x>y else y
print(largest(2,3))

div=lambda x:'divisible' if not x%5 else 'not divisible'
print(div(57))

rString=lambda s:[x for x in s.split() if len(x)>5]
l=list(filter(lambda x:len(x)>5,s.split()))