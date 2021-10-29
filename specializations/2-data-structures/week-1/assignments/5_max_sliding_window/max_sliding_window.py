# python3

from collections import deque


def max_sliding_window_naive(sequence, m):
    numbers = []
    maximums = deque()
    maximums.append(0)
    if (len(sequence) == 1):
        return sequence
    for i in range(1, m):
        while (len(maximums) > 0 and sequence[i] >= sequence[maximums[len(maximums) - 1]]):
            maximums.pop()
        maximums.append(i)
    
    numbers.append(sequence[maximums[0]])
    


    for i in range(m, len(sequence)):
        while (len(maximums) > 0 and sequence[i] >= sequence[maximums[len(maximums) - 1]]):
            maximums.pop()
        if (len(maximums) > 0 and maximums[0] == i - m):
            maximums.popleft()
        maximums.append(i)
        numbers.append(sequence[maximums[0]])

    return numbers

if __name__ == '__main__':
    n = int(input())
    input_sequence = [int(i) for i in input().split()]
    assert len(input_sequence) == n
    window_size = int(input())

    print(*max_sliding_window_naive(input_sequence, window_size))

