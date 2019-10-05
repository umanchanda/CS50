from cs50 import get_int

if __name__ == "__main__":
    while True:
        height = get_int("Height: ")
        if height > 0 and height <= 8:
            break
    
    for i in range(height):
        for space in range(0, height-i-1):
            print(' ', end="")
        print('#', end="")
        for hash in range(0, i):
            print('#', end="")
        print('\n', end="")