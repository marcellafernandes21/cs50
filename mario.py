from cs50 import get_int

# Prompt user for the pyramid height
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break

# Generate the half-pyramid
for i in range(height):
    # Print the required number of spaces for alignment
    print(" " * (height - i - 1), end="")
    # Print the hashes for the current row
    print("#" * (i + 1))
