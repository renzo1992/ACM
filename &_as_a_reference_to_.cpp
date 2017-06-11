#include <iostream>

using namespace std;


void print()
{
	int v[]={1,2,3,4,5,6,8};
	
	for(auto& x:v){
		cout << x << endl;
		++x;
	}
}



int main()
{
	print();
	return 0;
}



