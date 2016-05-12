// Sparse_Arr.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream> 
#include <string> 
#include "SparseArr.h" 
using namespace std;
int main() {
	SparseArr<double> sa1(2000000); // 1 
	sa1[127649] = 1.1; // 2 
	sa1[38225] = 1.2; // 3 
	sa1[2004056] = 1.3; // 4 
	sa1[1999999] = 1.4; // 5 
	sa1.Show("sa1"); // 6 
		cout << "sa1[38225] = " << sa1[38225] << endl; // 7 
	sa1[38225] = sa1[93]; // 8 
	cout << "After the modification of sa1:\n"; // 9 
	sa1.Show("sa1"); // 10 

	SparseArr<string> sa2(1000);  //11
	sa2[333] = "Nick";                     //12
		sa2[222] = "Peter";                   //13
	sa2[444] = "Ann";                     //14
		sa2.Show("sa2");                     //15
	sa2[222] = sa2[555];               // 16 
	sa2.Show("sa2");   // 17 
	//return 0;
	system("pause");
}