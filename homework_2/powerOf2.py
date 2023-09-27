def powerOf2(number):
    if number == 1:
        return True
    elif number % 2 != 0:
        return False
    else:
        return powerOf2(number // 2)

def main():
    number = int(input("Enter a number: "))
    
    result = powerOf2(number);
    
    if result == True:
        print(number, "is a power of 2")
    else:
        print(number, "is NOT a power of 2")
    
    return 0
    
if __name__ == "__main__":
    main()    
