#include "phi2dec.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int phi2dec(int *number,vector<char>&string, int j)
{
	//decoder;
	vector<char>decod;
	int amountOfzero = 0;
	while (string.at(j) == '0') amountOfzero++, j++;
	if (amountOfzero == 0) {j++, *number=0;
		return j;} 
	unsigned int dec1 = 0;
	unsigned int dec2 = 0;
	for (int change = 0; change < amountOfzero; change++)
	{

		dec1 = dec1 << 1;
		dec1 = dec1 | (string.at(j) - '0');
		j++;
	}
	decod.push_back ('1');
	for (unsigned int i = 0; i < (dec1-1); i++)
	{ 
		decod.push_back(string.at(j));
		j++;
	}
	for (unsigned int gedit = 0; gedit < decod.size(); gedit++)
	{
		dec2 = dec2 << 1;
		dec2 = dec2 | (decod.at(gedit)-'0');
	}
	*number = dec2;
	return j;
}
