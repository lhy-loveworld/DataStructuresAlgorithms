Linear list:
	Array:
		pointer length maxSize
		length() O(1)
		visit(i) O(1)
		traverse() O(N)
		clear() O(1)
		create(maxSize) O(1)
		search(x) O(1)
		insert(i,x) O(N)
		resize() O(1)
		remove(i) O(N)

	(Linked) List:
		easy to add new element, hard to random access
		Singly linked list
			head(simplify the insertion algorithm) and nodes
			node{
			data (head doesn't have)
			next
			}
			create() head = new node 	O(1)
			clear() delete nodes head->next_pointer = NULL	O(N)
			length()		O(N)
			insert(i,x) 	O(N)
			remove(i)	O(N)
			search(x)	O(N)
			visit(i)	O(N)
			traverse()	O(N)
		Doubly linked list
			head, nodes, tail
			node{
			data (head and tail without)
			next
			prior
			}
			create head = new node; head->next = tail = new node; tail->prior = head
		Circular linked list
			only nodes

	Stack:
		LIFO last in first out
		FILO fist in last out
		bottom
		top
		pop
		push
		empty

		A. recursive function
		B. Expression evaluation and syntax parsing
		C. calculator post-polish notation

	Queue:
		FIFO first in first out
		push()
		size(x)
		pop()
		front()
		empty()
		back()

Tree:
	Degree
		the number of sub trees of a node.
	Degree of tree
		the biggest degree of a tree's nodes
	Height
		the number of edges on the longest path between that node and a leaf.

	Binary tree:
		full binary tree: every node in the tree has either 0 or 2 children.
		perfect binary tree: height k; # of nodes: 2^k-1;
		complete binary tree: a perfect tree whose rightmost leaves (perhaps all) have been removed

		Left child and right child are identical

		Properties:
		1. The max number of nodes at level i is 2^(i-1)
		2. Height k, # of nodes is 2^k-1
		3. For any non-empty binary tree with n0 leaf nodes and n2 nodes of degree 2, n0 = n2 + 1.
		4. For a complete binary tree. Root node i=1; Parent node = [i/2]; Leaf node: 2i > N; Left child: 2i; Right child 2i+1;

		Traversal visit:
		Using pre-order and in-order / in-order and post-order can determine a binary tree.
		1. Pre-order:
			recursively
			stack1: keep left child first, visit before push, than right
			stack2: visit before pop, push right and left
		2. In-order:
			recursively
			stack, keep left child first, visit before pop, than right
			morris reverse
		3. Post-order:
			recursively
			stack, record the previously poped node, visit before pop, push right and left.

		Methods of storing:
		1. Array
			waste space, expensive in growing
			used for binary heaps, or complete binary tree
		2. Nodes and pointers
			data, left child, right child, (parent)
			left-child-right-sibling link (store a non-binary tree in the form of binary tree)

		Application:
		1. Expression tree
		2. Huffman coding

	Priority queue:
		Binary heap:
		  a complete binary tree
		  insert:O(log2(N))
		  	percolate up 
		  	keep comparing and swapping the hole node with its parent from the last leaf node until fitting or to the root node, using the insertted value
		  delete: O(log2(N))
		  	keep comparing and swapping the hole node with its smaller child (for min heap) from root node until fitting or to the leaf node, using the last node (leaf)'s value
		  build heap: O(N)
		  	Two means: recursively or non-recursively
		  	1. Recursively: From the root node, recursively build heap its left subtree and right subtree, and then percolate down the root node
		  	2. Non-recursively: From the last non-leaf node, percolate down each node until to the root node

		D heap
			Every node has D children
			Insert O(logD(N))
			Delete O(DlogD(N))
			fast insertion, low in deletion

		Leftist heap
			Easy to merge
			Null path length: npl(x) = min distance to a descendant with 0 or 1 children; npl(NULL) = -1; npl(leaf) = npl(single-leaf node) = 0;

			1. Minimum heap
			2. npl(left) >= npl(right)
			3. npl(parent) = npl(right) + 1

			Merge();
			If one of these trees is NULL, return the other tree;
			Merge the tree with larger value root and the right subtree of the other tree.
			To keep leftist property, swap left subtree and right subtree if needed;

			Insert():
			Merge the original tree and the new tree with only one node;

			Delete():
			Merge the two subtrees of the original tree

		Skew heap
			a self-adjusting leftist heap
			When merging, always swap left subtree and right subtree except the leaf node

		Binomial heap
			a collection of binomial trees
			binomial
				A binomial tree of order 0 is a single node
				A binomial tree of order k has a root node whose children are roots of binomial trees of orders k−1, k−2, ..., 2, 1, 0 (in this order).
				A binomial tree of order k has 2^k nodes, height k.
				a binomial tree of order n has C{n}{d} nodes at depth d
			Merge():
				merge two binomial trees of the same order with increasing order
				when merge two binomial trees, use the smaller root as the new root, the other one as its subtree
				log(N)

			Insert():
				merge the original heap with a single element heap

			Delete():
				find the tree with the smallest root
				delete this tree from the original heap
				delete the root of this tree to form a new heap
				merge these two heaps

			Store():
				A list of root nodes (using left-child-right-sibling link)

Set
	Search()
	Sort()

	Lookup table:
		a table used for looking up
		static lookup table:
			array or list
		dynamic lookup table:
			tree
		search():
			For unsorted list:
				linear search (to the end of the list)
			For sorted list:
				linear search (no need to the end)
				binary search (log(n))
				interpolation search:
					mid = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));
					used when data is uniformly distributed
					and accessing a data cost a lot more than computing
				blocking search
					first decide which block, than do linear search in the block
			STL search function
				bool binary_search()
				iterator find()
		dynamic lookup table:
			binary search tree:
				left<root<right
				slower than hash

				search() O(logN)
				insert() O(logN)
				delete() O(logN)
					if leaf node: simply remove it from the parent node
					else if has right child:  copy the smallest value of its right subtree to it, delete that value from its right subtree
						 else: copy the largest value of its left subtree to it, delete that value from its left subtree
			AVL tree:
				a self-balancing binary search tree
				balance factor:
					height(left subtree) - height(right subtree)
					height(NULL) = -1
					balance factor = -1 0 1
				insert()
					1. balance hasn't been destroyed, need to modify the balance factor of each node bottom up
						As long as one node whose balance factor hasn't changed shows up, we can stop
					2. balance destroyed, need to restruct the structure of the tree

					find the proper place to insert
					go back to root
					if the balance factor of a node used to be 0, re-calculate the balance factor, continue going back
					if the balance factor was not 0, re-calculate the balance factor, if lose balance adjust the structure of the tree

					adjust the structure:
					LL:
						single-rotation
						let the left child of the original root be the new root, its right child be the left child of the old root node, the old root node be the right child of the new root
					LR:
						double-rotation
						do a RR rotation for the old root's left child, and then do a LL rotation for the old root
					RL: LR's mirror
					RR: LL's mirror
				delete()
					//After adjustment, the height of a tree may not keep the same
					Let d be the eventually deleted node, p is the node being checked
					check(d, p)
						case p = 0: reset p's balance factor, return true;
						case d belongs to p's higher subtree: p = 0; return false;
						case d belongs to p's lower tree(it must belongs to p's lower tree's higher tree:
							let q be the other child of p;
							case q = 0: adjust p; return true;
							case pq = 1: adjust p; return false;
							case pq = -1; adjust p; return false;
					while (!check(d,p)) p = p's parent
					//different case needs different adjustment function

			Red-black tree:
				Each node is either red or black.
				The root is black.
				If a node is red, then both its children are black. (the parent of a red node is always black)
				Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes.

				Insert()
				Set the newly-inserted node to red
				If parent is black return
				else (means grandparent is black)
					adjust color
					If parent's sibling is black
						If newly-inserted node is grandparent's LL or RR
							Set parent to black
							Set grandparent to red
							LLb or RRb grandparent
						else (means LR or RL)
							Set newly-inserted node to black
							Set grandparent to red
							LRb or RLb grandparent
					else (parent's sibling is red)
						Set parent to black
						Set parent's sibling to black
						Set grandparent to red
						adjust up

				Delete()
				If the deleted node only has one child (this child must be red)
					set its child to black
				else(no child)
					If (the deleted node is red)
						simply delete it
					else 
						If the deleted node's sibling is black
							case L0,R0(sibling has 0 red child):
								Set the sibling to red
								If parent node is black: adjust upward
								else
									set parent node to black
									return
							Case L1L,R1R (sibling has only one red child, which is his outside child)
								screen shot
							Case L1R,R1L (sibling has only one red child, which is his insider child)
								screen shot
							case L2,R2
								screen shot
						else
							screen shot
			AA tree:
				a red-black tree whose left child can't be red
				Level:
					height of black nodes in rbt
					red node has the same level as its parent
					black node has 1 level less than his parent node
			STL search table:
				set store unique keys
				map store key-value pairs
	Hash
		hash function
			uniformity
			H(key) = position
		Collision resolution
			Closed hashing:
				Linear probing: searches the table for the closest following free location
				Quadratic probing: H+1, H+2^2, ..., H+k^2
				Double hashing: h(i,k) = ( h_1(k) + i * h_2(k) ) mod |T|.
								h_2 (x) = R - (x mod R) R, R is a prime number
			Seperate chaining:
				seperate chaining with linked lists

	Sort
		Insertion sort:
			taking elements from the list one by one and inserting them in their correct position into a new sorted list

			Simple insertion sort:
			Binary insertion sort:
			Shellsort:
		Selection sort
			Simple selection sort:

Disjoint-set data structure
	equivalence relation
		Reflexive: for all a belongs to R, aRa is true
		Symmetric: aRb is true if and only if bRa is true
		Transitive: aRb and bRc means aRc

		disjoint-set:
			find():
			union():

			store:
				linear list
					equivalent to a tree with only root and leaf nodes, O(1) in find, O(N) in union
				tree(parent representation)
				find() {return the root node}
				union() {merge two trees, set one of them as the child of the other}

			application:
				maze generation
				the nearest ancestor node
Graph
	G=(Vertice,Edge)
	
	undirected graph
		edges without orientation
	
	directed graph
		G=(Vertice,Arrow)
		<A,B> and <B,A> are different

	Weighted graph
		the weight of each edge

	Adjacent
		an edge between 2 vertices means adjacency
	Degree
		# of edges connected to a vertice
	Subgraph

	Path

	Cycle

	Connected graph
		For directed graph, strongly connected graph and weakly connected graph (if connected when regarded as an undirected graph)

	Perfect graph
		for undirected graph with n vertices, n(n-1)/2 edges
		for directed graph, n(n-1) edges

	Spanning tree
		Connects all vertices together without circles
		n vertices and n-1 edges
		Minimum Spanning Tree(MST)

	Store:
		adjacency matrix
			for directed graph
			A[i,j] = 1 means i -> j

			pro: O(1) time to judge the existence of an edge
			con: waste space
		adjacency list
			Each list describes the set of neighbors of a vertex in the graph.
			Vertices list: use an array or a list to store all the vertices
			Edges list: use a vertice to represent an edge, all the edges from one vertice forms its list

			pro: space and time both: O(V+E)
			con: 1. need to use worst O(n) time to determine if there's an edge between i and j
				 2. in undirected graph, one single edge needs to be stored twice, waste space
				 3. In directed graph, hard to find an edge entering some vertice

	Traverse:
		Depth-first search(DFS)
			We use recursion or stack to implement this algorithm

			1. Select a vertice to visit.
			2. Mark it as visited
			3. Select every adjacent vertice of it, mark it and do dfs for it.
			4. If there is still some vertices havn't been visited, select one of it and start from 2
			5. Else, return
			or
			everytime we visit a vertice, we mark it as visited and push all its adjacent vertices in stack

			output
				DFS tree, DFS forest

			implement
				DFS(){
					for v in V
						if v not visited
							dfs(V)
				}
				dfs(v){
					mark v as visited
					for v' in v's adjacent vertices
						if v' not visited
							dfs(v)
				}

			Time
				adjacent list: O(V+E)
				adjacent matrix: O(V^2)

		Breadth-first search(BFS)
			We use a queue to implement it, everytime we visit a vertice, we mark it as visited, pop it and push_back all its adjacent vertices

			1. Select a vertice
			2. Mark it as visited and do bfs
			3. Select its every adjacent vertice to visit, mark as visited
			4. do bfs for every adjacent vertice, return to 3
			5. if there's still not visited, turn to 1.

			output
				BFS tree, BFS forest

			implement
				BFS(){
					for v in v{
						if v not visited push_back(v)
						while !queue.empty() {
							cout<<queue.top()
							mark queue.top() visited
							for v' in queue.top()'s adjacent vertices {
								if v' not visited push_back(v')
							}
							queue.pop();
						}
					}
				}

			Time
				adjacent list: O(V+E)
				adjacent matrix: O(V^2)

		Application:
			The connectivity of undirected graph:
				DFS and BFS
				If connected, result is a tree. else, a forest

		###	Eulerian path:
				Goal is to traverse all the edges only once.

				If there are more than 2 odd-degree vertices or 1 or more zero-degree vertices, we cannot find Eulerian path.
				If there are only two odd-degree vertices, we can begin from one of them and end at the other.
				If all the vertices are even degree numbers, we can start from any node and end with the same one

				Implementation:

					First check if this graph contains any vertices that fail the criterion of Euler nodes. (O(V+E))
					Make a copy of this graph. (time O(V+E) space(O(V+E)))
					Select the start vertice
					For each vertices appear in the Eulerian path, test if it still has edges haven't been deleted
					If so, find this Euler circuit and insert it into the result
					Restore the graph
					Eulerian path:
						Find its first adjacent vertice, and delete this edge, do it recursively until it has no adjacent vertices

					pseudo code:
					```
					EulerianPath()
					{
						For each vertice in verticelist[]
						{
							degree = 0;
							edgenode = verticelist[i]->head;
							while edgenode!=NULL
							{
								degree++
								edgenode = edgenode->next;
							}
							if degree==0||degree%2 cout<<no euler circuit
						}
						backuplist = new node [#vertices];
						For each vertice in verticelist[]
						{
							backuplist[i]->data = verticelist[i]->data
							currentnode = verticelist[i]->head;
							while (currentnode!=NULL)
							{
								currentnode' = new node = currentnode;
								currentnode = currentnode->next;
							}
						}
						resultbegin = EC(verticelist[0],resultend);
						currentnode = resultbegin;
						while currentnode->next!=NULL
						{
							currentnode = currentnode->next;
							if verticelist[currentnode->data]->head!=NULL
							{
								currentnode'=EC(verticelist[currentnode->data],currentend);
								currentend->next = currentnode->next;
								currentnode->next = currentnode'
							}
						}
						restore verticelist[];
						cout<<resultbegin;
						return
					}

					EC(i,&end)
					{
						node* resultbegin = new node (i)
						currentnode = resultbegin
						while verticelist[i]->head!=NULL {
							j = verticelist[i]->head->data;
							currentnode->next = new node (j);
							currentnode = currentnode->next;
							delete edge(i,j);
							delete edge(j,i);
							i = j
						}
						end = currentnode;
						return resultbegin;
					}
					```
					Alternative method:
						First check the degree of each vertice.
						Start from a valid vertice, do DFS, the most important thing is to do DFS in post-order, which means visiting each vertice (track the vertice in result) after doing DFS on all its neighbors.
						DFS: track each edge if it is visited, if it's not, then mark it as visited and do DFS on the other end.
						And we end up with tracking the sequence of vertice reversely

			Hamiltonian cycle:
				traverse each vertice once and only once.

				no sufficient and necessary condition

				need to use backtracking

				complexity O(N!) ?

			Connectivity of directed graph:

				Use DFS to test if a directed graph is strongly connected

				Implementation:
					Choose a vertice and do a DFS starting from it
					Give each vertice a number according to the order of DFS
					Reverse the direction of each edge in the graph and start from the vertice with the largest number do a DFS
					The trees in the DFS forest are the strongly connected components in this graph

			Topological sorting:

				For directed acyclic graph (DAG)

				For each edge from v1 to v2, v1 comes before v2 in the order


				Implementation:

				Method 1. repeatedly pick the vertice with 0 degree and change the degree of other vertices accordingly
						  Time: O(E) + O(V) + O(E) = O(E)
						  Space: O(V)

				Method 2. use a linked list to store the result, doesn't matter use which vertice as the start, using post order DFS (visit the current node after doing DFS), always put the newest vertice at the front of the list
						  Time: O(E) + O(V)
						  Space: O(V)

				TopoSort() {
				  InDegree = CalcInDegree();
				  for (i = 0; i < V; ++i) {
				  	if (InDegree[i] == 0) q.push_back(i)
				  }
				  while (!q.empty()) {
				  	cout << q.front();
				  	currentnode = v[q.front()]->head;
				  	while (currentnode != NULL) {
				  	  --InDegree[currentnode->data];
				  	  if (!InDegree[currentnode->data]) q.push_back(currentnode->data)
				  	  currentnode = currentnode->next;
				  	}
				  	q.pop();
				  }
				}

				CalcInDegree() {
				  vector<int> res(V, 0);
				  for (i = 0; i < V, ++i) {
				  	currentnode = v[i]->head;
				  	if (currentnode != NULL) {
				  	  ++InDegree[currentnode->data];
				  	  currentnode = currentnode->next;
				  	}
				  }
				  return res;
				}

				Complexity:
					Time: O(E) + O(V) + O(E) = O(E)
					Space: O(V)

