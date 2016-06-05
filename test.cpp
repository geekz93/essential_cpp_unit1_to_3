#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
void disp(char *comments, vector<int> &ivec)
{
	cout << comments; 
	vector<int>::iterator iter = ivec.begin();
	for(; iter!= ivec.end(); ++iter)
		cout << *iter << ' ';
	cout << endl; 
}

int main()
{
	int ia[]={1, 34, 2, 45, 3, 1 ,53};
	vector<int> iv1(ia, ia+7);
	vector<int> iv2(7, 2); 
	//print vector
	disp("iv1: ", iv1);
	disp("iv2: ", iv2);
	vector<int> iv_pus(7);
	//pulse two vector
	transform(iv1.begin(), iv1.end(), iv2.begin(), iv_pus.begin(), plus<int>());
	disp("pus: ", iv_pus);
	//multiplies
	transform(iv1.begin(), iv1.end(), iv2.begin(), iv_pus.begin(), multiplies<int>());
	disp("mul: ", iv_pus);
	return 0;
}
