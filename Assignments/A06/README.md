# Assignment 6

## Walkthrough of SCUD Busters (UVA 109)

This question involves neighboring kingdoms, and the desctruction of their power lines via a missle (the question ensured us that it wouldn't cause any casualites thank goodness). In the problem, you are tasked with finding the area of powered kingdoms, namely the ones that didn't get hit by a SCUD missle. The process of finding this is fairly simple. 

### 1. Define the Kingdoms

The input is given to us by defining the kingdoms perimeter as a series of coordinates. Since the number of kingdoms is not predetermined, meaning the input tells you when to stop and not how many kingdoms there are, a vector is prefered to store the kingdoms. Each kingdoms is definied by its coordinates, therefore a `vector<pair<int,int>>` is perfect to store this. Each kingdom will be pushed onto the vector. Some of these points are internal however, therefore we can find the _Convex Hull_ which gives us coordinates that are used for the perimeter of the kingdom, which ultimately are the only coordinates that we need, therefore after determining this, we can remove the rest. A function to find the Convex Hull is given on *page 289*

### 2. Find Powered Kingdoms

The missles are definied by giving us a coordinate pair of where they will land to take out a power plant. Knowing this, if we can find in which kingdom the missle landed in, we can remove it from the list of areas to calculate. The textbook gives us a simple function we can use to determine whether a coordinate is inside of a polygon on *page 287*. Using this we can step through the vector of kingdoms, checking if the point is in the kingdom, which if found true, we can remove the the kingdom from the vector since we will not have to calculate its area.

### 3. Calculate Area of Powered Kingdoms

Now that the vector of kingdoms has removed the ones that are not powered, we can calculate the total area. Again, the textbook has a simple function we can use to calculate the area of a polygon on *page 286*. We can keep an area total by iterating through the vector of kingdoms, calculating the sub area, and adding it to the total area. At the end we will have our solution!