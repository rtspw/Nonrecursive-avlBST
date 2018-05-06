# Non-Recursive AVL Binary Search Tree

A simple project to further understand the properties of a self-balancing binary tree.
Instead of using recursion like most implementations, under the restriction of the nodes not carrying any data about its parents and children several vectors are used, using "pointer-like" indexes to organize the information.

### How data is stored 

| Vector Index        | Data           | Left Index  | Right Index | Parent Index |
| ------------- |:-------------:| -----:| ---: | ---: | 
| 0 | 30 | 2  | 1  | -1 |
| 1 | 35 | 3  | 4  | 0  | 
| 2 | 5  | -1 | -1 | 0  |
| 3 | 32 | -1 | -1 | 1  |
| 4 | 40 | -1 | -1 | 1  |

![bst visual](https://cdn.discordapp.com/attachments/325800539910832128/442593290223616000/unknown.png "BST Visual")

Where the red numbers are the balancing factors stored in each node.

The advantages of this system is that like pointers, the data does not have to be copied when swapped, as we can simply swap the index values in the left, right, and parent vectors.
