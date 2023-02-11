#include "DICEs.h"

using namespace std;

double dice(string string1, string string2)
{
	if (string1.empty() || string2.empty())
		return 0;

	if (string1 == string2)
		return 1;

	size_t strlen1 = string1.size();
	size_t strlen2 = string2.size();

	if (strlen1 < 2 || strlen2 < 2)
		return 0;

	size_t length1 = strlen1 - 1;
	size_t length2 = strlen2 - 1;

	double matches = 0;
	int i = 0;
	int j = 0;

	while (i < length1 && j < length2)
	{
		string a = string1.substr(i, 2);
		string b = string2.substr(j, 2);
		int cmp = a.compare(b);

		if (cmp == 0)
			matches += 2;

		++i;
		++j;
	}

	return matches / (length1 + length2);
}


