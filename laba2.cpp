#include "phi2.h"
#include "phi2dec.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
unsigned char Arry[256] = {};

int main()
{		
		int sp=0;
		int jd=0;
		vector <char> string;
	for (int letter = 0; letter < 256; letter++)
	{
		Arry[letter] = letter;
	}
	vector<char>word;
	ifstream file;
	file.open("/home/louisa/louisa/l2/lol.txt");
	if (!file)
	{
		cout<<"it's not opened:("<<endl;
	}
	else
	{
		cout<<"it's opened :)"<<endl;
		char letters;
		while (file.get(letters))
		{
			word.push_back(letters);
		}
		word.pop_back();
		cout<<"\n"<<(word.size()*8)<<"\n";
	
	vector<int>num;
	
	for (unsigned int s=0; s < word.size(); s++)
	{
		for (int m = 0; m < 256; m++)
		{
			if (word.at(s) == Arry[m])
			{
				num.push_back(m);
				cout<<num.at(s)<<" ";
				
				int number=num.at(s);
				sp+= phi2(number, string);
				
				char n = Arry[m];
				while (m != 0)
				{
					Arry[m] = Arry[m - 1];
					m--;
				}
				Arry[0] = n;
			}
		}
	}
	cout<<"\n";
	for (unsigned int iterator=0; iterator < string.size(); iterator++) cout << string.at(iterator);
cout<<"\n"<<string.size()<<"\n";
	cout << "\n";
	
	//decod
	for (int letter = 0; letter < 256; letter++)
	{
		Arry[letter] = letter;
	}
	
	int decnumber=0;
	
	
		for (unsigned int z = 0; z < word.size(); z++)
	{
		jd = phi2dec(&decnumber,string,jd);
		cout << decnumber << " ";
		char middle = Arry[decnumber];
		cout<<Arry[decnumber]<<" ";
		cout<<"\n";
		while (decnumber != 0)
			{
			
			Arry[decnumber] = Arry[decnumber - 1];
			decnumber--;
			}
		Arry[0] = middle;
	}
	
	
	file.close ();
	cout<<"\n";
	  return 1;
}
}
