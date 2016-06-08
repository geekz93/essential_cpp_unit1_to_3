#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
using namespace std;
//exercise3.3
//定义一个 map :索引为家庭的姓，键值为家庭的所有childern姓名 

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


int main()
{
	map< string, vector<string> > familybook;
	vector<string> familys;
	string surname;
	string sChildName;
	int num=2;
	while(num--)
	{
		
		cout << "输入姓氏: ";
		cin >> surname;
		//cout << endl;
		cout << "输入孩子姓名: "; 
		while(cin >> sChildName)
		{
			familys.push_back(sChildName);
			if('\n' == cin.peek())
			    break;
		}
		familybook[surname] = familys;
		familys.clear();
	}
//	disp(familys.begin(), familys.end());
	map< string, vector<string> >::iterator mit=familybook.begin();
	vector<string>::iterator vit;
	for(; mit != familybook.end(); ++mit)
	{
		vit = (mit->second).begin();
		cout << mit->first << ": ";	
		for(; vit != (mit->second).end(); ++vit)
			cout << *vit << " ";
		cout << endl;
	}
	
	while(true)
	{
	    cout << "输入姓氏查询：";
        cin >> surname;
        mit = familybook.find(surname);
        if(mit == familybook.end())
       	{
			cout<< "未找到"<<endl;
			continue;   
 		}
        vit = mit->second.begin();
        for(; vit != (mit->second).end(); ++vit)
			cout << *vit << " ";
		cout << endl;
	}
	return 0;
}
