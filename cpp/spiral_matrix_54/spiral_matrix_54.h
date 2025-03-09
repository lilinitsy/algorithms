#ifndef SPIRAL_MATRIX_54_H
#define SPIRAL_MATRIX_54_H


#include <vector>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

/* Spiral Matrix (54) https://leetcode.com/problems/spiral-matrix/
 *
 * Given a 2D vector input of ints, return the elements in spiral order
 * as a vector.
*/




vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	const int m = matrix.size();
	const int n = matrix[0].size();
	vector<int> order;

	// Initialize the starting locations
	int row_start = 0;
	int col_start = 0;

	// Initial end locations, that change. They are initially m and n
	int row_end = m - 1;
	int col_end = n - 1;

	while(row_start <= row_end && col_start <= col_end)
	{
		// Right: Traverse across columns. At the end,
		// it'll go to the next row to start going down
		for(int i = col_start; i <= col_end; i++)
		{
			order.push_back(matrix[row_start][i]);
		}
		row_start++;
		
		// Down: Traverse across rows. At the end,
		// it'll go to the previous column to start going left
		for(int i = row_start; i <= row_end; i++)
		{
			order.push_back(matrix[i][col_end]);
		}
		col_end--;

		// Left: Traverse across columns, but going backwards.
		// We can choose to only go left if the bounds make sense.
		// After we've gone fully left, we'll want to go UP, so 
		// Decrement the row ending
		if(row_start <= row_end)
		{
			for(int i = col_end; i >= col_start; i--)
			{
				order.push_back(matrix[row_end][i]);
			}
		}
		row_end--;

		// Up: Traverse across rows, but goinb backwards
		// Decrement the column start afterwards.
		if(col_start <= col_end)
		{
			for(int i = row_end; i >= row_start; i--)
			{
				order.push_back(matrix[i][col_start]);
			}
		}
		col_start++;
	}
	
	return order;
}


#endif
