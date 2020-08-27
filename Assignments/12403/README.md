# Save Setu

In this problem we are calculating how much money is donated. With the input there are two distinct commands

1. `'donate K'`
2. `report`

If donate is written, than the integer _K_ is added to the total, and if report is written, than the total is printed.

An important distinction is that 'donate' and 'report' are the **only two possibilities** which means that I do not need and `else if` since it is a boolean. That being said the question is very straight forward, and the code follows the steps as follows

1. initialize ints t (lines to read), donate, and total = 0
2. initialize string command
3. cin t
4. loop t times
   1. cin command
   2. check if command == 'donate'
      - True, cin donate and add to total
      - False, cout total
