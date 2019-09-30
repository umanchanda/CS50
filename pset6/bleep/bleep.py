from cs50 import get_string
from sys import argv
from sys import exit


def get_banned_words(filename):
    f = open(filename, "r")
    words = f.readlines()
    words = [word.strip() for word in words]
    return words


def main():
    if len(argv) != 2:
        exit("Usage: python bleep.py dictionary")
    message = input("What message would you like to censor?\n")
    new_msg = []
    for word in message.strip().split():
        if word.lower() in get_banned_words(argv[1]):
            new_msg.append(len(word) * '*')
        else:
            new_msg.append(word)
    print(' '.join(new_msg))


if __name__ == "__main__":
    main()
    
