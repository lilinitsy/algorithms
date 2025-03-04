#ifndef ENCRYPTION_MEDIUM_H
#define ENCRYPTION_MEDIUM_H


/* Encryption (HackerRank Medium) https://www.hackerrank.com/challenges/encryption/problem 
 * An English text needs to be encrypted using the following encryption scheme:
 * First, the spaces are removed from the text. Let L be the length of this text, presumably with spaces removed.
 * Then, the characters are written into a grid, whose rows and columns have the following constraints
 * floor(sqrt(L)) <= row <= column <= ceil(sqrt(L))
 *
 * Example: s = if man was meant to stay on the ground god would have given us roots
 * After removing spaces, the string is 54 chars, and sqrt(L) is between 7 and 8, so
 * it's written into a grid of 7 rows and 8 columns.
 * We should ensure rows * columns >= L
 *
 * Then, the encoded message is obtained by displaying the characters of each column, with a space between the column text.
 **/

#include <bits/stdc++.h>

using namespace std;


string encryption(string s)
{
	// Get bounds
	size_t length = s.length();
	float sqrt_length = sqrt((float) length);

	size_t rows = (int) floor(sqrt_length);
	size_t cols = (int) ceil(sqrt_length);
	

	if(rows * cols < length)
	{
		rows++;
	}

	vector<string> s_vec;

	// Split substrings into each vector
	for(size_t i = 0; i < rows * cols; i += cols)
	{
		size_t chars_to_print = min(i + cols, s.substr(i, i + cols).length());
		s_vec.push_back(s.substr(i, chars_to_print));
	}

	// Perform the encryption: mix together chars of each column. Basically a vector transpose
	vector<string> words;
	for(size_t c = 0; c < cols; c++)
	{
		string encrypted_word;
		for(size_t r = 0; r < rows; r++)
		{
			if(c < s_vec[r].size())
			{
				encrypted_word += s_vec[r][c];
			}
		}

		words.push_back(encrypted_word + " ");
	}

	words[words.size() - 1] = words[words.size() - 1].substr(0, words.size());
	return accumulate(next(words.begin()), words.end(), words[0], [](string a, string b) {return a + b;});
}



#endif
