# python3

class Heap:

    def __init__(self, initial_tree) -> None:
        self.maxSize = len(initial_tree)
        self.size = self.maxSize
        self.heap = initial_tree
       
    def get_parent(self, index):
        return (index - 1)  // 2
    
    def get_right(self, index):
        return 2 * index + 2
    
    def get_left(self, index):
        return 2 * index + 1

    def sift_up(self, index):
        pass

    def sift_down(self, index):
        pass

    def extract_max(self):
        pass

    def insert(self, node):
        pass

    def remove(self, index):
        pass

    def build_heap(self):
        pass
    
    def heap_sort(self):
        pass
    
    def partial_sort(self):
        pass


class MinHeap(Heap):

    def __init__(self, initial_tree) -> None:
        super().__init__(initial_tree)
        self.swaps = []

    def sift_up(self, index):
        parent_index = self.get_parent(index)
        while (index > 0) and (self.heap[parent_index] >= self.heap[index]):
            self.heap[parent_index], self.heap[index] = self.heap[index], self.heap[parent_index]
            self.swaps.append((parent_index, index))
            # print(f"{parent_index} {index}")
            index = parent_index
            parent_index = self.get_parent(index)

    def sift_down(self, index):
        min_index = index
        right_index = self.get_right(index)
        if (right_index < self.size) and (self.heap[min_index] > self.heap[right_index]):
            min_index = right_index

        left_index = self.get_left(index)
        if (left_index < self.size) and (self.heap[min_index] > self.heap[left_index]):
            min_index = left_index

        if (min_index != index):
            self.heap[min_index], self.heap[index] = self.heap[index], self.heap[min_index]
            self.swaps.append((index, min_index))
            self.sift_down(min_index) 

    def build_heap(self):
        for i in range(self.size // 2, -1, -1):
            self.sift_down(i)

def main():
    n = int(input())
    data = list(map(int, input().split()))
    assert len(data) == n

    heap = MinHeap(data)
    heap.build_heap()

    print(len(heap.swaps))
    for i, j in heap.swaps:
        print(i, j)

if __name__ == "__main__":
    main()
