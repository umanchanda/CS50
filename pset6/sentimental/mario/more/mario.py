from cs50 import get_int

if __name__ == "__main__":
    while True:
        height = get_int("Height: ")
        if height > 0 and height <= 8:
            break
    
    for i in range(height):
        for j in range(height-i-1):
            print(" ", end="")
        for hash in range(i+1):
            print('#', end="")
        print(" ", end=" ")
        for hash in range(i+1):
            print("#", end="")
        print('\n', end="")