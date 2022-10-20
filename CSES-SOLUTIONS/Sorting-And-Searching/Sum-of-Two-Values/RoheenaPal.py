size_target = list(map(int, input().split()))
size = size_target[0]
target = size_target[1]
arr = list(map(int, input().split()))
numbers = {}
indicator = 0
for index, num in enumerate(arr):
    reqd = target - num
    if reqd in numbers:
        print(numbers[reqd], index + 1)
        indicator += 1
        break
    numbers[num] = index + 1
if indicator == 0:
    print("IMPOSSIBLE")
