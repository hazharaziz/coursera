#python3
import sys

class StackWithMax():
    def __init__(self):
        self.max = float('-inf')
        self.stack = []
        self.max_numbers = []

    def Push(self, a):
        if (a >= self.max):
            self.max = a
            self.max_numbers.append(self.max)
        self.stack.append(a)

    def Pop(self):
        if (len(self.stack) == 0):
            return
        element = self.stack.pop()
        if (self.max == element):
            self.max_numbers.pop()
            self.max = self.max_numbers[len(self.max_numbers) - 1]

    def Max(self):
        return self.max


if __name__ == '__main__':
    stack = StackWithMax()

    num_queries = int(sys.stdin.readline())
    results = []
    for _ in range(num_queries):
        query = sys.stdin.readline().split()

        if query[0] == "push":
            stack.Push(int(query[1]))
        elif query[0] == "pop":
            stack.Pop()
        elif query[0] == "max":
            results.append(stack.Max())
        else:
            assert(0)

    for number in results:
        print(number)