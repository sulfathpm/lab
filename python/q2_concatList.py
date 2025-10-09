# 2.	 Accept a list of single digit numbers as input string. Concatenate the elements of the list as a single number.

l=input('enter a list of numbers(0 - 9) : ').split()
concat_num="".join(l)
num=int(concat_num)
print("concatenated number  : ",num)