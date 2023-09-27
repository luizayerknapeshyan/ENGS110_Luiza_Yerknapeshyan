def concatenate(number1, number2):
    result = 0
    
    nOfDigits = 0
    temp = number2
    
    while temp > 0:
        nOfDigits += 1 
        temp //= 10
        
    result = number1 * 10**nOfDigits + number2
    
    return result

def main():
    number1 = int(input("Enter a number: "))
    number2 = int(input("Enter a number: "))
    
    result = concatenate(number1, number2)
    
    print("The concatenated number is", result)
    return 0
    
if __name__ == "__main__":
    main()    
