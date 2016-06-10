#include<iostream>
#include<iterator>
#include<string>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
//exercise3.4_answer
//使用 io_iterator 输入一个数字序列，将序列中的奇数和偶数分别写到两个文件中 

typedef vector<string> vstring;

//read a file and populating the map
void populate_map( ifstream &nameFile, map< string, vstring > &families )
{
	string textline;
	while( getline(nameFile, textline ) )
	{
		string fam_name;
		vector<string> child;
		string::size_type pos=0,
		prev_pos = 0, text_size = textline.size();
		
		//ok: find each word speparated by a space
		while( (pos=textline.find_first_of( ' ', pos)) != string::npos )
		{
			//figure out end points of the substring
			string::size_type end_pos = pos - prev_pos;
			//if prev_pos not set, this is the family name
			//otherwise, we are reading the children ...
			if( !prev_pos )
				fam_name = textline.substr(prev_pos, end_pos );
			//以空格为分界逐个读取child 
			else child.push_back(textline.substr(prev_pos, end_pos) );
			prev_pos = ++pos;
		}
		// now handle last child
		if( prev_pos < text_size)
		//此时由于没有空格与之匹配，pos = -1（string的最大值） 
//		    child.push_back(textline.substr(prev_pos, pos-prev_pos) );
		    child.push_back(textline.substr(prev_pos) );//作用类似 
		
	if( ! families.count(fam_name) )
			families[ fam_name] = child;
		else cerr << " the family "<< fam_name << "were already in the map:\n";
		
	}
}

void display_map( const map<string, vstring > &families, ostream &os )
{
	map< string, vstring >::const_iterator it = families.begin(), end_it = families.end();
	
	while( it != end_it )
	{
		os << "The " << it->first << " family ";
		if( it->second.empty() )
			os << "has no children \n";
		else
		{
			//print out vector of children
			os << "has " << it->second.size() << " children: ";
			vector<string>::const_iterator 
						iter = it->second.begin(),
						end_iter = it->second.end();
			while( iter!= end_iter )
			{ os << *iter++ << " ";}
			os << endl;				
		}
		++it;
	}
}

void query_map(const string &family, 
               const map< string, vstring > families )
{
	map< string, vstring >::const_iterator it = families.find(family);
	if(it==families.end() )
	{
		cout << "sorry, the "<<family
		     << " is not currently entered.\n";
        return;
	}
	
	cout << "The " << family ;
	if( ! it->second.size() )
		cout << " has no children\n";
	else
	{
        cout << " has " << it->second.size() << " children: ";
        vector<string>::const_iterator
                 iter = it->second.begin(),
                 end_iter = it->second.end();
        while( iter!=end_iter )
        { cout << *iter++ << " ";}
        cout << endl;
	} 
}

int main()
{
    map< string, vstring > families;
    ifstream nameFile("families.txt");
    if( !nameFile )
    {
		cerr << "Unable to find families.txt file. \n";
		return -1;
	}
	
	populate_map( nameFile, families );
	
	display_map( families, cout );	

	return 0;
}
