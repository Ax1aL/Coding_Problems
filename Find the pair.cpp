#include<iostream>

using namespace std;

//Problem:------------------
//Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
//For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17

//Soltuions:----------------
//Becuase we have to add only two numbers the first soltuion would be to make a for-loop through the whole array and
//depending on where we are we substract from the k and search the other number with another for-loop
//ex:i=0 =>10;17-10=7 we search for the 7
//i=1 => 15; 17-15=2 we search for 2.

//We can also sort the array and using divide and conq can search for the other part faster.We can also discard the numbers
//that summed with the lowest number are over k to make the search faster (same thing applies for the other soltuion)


int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);



int main() {
	int arr[] = { 10,15,3,7,20,-4,-3,0,17 };
	int k = 17;
	int size = sizeof(arr) / sizeof(int);
	int limit = size - 1;
	cout << "The array is:";
	for (int i = 0; i < limit; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	quickSort(arr, 0, limit);//we sort it
	
	for (int i = limit; i >=0; --i)
	{
		if (arr[i] +arr[0] <= k) {//We exclude the numbers that can't be k or under
			limit = i;
			break;
		}
	}
	cout << "The specific array is:";
	for (int i = 0; i <= limit; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	int otherPart = 0;
	for (int i = limit; i >= 0; --i) {

		if (arr[i] == k) {
			cout << "Found the number!\n";
			continue;
		}
		otherPart = k - arr[i];
		int currPos = i / 2;
		int left, right;
		left = 0;
		right = i;
		do{//Divide et impera,by each iteration we check if we find the otherPart,if not we are halving the interval
			
			if (otherPart > arr[currPos]) {
				left = currPos;
				currPos = (right + currPos) / 2;
			}
			if (otherPart < arr[currPos]) {
				right = currPos;
				currPos = (left + currPos) / 2;
			}
			if (otherPart == arr[currPos]) {
				cout << "Found a pair:" << otherPart << " " << arr[i]<<"\n";
				break;
			}
		} while (currPos != left && currPos!=right);

	}


	system("pause");
	return 0;
}
//To this solution I would also add a variable named begin so that i can reduce the numbers from the left and make the interval even smaller

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
	
		if (arr[j] < pivot)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		
		}
	}
	
	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
	
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}