Project Description

Design and implement an efficient O(V + E) algorithm to find the core of a given tree T, which is undirected, connected and acyclic graph.

Definition: A core of a tree T = (V, E) is the vertex s in V such that for any vertices u and v in V, that is the maximum shortest distance from s to v is less than or equal to the maximum of
the shortest distance from u.

Solution -
To solve this problem, I came up with an algorithm that makes use of Breadth First Search Algorithm. This algorithm first finds the diameter if the tree T, which is the maximum shortest distancepossible between two vertices of tree T. Then depending the nature of the length of the diamter, that is, if diamter is of odd length then the tree T have two core vertices or one core if length is even. The correctness of the algorithm can be halt by looking at the definition of a tree and the core. Since its uses BFS twice(to find out two end points as we are not given the end points), first on any vertex to find one end of the diameter and second on the acquired end of the diamter to find the another end, this algorithm still runs in O(V + E) time complexity. The space complexity required is O(V + E) due to use of BFS.
