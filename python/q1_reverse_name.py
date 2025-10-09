# 1.	Accept full name and display in reverse order with space between the words.
name=input('Enter full name : ').split()
for word in name[::-1]:
    print(word,end=' ')