Minimum Spanning Tree:
	Spanning Tree:
		A subgraph of a undirected connected graph that is a tree that includes all the vertices of a graph, with minimum possible number of edges
		N vertices and N-1 edges

	MST:
		A spanning tree with the minimun total weight
		
		Kruskal's algorithm:
			Use disjoint set and priority queue
			Consider the edge with the smallest weight
			Add it to the result if no circuit will be generated
			loop until the priority queue is empty
			check the disjoint set if there is only one root
				Implementation:
					Build a disjoint set, starting with each vertice as root (an array of -1 with the length of num of vertices) O(V)
					Push every edge into a priority queue O(ElogE)
					For every top of the priority queue, pop and test if it will cause a circle (connect two vertices with the same root)(O(logE+2logV)), if not, add it to the result and union two disjoint set.
					Loop until N-1 edges are added
				Complexity:
				Time:
					generate a disjoint set that stores every vertice O(V)
					generate a priority queue that stores every edge{start, end, weight} O(Elog(E))
					check the disjoint set O(Elog(V))
						E > V, in total O(Elog(E))
				Space:
					O(V+E)

		Prim's algorithm:
			The result is a set called U. When U != V, find the edge connecting U and V - U with the minimum weight. Add its ends to U.
			Loop until U == V
			
			Implement
				Use a bool array to represent whether vertice i belongs to U
				Use an array to represent the minimum distance from U to each vertice
				Use an array to represent the other end of that minimum edge

				prim() {
				  U[0] = 1;
				  vector cost(n, INT_MAX);
				  vector starts(n);
				  current = 0;
				  for (int i = 0; i < n-1; ++i) {
				  	edge = V[current].head;
					while (edge != NULL) {
					  if (U[edge->end] == 0) {
					    if (edge->weight < cost[edge->end]) {
					      cost[edge->end] = edge->weight;
					  	  starts[edge->end] = current;
					  	}
					  } 
					  edge = edge->next;
					}
					min = INT_MAX;
					for (int u = 0; u < n; ++u) {
					  if (cost[u] < min) {
					    min = cost[u];
					    current = u;
					  }
					}
					if (min == INT_MAX) return;
					cout << current << starts[current];
					cost[current] = INT_MAX;
				  }
				}

			Complexity:
				Time:
					O(V*V)
				Space:
					O(V)
				

