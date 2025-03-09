#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#include "spiral_matrix_54.h"

int main()
{
	vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	vector<int> spiral_order = spiralOrder(matrix);

	for(int elem : spiral_order)
	{
		printf("%d ", elem);
	}
	return 0;
}
