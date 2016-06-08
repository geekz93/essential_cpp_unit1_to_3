#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
using namespace std;
//exercise3.3
//����һ�� map :����Ϊ��ͥ���գ���ֵΪ��ͥ������childern���� 

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
		
		cout << "��������: ";
		cin >> surname;
		//cout << endl;
		cout << "���뺢������: "; 
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
	    cout << "�������ϲ�ѯ��";
        cin >> surname;
        mit = familybook.find(surname);
        if(mit == familybook.end())
       	{
			cout<< "δ�ҵ�"<<endl;
			continue;   
 		}
        vit = mit->second.begin();
        for(; vit != (mit->second).end(); ++vit)
			cout << *vit << " ";
		cout << endl;
	}
	return 0;
}
