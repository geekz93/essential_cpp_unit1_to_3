#include<iostream>
#include<vector>
#include<list>
#include<functional>
using namespace std;
template <typename InputIterator>
void disp(char *comments, InputIterator first, InputIterator last)
{
	cout << comments; 
	for(; first!= last; ++first)
		cout << *first << ' ';
	cout << endl; 
}

//generic
template<typename InputIterator, typename OutputIterator, 
		 typename ElemType, typename Comp>
OutputIterator
filter( InputIterator first, InputIterator last, 
		OutputIterator &at, const ElemType &val, Comp pred)
{
	while(( first = find_if(first, last, 
			bind2nd(pred, val))) != last )
	{
		cout << "found value: " << *first << endl;
		at.push_back(*first++);
	}
	return at;
}

int main()
{
	int ia[]={1, 34, 2, 45, 3, 1 ,53};
	vector<int> iv1(ia, ia+7);
	list<int> ivRes;
	int num = 6;
	filter( iv1.begin(), iv1.end(), 
			ivRes, num, greater<int>() );//greater<type> -> ´óÓÚnum 
	disp("ilr: ", ivRes.begin(), ivRes.end());
	return 0;
}
