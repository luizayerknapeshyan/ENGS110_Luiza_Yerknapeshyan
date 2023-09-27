def rectangle(length, width, symbol):
    for i in range(length):
        if i == 0 or i == length - 1:
            print(symbol * (width - 1))
        else:
            print(symbol + ' ' * (width - 3) + symbol)

def main():
    symbol = input("Enter a character: ")
    N, M = map(int, input("Enter 2 integers: ").split())

    rectangle(N, M, symbol)

if __name__ == "__main__":
    main()
