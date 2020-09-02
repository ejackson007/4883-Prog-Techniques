# Relational Operator

In this problem we are checking coordinates against a moving origin point to find their quadrant. The input is the folowing:

1. `K` number of coordinates that will follow after the origin is given
2. `N & M` coordinates of the origin
3. `X & Y` coordinates to be checked

After all the coordinates are readm there may or may not be more coordinates with a new origin. A 0 is given as the K value to denote if there are any more data sets to run. If output is the quadrant on a coordinate plane, with the quadrant value mapped to the following strings:

![quadrants](https://schooltutoring.com/wp-content/uploads/sites/2/CP3.png?w=640)

- Q1 : NE
- Q2 : NO
- Q3 : SO
- Q4 : SE
- on x or y axis : divisa

Knowing this, to solve you just need to compare the coordinate to the origin given, and print the value desired given the quadrant that they are in.

The code follows the steps as follows:

1. initialize ints k, n, m, x, y
2. initialize bool run = true
   - This is done so that a while loop can be used to stop the program from running when needed
3. cin initial k
4. while run == true
   1. cin n, m
   2. loop k times
      1. cin x, y
      2. compare n, m, x, y
         - if x > n && y > m print 'NE'
         - if x > n && y < m print 'SE'
         - if x < n && y < m print 'SO'
         - if x < n && y > m print 'NO'
         - else print divisa
   3. cin new k
   4. if k == 0, run == false
