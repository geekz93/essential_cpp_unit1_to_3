#include<iostream>
#include<vector>
#include<functional>
#include<iterator>
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

//generic
template<typename InputIterator, typename OutputIterator, 
		 typename ElemType, typename Comp>
OutputIterator
filter( InputIterator first, InputIterator last, 
		OutputIterator at, const ElemType &val, Comp pred)
{
	while(( first = find_if(first, last, 
			bind2nd(pred, val))) != last )
	{
		cout << "found value: " << *first << endl;
		*at++ = *first++;
	}
	return at;
}


int main()
{
	const int elemSize = 7;
	int ia[elemSize]={1, 34, 2, 45, 3, 1 ,53};
	vector<int> iv1(ia, ia+7);
	
	//vector<int> iv2(7); //指定大小 
	//filter(iv1.begin(), iv1.end(), iv2.begin(), elemSize, greater<int>() );
	
	vector<int> iv2;//不指定大小，使用back_inserter进行传参 
	//filter(iv1.begin(), iv1.end(), iv2.begin(), elemSize, greater<int>() );
	filter(iv1.begin(), iv1.end(), back_inserter(iv2), elemSize, greater<int>() );
	//filter(iv1.begin(), iv1.end(), inserter(iv2, iv2.end()), elemSize, greater<int>() );
	disp("iv2: ", iv2);
	return 0;
}
