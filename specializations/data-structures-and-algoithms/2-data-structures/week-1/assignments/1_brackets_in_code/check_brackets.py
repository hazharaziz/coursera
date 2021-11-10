# python3

from collections import namedtuple

Bracket = namedtuple("Bracket", ["char", "position"])


def are_matching(left, right):
    return (left + right) in ["()", "[]", "{}"]


def is_balanced(text):
    char_indices = []
    opening_brackets_stack = []
    for i, next in enumerate(text):
        if next in "([{":
            opening_brackets_stack.append(next)
            char_indices.append(i + 1)

        if next in ")]}":
            if (len(opening_brackets_stack) == 0):
                return i + 1
            top = opening_brackets_stack.pop()
            char_indices.pop()
            if (are_matching(top, next) == False):
                return i + 1

    if (len(opening_brackets_stack) != 0):
        return char_indices[0]
    return len(opening_brackets_stack)

def main():
    text = input()
    # text = "[](()"
    # text = "[]"
    mismatch = is_balanced(text)

    if mismatch == 0:
        print('Success')
    else:
        print(str(mismatch))
        



if __name__ == "__main__":
    main()
