n_m_k = list(map(int, input().split()))
n, m, k = n_m_k[0], n_m_k[1], n_m_k[2]
size_reqd = list(map(int, input().split()))
size_available = list(map(int, input().split()))
reqd = 0
available = 0
size_reqd = sorted(size_reqd)
size_available = sorted(size_available)
getting = 0
while reqd < n and available < m:
    if abs(size_reqd[reqd] - size_available[available]) <= k:
        getting += 1
        reqd += 1
        available += 1
    elif size_reqd[reqd] < size_available[available]:
        reqd += 1
    else:
        available += 1
print(getting)
