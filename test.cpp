#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;
//iostream iterators
int main()
{
	istream_iterator<string> inputs(cin);//�����������������׼�������� 
	istream_iterator<string> endfile;//����Ľ��� end_of_file 
	
	vector<string> text;
	copy(inputs, endfile, back_inserter(text));//����������ݴ���text�������ڲ�֪���������ݵĴ�С��ʹ��back_inserter 
	
	sort(text.begin(), text.end());//���� 
	
	ostream_iterator<string> outputs(cout, " ");//����������������׼������� 
	copy(text.begin(), text.end(), outputs);//��� 
	//ͬ������������� 
	/* 
	vector<string>::iterator it = text.begin();
	while( it!=text.end())
	*outputs = *it++;//*outputs++û������ 
	*/
	return 0;
}
