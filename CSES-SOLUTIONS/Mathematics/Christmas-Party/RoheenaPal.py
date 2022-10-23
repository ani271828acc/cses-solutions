n = int(input())
if n == 1:
    print('0')
else:
    derrange = [0, 0, 1]
    mod = 1000000007
    for index in range(3, n + 1):
        ways = (((derrange[index - 1] + derrange[index - 2]) % mod) * ((index - 1) % mod)) % mod
        derrange.append(ways)
    print(derrange[-1])
