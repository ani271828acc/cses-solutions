import bisect
 
n = int(input())
mas = [int(i) for i in input().split()]
towers = [mas[0]]
i = 1
while i != len(mas):
    a = mas[i]
    index = bisect.bisect_right(towers, a)
 
    if len(towers) > index and towers[index] > a:
        towers[index] = a
    else:
        towers.insert(index, a)
    i += 1
print(len(towers))
 