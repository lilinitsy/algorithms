#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <cmath>
#include <iostream>
#include <vector>


/*	Segment Tree (simple version)
 *	Given an array a[0 : n - 1], the tree should be able to find the sum of elements between indices l and r,
 *	and also allow values to be changed: a[i] = x. Any query should run in O(log(n)) time
 *
 *	The easier method using an array or std::unordered_set updates in O(1) but runs in O(n) to perform queries.
 *	This times out on competitive programming questions.
 *
 *	Array segments get a divide-and-conquer approach. The sum of elements of an array is stored, and then
 *	store the array in two halves: a[0 : n /2 - 1], and a[n / 2 : n - 1]. Each of those are split in half, etc,
 *	until segment sizes reach leaf node size 1.
 *
 *	The root of the tree is the segment a[0 : n - 1], ie the entire segment, and each non-leaf vertex has
 *	two children. Each node will store the sum of its children.
 *
 *	For instance, given the array a = [1, 3, -2, 8, -7], there are 5 indices 0 to 4, and the tree would be laid
 *	out such as:
 *
 *										a[0:4], sum=3
 *						a[0 : 2], sum=2					a[3:4], sum=1
 *				a[0:1] sum=4	a[2:2]			a[3:3]			a[4:4]
 *		a[0:0]		a[1:1]		sum=-2			sum=8			sum=-7
 *		sum=1		sum=3
 *
 *	For a sum segment tree, each node would store the sum of its children in [l r]. Ie, a[0 : 1] stores the sum
 *	of the its children a[0 : 0] and a[1 : 1].
 *
 *
 *
 * For the LC problem of transmitting segment bytes and doing it quickly, there are two possible ways; using an unordered_set,
 * and using a Tree. Below, I'll implement the tree.
 */



struct SegmentTree
{
	int              n; // max value
	std::vector<int> tree;

	SegmentTree(int size)
	{
		n             = size;
		int height    = static_cast<int>(ceil(log2(n)));
		int tree_size = 2 * (1 << height) - 1;
		tree.resize(tree_size, 0);
	}

	void insert(int left, int right)
	{
		update_range(0, 0, n - 1, left, right);
	}

	int get_total_coverage()
	{
		return tree[0]; // total is stored in root
	}



	void update_range(int node, int start, int end, int left, int right)
	{
		if(start > right || end < left)
		{
			return;
		}

		// leaf node, mark it
		if(start == end)
		{
			tree[node] = 1;
			return;
		}

		int midpoint = (start + end) / 2;
		update_range(2 * node + 1, start, midpoint, left, right);
		update_range(2 * node + 2, midpoint + 1, end, left, right);
		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}
};






























#endif
