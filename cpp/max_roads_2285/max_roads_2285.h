#ifndef MAX_ROADS_2285_H
#define MAX_ROADS_2285_H


#include <vector>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

/* Max Total Importance of Roads (2285) https://leetcode.com/problems/maximum-total-importance-of-roads/submissions/1567321304/
 *
 * We are given an integer n denoting the number of citiies in a country, numbered 0 to n - 1.
 * We're also given a 2D integer array roads where roads[i] = [ai, bi], denoting there exists a bidirectional road connecting cities ai and bi.
 * We need to assign each city an int from 1 to n, where each value can only be used once. The importance of a road is then defined
 * as the sum of the two cities if it connects.
 *
 * This function should return the maximum total importance of all roads possible after assinging the values optimally.
 *
 * To maximize how the weights accumulate, it probably makes sense that the nodes with the most connections have the highest values.
 * But, there might also be cases where a node that only connects to a high value node ends up being more important than some others?
 *
 * The solution provided is by far a very inefficient solution, undergoing many O(n) operations, but
 * it's a cleaner reading solution than log(n) tree approaches
 **/



struct nodeinfo
{
	int node_idx = 0;
	int num_connections = 0;
	int weight = 0;
};


long long maximumImportanceFaster(int n, vector<vector<int>> &roads)
{
	vector<int> connections(n, 0);

	for(vector<int> road : roads)
	{
		connections[road[0]]++;
		connections[road[1]]++;
	}

	sort(connections.begin(), connections.end());

	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += connections[i] * (i + 1);
	}

	return sum;
}


long long maximumImportance(int n, vector<vector<int>> &roads)
{
	// First figure out how many connections each node has and sort based on that
	// Store a vector of tuples indexed (node_idx, num_connections, weight)
	// Tuples in cpp suck to work with, so a custom struct of ints is better
	vector<nodeinfo> nodes(n);
	set<int> unique_vals;
	for(int i = 0; i < n; i++)
	{
		nodes[i] = {i, 0, 0};
		unique_vals.insert(i + 1);
	}

	// Get connections for node
	for(vector<int> road : roads)
	{
		int first = road[0];
		int second = road[1];
		nodes[first].num_connections++;
		nodes[second].num_connections++;
	}

	// Sort nodes by num connections
	sort(nodes.begin(), nodes.end(),
			[](const nodeinfo &a, const nodeinfo &b)
			{
				return a.num_connections > b.num_connections;
			});

	// Assign importance decreasingly through the newly sorted nodes
	// Assign weights
	for(size_t i = 0; i < nodes.size(); i++)
	{
		nodes[i].weight = n - i;
	}

	// Remap original node idx to weight
	vector<int> node_weights(n);
	for(int i = 0; i < n; i++)
	{
		node_weights[nodes[i].node_idx] = nodes[i].weight;
	}

	// Figure out sum
	long long sum = 0;
	for(vector<int> road : roads)
	{
		int first = road[0];
		int second = road[1];
		sum += node_weights[first] + node_weights[second];
	}	

	return sum;
}




#endif
