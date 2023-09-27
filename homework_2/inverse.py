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
    
    print("The inverse of the number is", result)
    
    return 0
    
if __name__ == "__main__":
    main()    
