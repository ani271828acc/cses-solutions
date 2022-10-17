n = int(input())
numbers = list(map(int, input().split()))
print((n * ((n + 1))) // 2 - sum(numbers))
