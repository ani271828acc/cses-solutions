children_weight = list(map(int, input().split()))
number_of_children = children_weight[0]
max_weight = children_weight[1]
weights = list(map(int, input().split()))
weights = sorted(weights)
start = 0
end = number_of_children - 1
min_gondola = 0
while start <= end:
    if weights[start] + weights[end] > max_weight:
        end -= 1
    else:
        start += 1
        end -= 1
    min_gondola += 1
print(min_gondola)
