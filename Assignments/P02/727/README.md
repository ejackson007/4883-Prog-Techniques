# Equation

The goal of this program is to turn infix equations to post script. Using a stack and a priority list for operators, the algorithm follows a few rules, which are as follows:

1. if the value is a number, write it out
2. if the value is a `(` push it onto the stack
3. if the value is a `)` pop everything off the stack until the nearest `(`
4. if the operator priority is greater than the top of the stacks priority, push it onto the stack
5. if the operator priority is less than the top of the stacks priority, pop the stack until it is empty or reaches a `(`, and then push the operator
6. if the operator priority is equal to the top of the stacks priority, pop the top of the stack, and push the operator

Knowing these rules, the algorithm is as follows:

1. initilize dictionary for value look up table
2. initilize stack
3. initilize postifx string
4. input the number of problems
5. input the first char in the equation string
6. loop for number of problems
   1. while current char isnt ''
      - if current is `(` push to stack
      - elif current is `)`, pop until you reach closing
      - elif current is number, write to postfix
      - elif stack is empty of top is `(`, push to stack
      - elif current priority is greater than stack, push to stack
      - elif current priority is less than stack, empty stack to nothing or `(` and push current to stack
      - elif current priority is euqal to stack, pop stack and push current
   2. pop remainder of stack
   3. print new postfix
   4. clear postfix
   5. input new current
