#include<bits\stdc++.h>

using namespace std;

/**
	* fun Heapify use to create max heap or min heap
*/

void heapify(int *arr, int number, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	
	if(left < number and arr[left] > arr[largest])
		largest = left;
		
	if(right < number and arr[right] > arr[largest])
		largest = right;
		
	if(largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, number, largest);
	}
}

/**
	* fun use to creat heap sort
*/

void heapSort(int *arr, int number)
{
	// Build Min heap
	for(int i = (number / 2) - 1; i >= 0; i--)
		heapify(arr, number, i);
		
	for(int i = number - 1; i >= 0; i--)
	{
		swap(arr[i], arr[0]);
		
		heapify(arr, i, 0);
	}
}

int main()
{
	int number;
	cin >> number;
	
	int *arr = new int[number];
	
	srand(time(NULL));
	
	for(int i = 0; i < number; i++)
		arr[i] = rand() % 1000;
		
	heapSort(arr, number);
	
	for(int i = 0; i < number; i++)
		cout << arr[i] << " ";
	
	return 0;
}
