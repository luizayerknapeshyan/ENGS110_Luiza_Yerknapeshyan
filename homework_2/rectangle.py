def rectangle(length, width):
    for i in range(length):
        if i == 0 or i == length - 1:
            print('*' * (width - 1))
        else:
            print('*' + ' ' * (width - 3) + '*')

def main():
    N, M = map(int, input("Enter 2 integers: ").split())
    rectangle(N, M)

if __name__ == "__main__":
    main()
