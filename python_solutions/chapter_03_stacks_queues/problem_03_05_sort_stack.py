from . import Stack as s


def sort_stack(stack):
    temp = s.Stack()
    smallest = None
    stack_size = stack.size
    for i in range(stack_size):
        for j in range(stack_size - i, 0, -1):  #
            current = stack.pop()
            if smallest is None:
                smallest = current
            else:
                if current < smallest:
                    temp.push(smallest)
                    smallest = current
                else:
                    temp.push(current)
        stack.push(smallest)
        smallest = None
        while not temp.is_empty():
            stack.push(temp.pop())
