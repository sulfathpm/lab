
s1 = input("Enter s1: ")
s2 = input("Enter s2: ")

def nearly_equal(s1, s2):
    if len(s1) != len(s2):
        return False

    mismatch = 0
    for a, b in zip(s1, s2):
        if a != b:
            mismatch += 1
        if mismatch > 1:
            return False
    return True

if nearly_equal(s1, s2):
    print("Strings are nearly equal")
else:
    print("Strings are NOT nearly equal")
