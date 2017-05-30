#include <iostream>
#include <string.h>
using namespace std;

class AutoLoan{
	public:
		static bool binarySearchRecursive(int array[], int x,int left, int right){			
			int mid = left + ((right - left)/2);
			if (x == array[mid]){
				return true;
			}	
			else if(x < array[mid]){
				return binarySearchRecursive(array, x, left, mid + 1);
			}
			else {
				return binarySearchRecursive(array, x, mid - 1, right);
			}	
			return false;
		


		}
	
	
		static bool binarySearchIterative(int array[], int x, int left, int right){
			
			while (left <= right){
				int mid = left + ((right - left)/2);
				if (array[mid] == x){
					return true;
				}else if (x < array[mid]){
					right = mid - 1;
					//return binarySearchIterative
				}else {
					left = mid + 1;
				}	
			}
			return false;			
		}
	
			
};

int main(){
	int array1[] = {1,4,6,8,9,12};
	int valuer = 8;
	int left = 0;
	int right = sizeof(array1)/sizeof(array1[0]) - 1;
	AutoLoan call;
	cout << call.binarySearchIterative(array1, valuer, left, right) << endl;
	cout << call.binarySearchRecursive(array1, valuer, left, right) << endl;
	return 0;
}





