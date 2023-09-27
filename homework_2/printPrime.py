def isPrime(number):
    result = True
    i = 2
    
    if number == 0 or number == 1:
        result = False
    elif number == 2:
        return result
    else:
        while i < number / 2 + 1:
            if number % i == 0:
                result = False
                
            i += 1
        
    return result

def main():
    number = int(input("Enter a number: "))
    
    for i in range (0, number, 1):
        result = isPrime(i)
        if result == True:
            print(i)
    
    return 0
    
if __name__ == "__main__":
    main()    
