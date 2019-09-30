from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    same = []
    for x in a.split('\n'):
        for y in b.split('\n'):
            if x == y:
                same.append(x)
    return same[0:-1]


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    same = []
    for x in sent_tokenize(a):
        for y in sent_tokenize(b):
            if x == y:
                same.append(x)
    return same


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    return []

# if __name__ == "__main__":
#     print(lines("hello world\n", "hello world\n"))