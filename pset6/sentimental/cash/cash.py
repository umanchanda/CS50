from cs50 import get_float

if __name__ == "__main__":
    cash = get_float("Change owed: ")
    coins = 0
    while cash >= 0.25:
        cash -= 0.25
        coins += 1
    while cash >= 0.10:
        cash -= 0.10
        coins += 1
    while cash >= 0.05:
        cash -= 0.05
        coins += 1
    while cash >= 0.01:
        cash -= 0.01
        coins += 1
    print(coins)