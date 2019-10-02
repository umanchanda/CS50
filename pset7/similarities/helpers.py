from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    set_a = set(a.split('\n'))
    set_b = set(b.split('\n'))
    return set_a & set_b


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    set_a = set(sent_tokenize(a))
    set_b = set(sent_tokenize(b))
    return set_a & set_b


def get_substrings(string, n):
    substrings = []
    for i in range(0, len(string)-n+1):
        substrings.append(string[i:i+n])
    return substrings


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    set_a = set(get_substrings(a, n))
    set_b = set(get_substrings(b, n))
    return set_a & set_b