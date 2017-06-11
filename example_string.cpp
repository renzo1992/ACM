#include <iostream>

using namespace std;

string name = "Niels Stroustrup";

void print()
{	
	string s = name.substr(6,10);//s = Stroustrup, first parameter is the position 6 and the  second parameter is the length 10
	cout << s << endl;

	string d = name.replace(0,5,"miguel"); // replace positions of 0 to 5 in the string name with string miguel
	cout << d << endl;

	name[12] = toupper(name[7]);//exchange a char of position to another char of position,  of a string , but toupper() change of lower char to upper char 
	cout << name[12] << endl;
	cout << name << endl;	
}

int main()
{
	print();
	return 0;
}