Shortest path problem:
	Single source shortest path:
		unweighted shortest path:
			same as BFS
			use a vector to store the distance to each vertice
			use a queue to help the BFS
			Complexity: 
				time: O(V+E); space: O(V)

		Weighted shortest path:
			DIJKSTRA algorithm:
				Similar with the Prim's algorithm

				The set of vertices whose shortest path are determined is called S. For each newly joined vertice of S, we check its neighbors belonging to V-S. if their path are shorter than before, we update it. Also we record the vertice with minimum path in V-S (can use a priority queue here to speed up), and add that to S, loop until S = V.

				Use a bool array to record if a vertice is in S
				Use an array to record the length of the shortest path to each vertice
				Use an array to record the previous vertice of each vertice

				Dijkstra() {
				  S[0] = 1;
				  vector path(n, INT_MAX);
				  vector starts(n);
				  current = 0;
				  for (int i = 0; i < n-1; ++i) {
				  	edge = V[current].head;
					while (edge != NULL) {
					  if (S[edge->end] == 0) {
					    if (path(current) + edge->weight < path(edge->end)) {
					      path(edge->end) = path(current) + edge->weight;
					  	  starts(edge->end) = current;
					  	}
					  } 
					  edge = edge->next;
					}
					min = INT_MAX;
					for (int s = 0; s < n; ++s) {
					  if (!S[s] && path[s] < min) {
					    min = path[s];
					    current = s;
					  }
					}
					if (min == INT_MAX) return;
				  }
				}	

				Complexity:
					Time: O(E) + O(V*V) = O(V^2)
					Space: O(V)

		Shortest path with negetive weight:
			Modify the BFS
			Use a queue to store the vertices need to be modified
			Use an array to store each vertice's shortest path length
			Use an array to store each vertice's previous vertice
			
			Everytime pop a vertice, calculate each of its adjacent vertice's path length, if it is shorter than the min, modify it. push it
			loop until the queue is empty

			Complexity:
				Time: Best case O(V) Worst case O(V*E)

		Shortest path for acyclic graph
			Combine the dijkstra's algorithm with topological sorting

			Use an array to store the indegree of each vertice
			Use a queue to store the vertice to be processed
			Use an array to store the path length of each vertice
			Use an array to store the previous vertice of each vertice

			Calculate the indegree of each vertice
			Everytime pop a vertice from the queue, for each of its adjacent vertices, recalculate its path length, if shorter than the current one, modify it, recalculate its indegree, if = 0, push it into the queue
			Loop until queue is empty

			Complexity:
				Time: O(V+E)
				Space: O(V)

	All-pairs shortest paths:
		For each vertice, use Dijkstra's algorithm.
			Complexity:
				Time: O(N^3)
				Space: O(V^2)

		Floyd's algorithm:
			build a V * V matrix A, Aij means the distance from i to j(Adjacent matrix), for each vertice k(loop V times), Aij = min(Aij, Aik + Akj) (loop O(V^2) times)
			