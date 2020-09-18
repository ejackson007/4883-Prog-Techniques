# Team Queues

In this problem you are given a list of numbers to add into a queue that will be taken out of the queue as the program goes on. The catch is that these numbers are members of _teams_ which allows them to cut in line to join their team. If the team isn't present in the line, they have to go to the back. While easy in concept, there are a lot of things you have to keep up with for each member that makes it complex to program. To solve the problem, I made the following decision.

## Method

1. *Order doesn't matter... Kind Of*
    - Similar to when you go to the DMV, you don't actually stand in line, instead you take a ticket that and sit down. Physically you are not in a line, however your position is remembered. In the same way as long as each team stays in order, and the program knows the order in which to call the teams, the teams do not have to line up together.
2. *Member Recognization*
    - Knowing what team the member is a part of is integral to the program, and will end up being pivotal in how the teams are chosen to be stored. To quickly recognize what team a member is a part of, as they are being read in, they are being added to an unordered_map with the key being their team as an integer. Given that their team numbers are also 0-n, it is very convenient to store the team queue as a vector of queues, since their team number can be used as the index in the vector. 
3. *Team Order*
    - If a team member joins the line and there are no other team members, it enters the line at the back, otherwise it joins its team. To check which lines were empty every iteration would be ineffiecent, and knowing which team has to be in the front would require a pair or every queue to have a value regularly changed. This would also mean that every iteration of a memeber exiting the line is potentially O(n) since it needs to find the queue that has line position 0. Whats much easier than this is to implement a queue and set that function together to find this. Whenever a team memember joins the line, its team number is checked to see if it exists in the set. If its not, its added to the stack and then pushed onto the queue (meaning there were no other team members it could join), otherwise you move on. When a memeber leave, the top value of the queue (front team) to see if they have any more memebers. If its empty the value is popped and removed from the set. This allows for the order of the teams to be kept and found at no worse than O(logn) due to finding and removing values from the set. 

## Algorithm

1. Initialize variables
2. cin number of teams
3. for teams
    - cin members and assign team values
4. Until commands stop
    1. If ENQUEUE
        - cin member
        - if memeber is first of team in line
            - add team to line queue
            - add team number to has members in line set
        - add memeber to team line
    2. If DEQUEUE
        - cout first member of team thats first in line and remove from line
        - if team line is empty
            - pop line queue
            - remove from members in line set
5. clear line queue, line set, team lines

