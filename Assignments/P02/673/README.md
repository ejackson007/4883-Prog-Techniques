# Parentheses Balance

I solved this problem in python, as well as c++. The general solution was identical, but I will include language specific things that were used.

## General

The goal of the program is to see if a series of `()` and `[]` are syntatically correct, specifically that every opening is closed, as well as no hanging closers are included. To check for this, a stack was the best data structure. If a `( or [` is the current char in the sequence, it is pushed onto the stack. If a `) or ]` is the current char in the sequence, the stack is popped and compared for matching bracket type. The cases where it fails are:

1. Popped case does not match
2. A pop is attempted while the stack is empty

Knowing this, both languages followed this algorithm:

1. input how many cases are being checked
2. loop for the amount of cases
   1. set validity to true
   2. input the sequence to be checked
   3. loop for characters in sequence
      - if char is `(` or `[`
        - push onto stack
      - else
        - check if stack size is 0
          - validity is false and exit loop
        - check if the top value is matching the case for char
          - pop stack
        - if they don't match
          - validity is false and exit loop
   4. print `Yes` or `No` based on validity
   5. empty stack

## Language Specifics

### Python

- Input sees in the lines as strings, which are iterable by character so looping and input was simple
- The built in list can be dynamically created, and includes the `pop()` method, making implementation as a stack simple

### C++

- Vector used as stack so that it can be grown dynamically
- If `cin` is used, an empty line would be skipped as newline is seen as a delimeter, therefore `getline()` is used
- `getline()` brings its own issues. It will only accept a string or char as a parameter to be written to, therefore `stoi()` has to be used to turn the count back to an int
  - `cin` cannot be used easily with `getline()`, as `getline()` will reread the same line.
- string is technically an array of char, therefore it can be iterated through easily.
