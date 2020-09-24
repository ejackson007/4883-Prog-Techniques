# Binary Search Tree

In this problem you are given the output of a pre order traversal of a tree, and then are tasked with printing the post order traversal.

## Process

Knowing how a post order traversal work, vs a pre order, you can backwards from the root of the pre order, and then get the post order by traversing back through the tree recursively left and then right. The root can be found as the first value of the pre order. 

The algorithm is as follows:

1. Initialize Variables
2. cin pre order
3. Create post order(preorder, min, max, index)
    1. if index is at end of preorder, return
    2. if pre[index] outside of min max range, return
    3. val = pre[index], index++
    3. postorder(pre, min, val, index)
    4. postorder(pre, val, max, index)
    5. print val
 
