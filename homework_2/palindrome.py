def inverse(number):
    remainder = 0
    result = 0
    
    while number > 0:
        remainder = number % 10
        number //= 10
        
        result = (result * 10) + remainder
        
    return result

def main():
    number = int(input("Enter a number: "))
    
    result = inverse(number)
    
    if number == result:
        print("The number is a palindrome.")
    else:
        print("The number is NOT a palindrome.")
    
    return 0
    
if __name__ == "__main__":
    main()    
