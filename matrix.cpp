//find a matrix of C = A*B OF nxn
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;
vector <int> vector1;
vector <int> vector2;
vector <int> vector3;

int main(){
	int size;
	printf("%s\n","enter  size" );
	cin >> size;
	printf("%s\n","enter valuer matrix A" );
	for(int i=0; i < pow(size,2);i++){
		int valuer;
		cin >> valuer;
		vector1.push_back(valuer);
	}
	printf("%s\n","enter valuer matrix B");
	for(int i=0; i < pow(size,2); i++){
		int valuer;
		cin >> valuer;
		vector2.push_back(valuer);
	}
	for(int t=0; t<size; t++){
		for(int s=0; s< size; s++){
			vector3.insert( vector3.begin() + t*size + s, 0);
			for(int k=0;k < size; k++){
				vector3[t*size+s] = vector3[t*size+s] + vector1[t*size + k]*vector2[k*size+s];
			}
		}	
	}
	for(int i =0;i < size; i++){
		for(int j=0; j< size; j++){
			cout << vector3[i*size + j] << " " ;
		}
		printf("%s\n"," " );
	}
	return 0;
}

