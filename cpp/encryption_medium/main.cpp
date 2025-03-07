#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#include "encryption_medium.h"

int main()
{
	string s = "ifmanwasmeanttostayonthegroundgodwouldhavegivenusroots";
	string output = encryption(s);
	printf("output: %s\n", output.c_str());

	s = "iffactsdontfittotheorychangethefacts";
	output = encryption(s);
	printf("output: %s\n", output.c_str());

	return 0;
}
