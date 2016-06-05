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

vector<int> filter1(const vector<int> &vec, int val, less<int> &lt)
{
	vector<int> nvec;
	vector<int>::const_iterator iter = vec.begin();
	while( (iter = find_if(iter, vec.end(),
		bind2nd(lt, val))) != vec.end() )
	{
		nvec.push_back( *iter );
		++iter;
	}
	return nvec;
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
		cout << "found value: " << first << endl;
		*at++ = *first;
	}
	return at;
}


int main()
{
	int ia[]={1, 34, 2, 45, 3, 1 ,53};
	vector<int> iv1(ia, ia+7);
	vector<int> iv2(7, 2); 
	
	return 0;
}
