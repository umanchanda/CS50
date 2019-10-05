from cs50 import get_int


def isValid(creditcard):
    firstsum = 0
    for c in str(creditcard)[-2:0:-2]:
        firstsum += (int(c) * 2)
    
    secondsum = 0
    for c in str(creditcard)[-1:0:-2]:
        secondsum += int(c)
    
    return ((firstsum + secondsum) % 10) != 0


if __name__ == "__main__":
    while True:
        number = get_int("Number: ")
        if number > 0:
            break
    
    if isValid(number) == False:
        print("INVALID")
    else:
        if len(str(number)) == 15 and (str(number)[0:2] == '34' or str(number)[0:2] == '37'):
            print("AMEX")
        elif len(str(number)) == 16 and (str(number)[0:2] == '51' or str(number)[0:2] == '52' or str(number)[0:2] == '53' or str(number)[0:2] == '54' or str(number)[0:2] == '55'):
            print("MASTERCARD")
        elif (len(str(number)) == 13 or len(str(number)) == 16) and str(number)[0] == '4':
            print("VISA")
        else:
            print("INVALID")