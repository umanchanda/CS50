from sys import argv
from sys import exit
from cs50 import get_string


def main():
    if len(argv) != 2:
        exit("Usage: python caesar.py k")
    k = int(argv[1])
    if k < 0:
        exit("Usage: python caesar.py k")
    plaintext = get_string("plaintext: ")

    cipher = []
    for c in plaintext:
        if c.islower():
            cipher.append(chr(((ord(c) + k - 97) % 26) + 97))
        elif c.isupper():
            cipher.append(chr(((ord(c) + k - 65) % 26) + 65))
        else:
            cipher.append(c)
    ciphertext = ''.join(cipher)
    print('ciphertext:', ciphertext)


if __name__ == "__main__":
    main()