#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<set> 
using namespace std;

int main()
{
	map<string, int> words;
	words["first"] = 10;
	string tword = "adf";
//	cin >> tword;
	words[tword]++;
	map<string, int>::iterator it=words.begin();
	cout << "key" << ' ' << "value" << '\n' << "--------" << endl; 
	for(; it != words.end(); ++it)
	{
		cout << it->first << ' ' 
			 << it->second << endl; 
	}
	
	map<int, int> imap;
	imap[213] = 0;
	cout << imap[213] << endl;	 
	return 0;
}
