#include<iostream>

using namespace std;

//Problem:------------------
//Given an array of integers, return a new array such that each element at index i of the new array is the product
//of all the numbers in the original array except the one at i.
//For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].
//If our input was[3, 2, 1], the expected output would be[2, 3, 6]

//Soltuions:----------------
//We can pass through the array and get the product of all,
//then in the new array we just divide the product of all by the number at the position needed



int main() {
	int arr[] = { 1,2,3,4,5 };
	int size = sizeof(arr) / sizeof(int);
	long long product = 1;
	for (int i = 0; i < size; ++i)
	{
		product *= arr[i];
	}
	long long* newArr=new long long[size];
	if (!product) { cout << "Impossible"; system("pause"); return 0; }//in case the product is 0,we would divide by 0 at one point
	for (int i = 0; i < size; ++i)
	{
		newArr[i] = product / arr[i];
	}

	for (int i = 0; i < size; ++i)
	{
		cout << newArr[i] << " ";
	}

	system("pause");
	return 0;
}

