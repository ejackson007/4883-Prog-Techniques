# Packing for Holiday

In this program you are given the dimensions of an object, and are tasked to see if it would fit within a 20x20x20 suit case. The input is as follows:

1. `T` how many lines of input
2. 3 integers

Given that all the objects are also cubical in nature, the easiest way to see if one of them would fit would be to check if either the width, height, or depth of the object is over 20 units. Given that only one needs to be true, doing an `OR` operation between the 3 would be the simplest way to do so, however I wanted to use this as a test for another method, which in this case isn't any more efficient, but sure is a lot more cool.

Given that in c++, the boolean values of true or false are seen as 1 and 0 respectively, you can use them in arithmetic. Knowing this, I created a boolean called fits, and set it equal to the product of the 3 comparisons. This means that if any of them were false, it would set the product to false as well. For example:

```
fits = (1 <= 20) * (2 <= 20) * (21 <= 20)
which is equivalent to
fits = 1 * 1 * 0
```

This effectively is equivalent to an `OR` statement between all of them. Given that, the code is as follows:

1. initialize ints items, w, h, d
2. initialize bool fits
3. cin items
4. loop for all items
   1. sin w, h, d
   2. calculate fits
      - if fits, print "Case #: good"
      - if does not fit, print "Case #: bad"
