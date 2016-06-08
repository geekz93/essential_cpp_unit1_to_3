#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
//exercise3.2
//read a text file, store it in a vector
//sort the vector by the length of string

template <typename InputIterator>
void disp( InputIterator first, InputIterator last, char *comments="", int newline=10 )
{
	cout << comments; 
	int line = 0;
	for(; first!=last; ++first)
	{
	    cout << *first << ' ';
	    line++;
		if( newline==line )
		{
			line = 0;
			cout << endl;
		} 
	}
	cout << "\n\n";
}

//…˝–Ú≈≈¡– 
bool SizeDown(string str1, string str2){ return(str1.size() > str2.size()); }
//Ωµ–Ú≈≈¡– 
bool SizeUp(string str1, string str2){ return(str1.size() < str2.size()); }


int main()
{
	ifstream ifile("article.txt");
	if(!ifile)
	{
		cerr<< "open file err..." << endl;
		return -1;
	}
	
	istream_iterator<string> istr(ifile);
	istream_iterator<string> eof;

	vector<string> ReadStr(istr, eof);
//	vector<string> ReadStr(istr.begin(), istr.end());//error
	disp(ReadStr.begin(), ReadStr.end(), "Original:\n");
	sort(ReadStr.begin(), ReadStr.end(), SizeUp);
	disp(ReadStr.begin(), ReadStr.end(), "Sort:\n", 7);
	cout << endl;
	return 0;
}
