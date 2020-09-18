# Beiju Text

I this problem you are taking the input of a messed up keyboard and showing what the actual input what was. The keyboard will occasionally press "HOME" and "END" which is idicated by "[" and "]" respectively. 

## Method

1. My first take on this problem was to keep two strings. The first one was the `final` string, and the second was a `current` string. Each time the HOME or END would show up, it would concatenate `current` and `final` depending on what the last HOME or END was, simulating a moving cursor. This was very effective and easy to implement, however it did not pass UVA speed, which led me to look into ways to optimize my functions, and ultimately came to the conclusion that *string concatenation in c++ is slow*. Since a string is just an array of chars, to concatenate, c++ has to allocate a new array the size of the two together, and then iterate through them and copy the values. The program did this many times over, making is approach O(n<sup>2</sup>), which would not do. To solve this, I needed a data structure that allowed me to literally move the cursor similar to how the question did, allowing me to not have to effectively rewrite the characters that had already been written. 

2. A `list` allowed me to do exaclty that. By using a list, I could create an iterator that would be moved from the beginning to the end depending on the input. `line.insert()` also conveniently adds the value to the list, growing it to fit the element in the position in front of the cursor, and then moves the cursor to it. To achieve something similar in a vector, to resize it would be O(n) with the size of the vector, while in a list, since it is doubly linked is O(n) with the number of elements inserted, which in this case is O(1)

## Algorithm

 1. Initialize list and entry
 2. cin entry (keyboard entry)
 3. Initialize list iterator cursor
 4. iterate through entry
    - if char is [ move cursor to beginning
    - if char is ] move cursor to end
    - else, insert char at cursor
5. print contents of list