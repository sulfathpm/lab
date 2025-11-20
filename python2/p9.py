filename = "b.txt"

try:
    # Read all lines
    with open(filename, "r") as f:
        lines = f.readlines()

    # Keep only lines that do NOT start with 'a' and end with 'e'
    new_lines = [line for line in lines if not (line.startswith('a') and line.strip().endswith('e'))]

    # Write back remaining lines
    with open(filename, "w") as f:
        f.writelines(new_lines)

    print("Matching lines removed successfully.")

except Exception as e:
    print("Error:", e)
