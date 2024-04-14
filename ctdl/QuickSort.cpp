#include<iostream>

using namespace std;

/**
	*	Ham QuickSort voi phan hach Lomuto
*/

int Pattion(int *a, int l, int r)
{
	int value = a[r];
	int j = l - 1;
	
	for(int i = l; i < r; i++)
	{
		if(a[i] <= value)
		{
			++j;
			swap(a[i], a[j]);
		}
	}
	
	++j;
	swap(a[j], a[r]);
	
	return j;
}

void QuickSort(int *a, int l, int r)
{
	if(l >= r)
		return;
		
	int P = Pattion(a, l, r);
	QuickSort(a, l, P - 1);
	QuickSort(a, P + 1, r);
}

/**
	*	Ham QuickSort voi phan hach Hoare
*/

int Pattion2(int *a, int l, int r)
{
	int Pivot = a[l];
	int i = l - 1, j = r + 1;
	
	while(true)
	{
		do
		{
			++i;
		}while(a[i] > Pivot);
		
		do
		{
			--j;
		}while(a[j] < Pivot);
		
		if(i < j)
			swap(a[i], a[j]);
			
		else
			return j;
	}
}

void QuickSort2(int *a, int l, int r)
{
	if(l >= r) 
		return;
		
	int P = Pattion2(a, l, r);
	QuickSort2(a, l, P);
	QuickSort2(a, P + 1, r);
}

int main()
{
	cout << "Nhap so phan tu cua mang: ";
	int number;
	cin >> number;
	
	int *a = new int[number];
	
	for(int i = 0; i < number; i++){
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
	
	cout << "Day la thuat toan Quick Sort theo phan hoach Lomuto\n";
	QuickSort(a, 0, number - 1);
	
	for(int i = 0; i < number; i++)
		cout << a[i] << " ";
		
	cout << "\nDay la thuat toan Quick Sort theo phan hoach Hoare\n";
	QuickSort2(a, 0, number - 1);
	
	for(int i = 0; i < number; i++)
		cout << a[i] << " ";
	
	return 0;
}
