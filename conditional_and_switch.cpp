#include <iostream>

using namespace std;

bool accept()
{
	cout << "do you want to proceed(y or n)\n";

	char answer;
	cin >> answer;

	if(answer=='y'){
		return true;
	}
	else{
		return false;
	}	
}

bool accept1()
{
	cout << "do you want to proceed (y or n)?\n";
	char answer = 0;
	cin >> answer;
	switch(answer){
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		cout << "i'll take that for a no.\n";
		return false;
	}	
}

bool accept2()
{
	int tries = 1;
	while(tries<4){
		cout <<"Do you want to proceed (y or n)?\n";
		char answer = 0;
		cin >> answer;
			
		switch(answer){
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			cout << "Sorry, i'don't undertand that\n";
			tries++;
		}
	}	

	cout << "i'll take that for a no.\n";
 	return false;

}

int main()
{
	accept();
	accept1();
	accept2();

	return 0;
}



