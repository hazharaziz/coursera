# python3

import sys
import threading


class Tree:
    
    def __init__(self, key):
        self.key = key
        self.children = []


def create_tree(n, nodes, parents):
    for i in range(n):
        if parents[i] == -1:
            continue
        nodes[parents[i]].children.append(nodes[i])

    for i in range(n):
        if parents[i] == -1:
            tree = nodes[i]


    return tree
        



def compute_height(tree):
    max_height = 0
    if (len(tree.children) == 0):
        return 1 + max_height
    
    temp = 0
    for child in tree.children:
        temp = compute_height(child)
        if (temp > max_height):
            max_height = temp

    return 1 + max_height


def main():
    n = int(input())
    parents = list(map(int, input().split()))
    nodes = [Tree(i) for i in range(n)]
    tree = create_tree(n, nodes, parents)
    print(compute_height(tree))


# In Python, the default limit on recursion depth is rather low,
# so raise it here for this problem. Note that to take advantage
# of bigger stack, we have to launch the computation in a new thread.
sys.setrecursionlimit(10**7)  # max depth of recursion
threading.stack_size(2**27)   # new thread will get stack of such size
threading.Thread(target=main).start()
