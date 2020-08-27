# Cost Cutting

In this problem, we are given 3 values, and must print the median value. The input is as follows:

1. `T` number of inputs
2. Three non ordered integers

It is possible to do a lot of comparisons inbetween the variables to find the median, however this would be long to write, as well as inefficient. The better solution would be to sort the values. Knowing that there are 3 values, the median after sorting will always be the middle of the two. While filling an array and then sorting it would be a possiblility, I instead decided to solve the problem using a `priority_queue` which will sort it as I add the values. By using this, I avoid writing a sort method / importing one. Admittedly however, if the number of values was more than 3 / unknown size, filling a vector and then sorting would be much more efficient extracting the value, that being said for the sample size this was an effective and simple solution. The solution is as follows:

1. initialize ints t, e1, e2, e3
2. intialize priority_queue pq
3. cin t
4. loop t times
   1. cin e1, e2, e3
   2. push e1, e2, e3 onto pq
   3. pop pq
   4. print top value
   5. empty pq
