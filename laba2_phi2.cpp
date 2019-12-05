#include "phi2.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int phi2(int number, vector <char>&string)
{
	int like = number, s = 0;
	if (like == 0) 
	{
		string.push_back ('1'), s++ ;
		return s;
	}
	if (like==1)
	{
	string.push_back('0');
	s++;
	string.push_back('1');
	s++;
	return s;
	}
	else
	{
		int len = 0;
		while (like != 0) like = like >> 1, len++;
		int likeOfnumber=len;
		int lenOflen = 0;
		while (likeOfnumber != 0) likeOfnumber = likeOfnumber >> 1, lenOflen++;
		for (int zero = 0; zero < lenOflen; zero++) 	string.push_back ('0'), s++;
		string.push_back('1'), s++;
		if (lenOflen != 1)
		{
			unsigned int m = 1 << (lenOflen - 2);
			while (m != 0)
			{
				if ((len & m) != 0) string.push_back('1');
				else string.push_back('0');
				s++;
				m = m >> 1;
			}
		}
		unsigned int r = 1 << (len - 2);
		while (r != 0)
		{
			
			if ((number & r) != 0)
			{
				string.push_back('1');
				s++;
			}
			else
			{
				string.push_back('0');
				s++;
			}
			r = r >> 1;
		}
	}
	return s;
}


