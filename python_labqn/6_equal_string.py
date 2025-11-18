s1 = input("Enter s1: ")
s2 = input("Enter s2: ")
def nearly_equal(s1, s2):
    if abs(len(s1) - len(s2)) > 1:
        return False

    i = j = 0
    mismatch = 0

    while i < len(s1) and j < len(s2):
        if s1[i] != s2[j]:
            mismatch += 1
            if mismatch > 1:
                return False

            if len(s1) > len(s2):
                i += 1
            elif len(s1) < len(s2):
                j += 1
            else:
                i += 1
                j += 1
        else:
            i += 1
            j += 1

    return True
if nearly_equal(s1, s2):
    print("Strings are nearly equal")
else:
    print("Strings are NOT nearly equal")