#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<fstream> 
using namespace std;
//iostream iterators
int main()
{
	ifstream ifile("inputFile.txt");
	ofstream ofile("sortFile.txt");
	if( !ifile || !ofile )
	{
		cerr<< "open file err... " << endl;
		return -1; 
	}
		
	istream_iterator<string> is(ifile);
	istream_iterator<string> endfile;
	
	vector<string> str;
	copy(is, endfile, back_inserter(str) );
	
	sort(str.begin(), str.end());
	
	ostream_iterator<string> os(ofile, " ");
	copy(str.begin(), str.end(), os);
	return 0;
}
