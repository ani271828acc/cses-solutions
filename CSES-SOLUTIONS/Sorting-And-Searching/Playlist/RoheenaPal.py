number_of_songs = int(input())
songs = list(map(int, input().split()))
found = {}
left = 0
unique = 0
for right in range(number_of_songs):
    if songs[right] not in found:
        unique = max(unique, right - left + 1)
    else:
        if found[songs[right]] < left:
            unique = max(unique, right - left + 1)
        else:
            left = found[songs[right]] + 1
    found[songs[right]] = right
print(unique)
