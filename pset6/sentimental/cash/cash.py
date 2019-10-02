from cs50 import get_float

if __name__ == "__main__":
    while True:
        cash = get_float("Change owed: ")
        cash *= 100
        if cash > 0:
            break
    coins = 0
    while cash >= 25:
        cash -= 25
        coins += 1
    while cash >= 10:
        cash -= 10
        coins += 1
    while cash >= 5:
        cash -= 5
        coins += 1
    while cash >= 1:
        cash -= 1
        coins += 1
    print(coins)