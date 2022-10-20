from math import gcd

points = int(input())
x = []
y = []
for point in range(points):
    x_y = list(map(int, input().split()))
    x.append(x_y[0])
    y.append(x_y[1])
x.append(x[0])
y.append(y[0])
area = 0
for point in range(points):
    area += x[point] * y[point + 1]
    area -= y[point] * x[point + 1]
area = abs(area)
boundary = 0
for point in range(points):
    if x[point + 1] == x[point]:
        boundary += abs(y[point + 1] - y[point])
    elif(y[point + 1] == y[point]):
        boundary += abs(x[point + 1] - x[point])
    else:
        boundary += gcd(abs(x[point + 1] - x[point]), abs(y[point + 1] - y[point]))
print((area + 2 - boundary) // 2, boundary)
