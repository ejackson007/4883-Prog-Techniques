priority = {
    '+': 1,
    '-': 1,
    '*': 2,
    '/': 2
}

stack = []
postfix = ''
problems = int(input())
# kill first empty line
input()
current = input()
for _ in range(problems):
    while current != '':
        if current == '(':
            stack.append(current)
        elif current == ')':
            while stack[-1] != '(':
                postfix = postfix + stack.pop()
            stack.pop()
        elif current not in priority:
            postfix = postfix + current
        # cannot read back of stack with not elements, therefore append to empty
        elif len(stack) == 0 or stack[-1] == '(':
            stack.append(current)
        # current priority is larger than stack top priority
        elif priority[current] > priority[stack[-1]]:
            stack.append(current)
        # current priority is smaller than stack top priority
        elif priority[current] < priority[stack[-1]]:
            while len(stack) != 0 and stack[-1] != '(':
                postfix = postfix + stack.pop()
            stack.append(current)
        # current priority is equal to stack top priority
        else:
            postfix = postfix + stack.pop()
            stack.append(current)
        # crashes after last '' with eof error for unknown reason.
        try:
            current = input()
        except EOFError:
            break

    while len(stack) != 0:
        postfix = postfix + stack.pop()
    print(postfix)
    postfix = ''
    # crashes with end of file error. at end of input
    try:
        current = input()
        print()  # do not print on last postfix
    except EOFError:
        break
