def find_index(arr, num, low, high):
    if low == 0 and high == -1:
        return 0
    if high == low:
        if arr[low] > num:
            return 0 if low == 0 else low
        else:
            return low+1
    elif high > low:
        mid = (high + low) // 2
        if arr[mid] > num:
            return find_index(arr, num, low, mid-1)
        else:
            return find_index(arr, num, mid+1, high)
    else:
        return low

sorted_list = []
result = 0
with open('cisla.in') as input_file:
    n = int(input_file.readline())
    permutations = [int(x) for x in input_file.readline().split(' ')] if n != 0 else []
    # permutations.insert(0, 99)

for permutation in permutations:
    new_index = find_index(sorted_list, permutation, 0, len(sorted_list)-1)
    result += len(sorted_list)-new_index
    sorted_list.insert(new_index, permutation)

print(result)
