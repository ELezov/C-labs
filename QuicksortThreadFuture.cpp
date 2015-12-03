// Quicksort.cpp: главный файл проекта.



#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <future>

using std::cout;
using std::cin;
using std::future;
using std::async;


bool quickSort( int[], int, int, int,int);
int partition( int[], int, int);
void SWAP(int&,int&);



int main(int argc,char* argv[])
{
    int max;
	int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};

	int i;
	std::cout<<"Unsorted array is:  ";
	for(i = 0; i < 9; ++i)
		std::cout<<a[i]<<" ";

	std::cout<<std::endl;

	max=std::thread::hardware_concurrency();
	int k=1;
//	future<int> ans;
	quickSort(a,0,8,k,max);

	//thr.join();
	//quickSort( a, 0, 8);

	std::cout<<"Sorted array is:  ";
	for(i = 0; i < 9; ++i)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;

    system("pause");
	return 0;
}

bool quickSort( int a[], int l, int r,int h,int max)
{  
	std::cout<<"Quick"<<std::endl;
   int j;

    if( l < r ) 
{
	// divide and conquer
	j = partition( a, l, r);
	future<bool> ans; 
	h *= 2;
	if (h < max)
		ans=async(std::launch::async,quickSort,a, l, j-1,h,max);
	else 
		ans=async(std::launch::deferred,quickSort,a, l, j-1,h,max);

	quickSort( a, j+1, r,h,max);
	ans.wait();
	}
	return 0;
}



int partition( int a[], int l, int r) {
   int pivot, i, j;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
	SWAP(a[i],a[j]);
   }
   SWAP(a[l],a[j]);
   return j;
}

void SWAP(int &a,int &b)
{
	int tmp=b;
	b=a;
	a=tmp;
}