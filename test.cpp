#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;
//iostream iterators
int main()
{
	istream_iterator<string> inputs(cin);//定义输入向量：与标准数入流绑定 
	istream_iterator<string> endfile;//输入的结束 end_of_file 
	
	vector<string> text;
	copy(inputs, endfile, back_inserter(text));//将输入的数据存入text向量由于不知道输入数据的大小故使用back_inserter 
	
	sort(text.begin(), text.end());//排序 
	
	ostream_iterator<string> outputs(cout, " ");//定义输出向量：与标准输出流绑定 
	copy(text.begin(), text.end(), outputs);//输出 
	//同样可以输出数据 
	/* 
	vector<string>::iterator it = text.begin();
	while( it!=text.end())
	*outputs = *it++;//*outputs++没有区别？ 
	*/
	return 0;
}
