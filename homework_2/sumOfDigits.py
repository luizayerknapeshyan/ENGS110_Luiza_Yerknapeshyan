def sumOfDigits(number):
    remainder = 0
    result = 0
    
    while number > 0:
        remainder = number % 10
        number //= 10
        
        result += remainder
        
    return result

def main():
    number = int(input("Enter a number: "))
    
    result = sumOfDigits(number)
    
    print("The sum of the digits is", result)
    
    return 0
    
if __name__ == "__main__":
    main()    
