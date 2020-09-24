# Trees on the Level

In this problem, you are given a probelm where you are given arbitrary leaves of a Binary Tree. Each value has a sequence of `L` and `R` that dictates the path you use to navigate to the position of the leaf. After the tree is completed, your output is either the in-order traversal of the tree, or `not completed` if it is an invalid tree, i.e leaves without a parent. 

*I ran into a lot of issues*

## Problems

### Memory limitations
Knowing that I had to output an in-order traversal, I believed that an array implementation would be easily used. You could easily calculate what index to store each number in using the directions. The major problem with this however is that there is a maximum of 256 nodes in any tree. Worst case scenario, that means that there would be 2<sup>256</sup> indexes needed in the array! With 4 bytes a piece, the array would need ~4.6 Terabytes of memory, which is definitely not an option.

### Size limitation
To save on memory, my idea was to use a vector instead of an array. By storing them into a vector, I could guarantee myself an array of size 256 max. The "location" in the array would still be important however since I needed something to compare to and see where it belonged when the vector was sorted, which is when I ran into an issue. Do to an integer being 4 bytes, it is physcially incapable of storing a value over 2<sup>32</sup>. Even with a long long int, its maximum value is 2<sup>64</sup>.
At this point I was stuck. The only way to compare the values was to account for every unique combination, which was too large to do. The way to compare the strings was just that though. All I had to do was to compare the strings.

> s1 < s2 : A string s1 is smaller than s2 string, if either, length of s1 is shorter than s2 or first mismatched character is smaller.
>   - Some guy at GeeksforGeeks who wrote an article and saved my life

## Solution

### Storage
By some stroke of luck, comparing the two strings is exactly what I had to do. In my own practice, comparisons between different sized strings is unreliable, but as long as they are the same size, it is exactly what I needed. Since `R` is a larger ascii value than `L`, Whichever string has a right turn first is seen as larger, which is also true for the actual tree. Knowing this I could implement a vector with priority queues of pairs of a string and integer. Each string value pair would be inserted into the vector at the position of its strings length, guaranteeing that all the inputs are with same lengths.

### Checking viability
After all of the leaves is inserted, checking to see if the values are possible is fairly trivial. A new vector of integers is created, and the tree vector has all of its values pushed off in order. As each leaf is moved, the positional string has the back popped off, which would give the positional string of its parent. That string is searched for in a set that contains all of the strings seen in, and as long as its valid it is moved. If at any time that string cannot be found, a boolean is marked is invalid. The output is either the vector in order, or `not complete` depending on the condition of the boolean. 

