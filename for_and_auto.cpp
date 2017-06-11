#include <iostream>

using namespace std;


void print()
{
	int v[]={1,2,3,4,5,6,8};
	
	for(auto x:v) cout << x <<"\n";	
	
	for(auto x:{10,45,56,23,4,5,7,4}) cout << x << "\n";
}



int main()
{
	print();
	return 0;
}



