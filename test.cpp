#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;


int main()
{
	int ia[]={1, 34, 2, 45, 3, 1 ,53};
	//cout << sizeof(ia)/4 << endl;//elements in array
	vector<int> iv(ia, ia+7);
	//print vector
	for(vector<int>::const_iterator iter = iv.begin(); iter!=iv.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	//sort with ascending
	sort(iv.begin(), iv.end(), greater<int>());//ʹ�ú������� greater ������������ 
	//print vector
	for(vector<int>::const_iterator iter = iv.begin(); iter!=iv.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	//sort with descending
	sort(iv.begin(), iv.end(), less<int>());//less �������� 
	//print vector
	for(vector<int>::const_iterator iter = iv.begin(); iter!=iv.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}
