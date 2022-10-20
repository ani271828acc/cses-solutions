n = int(input())
if n % 4 == 1 or n % 4 == 2:
    print("NO")
elif n % 4 == 3:
    print("YES")
    print(n // 2)
    for i in range(2, n // 2 + 1, 2):
        print(i, n - i, end = " ")
    print(n)
    print(n // 2 + 1)
    for i in range(1, n // 2 + 1, 2):
        print(i, n - i, end = " ")
    print("", end = "\n")
else:
    print("YES")
    print(n // 2)
    for i in range(2, n // 2 + 1, 2):
        print(i, n - i + 1, end = " ")
    print("", end = "\n")
    print(n // 2)
    for i in range(1, n // 2 + 1, 2):
        print(i, n - i + 1, end = " ")
