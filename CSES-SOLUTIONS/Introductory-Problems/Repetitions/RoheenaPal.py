dna_sequence = input()
prev = dna_sequence[0]
left = 0
right = 0
longest_sequence = 0
length = len(dna_sequence)
count = 0
while left <= right and right < length:
    if dna_sequence[left] == dna_sequence[right]:
        count += 1
        longest_sequence = max(count, longest_sequence)
        right += 1
    else:
        count = 0
        left = right
longest_sequence = max(count, longest_sequence)
print(longest_sequence)
