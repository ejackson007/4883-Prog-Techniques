# Rails

In this problem you are attempting to get cars to the otherside of a railway station. Your two options are to drive the car straight over, or to park it in the parking lot, the caveat being that the parking follows Last-In-First-Out. The input gives the number of cars, and then the desired outcome. If the desired outcome is a 0, the next input is a new amount of cars. If the amount of cars is also 0, than the program quits. Knowing this, the algorithm is as follows:

1. input number of cars
2. while number of cars is not 0
   1. create line 1 - number of cars
   2. create copy of line that can be edited
   3. input desired outcome
   4. while desired outcome is not 0
      1. loop through cars in expected outcome
         - go through line until the desired car is found in line or in parking lot, pushing cars from line to parking lot
         - if car isn't available in line, or first to come out of parking lot, than the desired outcome is marked as impossible
      2. input new desired outcome
   5. input new number of cars
