number_of_coins = int(input())
coins = list(map(int, input().split()))
coins.sort()
least_sum = 1
for index in range(0, number_of_coins):
    if coins[index] <= least_sum:
        least_sum += coins[index]
    else:
        break
print(least_sum)
