#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
#include<fstream>
#include<set>
#include<map>
using namespace std;
//exercise3.1
//read a text file, store each word as a key in a map
//the key value is the count of each word
//define a set containing words such as "a, an, or, 
//the, and, but"

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
	
	//vector<string> ReadStr;
	string sExWord[]={"a", "an", "or", "the", "and", "but"};
	set<string> ssExWord(sExWord, sExWord+6);
	set<string>::iterator sit = ssExWord.begin();
/*//display set
	for(; sit!=ssExWord.end(); ++sit)
		cout << *sit << endl;
*/
	map<string, int> WordAcount;
	
	for( ; istr!=eof; ++istr)
	{
		if( ssExWord.count(*istr) )
			continue;
		WordAcount[*istr]++;
	}
	map<string, int>::iterator miter=WordAcount.begin();
for( ; miter!=WordAcount.end(); ++miter)
	{
		cout<< miter->first << " "
			<< miter->second << endl;
	}
	
	return 0;
}
