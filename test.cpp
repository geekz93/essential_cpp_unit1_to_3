#include<iostream>

#include<iterator>

#include<string>
#include<fstream>

using namespace std;
//exercise3.4
//ʹ�� io_iterator ����һ���������У��������е�������ż���ֱ�д�������ļ��� 

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
	istream_iterator<int> input(cin);
	istream_iterator<int> eos;
	
	ofstream ofile1("odd.txt");
	ofstream ofile2("even.txt");
	ostream_iterator<int> output1(ofile1," ");
	ostream_iterator<int> output2(ofile2, " ");
	
	
	if(!ofile2||!ofile2)
	{cerr<< "open err..";return 0; }
	for(; input!=eos; ++input)
	{
		if( (*input)%2 )//odd
			*output1++ = *input;
		else
			*output2++ = *input;
	}
	
	return 0;
}
