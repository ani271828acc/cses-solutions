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
print(abs(area))
