lines = int(input())
stack = []

for _ in range(lines):
    valid = True  # set to true before input
    sequence = [char for char in input()]
    for char in sequence:
        # append for opening
        if char == '(' or char == '[':
            stack.append(char)
        else:
            # if a popping case and empty it fails
            if len(stack) == 0:
                valid = False
                break
            # pop matching
            elif char == ')' and stack[-1] == '(':
                stack.pop()
            elif char == ']' and stack[-1] == '[':
                stack.pop()
            # fail if doesnt match case
            else:
                valid = False
                break
    # after trying all cases
    if(valid and len(stack) == 0):
        print('Yes')
    else:
        print('No')
