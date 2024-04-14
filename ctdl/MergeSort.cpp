#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

/**
	*	Ham tron va tra ve mang da duoc tron
*/

void Merge(int *&a, int l, int m, int r)
{
	vector<int> vt(a + l, a + m + 1);
	vector<int> vt2(a + m + 1, a + r + 1);
	
	int i = 0, j = 0;
	
	while(i < vt.size() and j < vt2.size())
	{
		if(vt[i] >= vt2[j])
			a[l++] = vt2[j++];
			
		else
			a[l++] = vt[i++];
	}
	
	while(i < vt.size())
		a[l++] = vt[i++];
		
	while(j < vt2.size())
		a[l++] = vt2[j++];
}

/**
	*	Ham sap xep theo thuat toan Merge Sort 
*/

void MergeSort(int *a, int l, int r)
{
	if(l >= r)
		return;
	
	int m = (l + r) / 2;
	MergeSort(a, l, m);
	MergeSort(a, m + 1, r);
	Merge(a, l, m, r);
}

int main()
{
	int number;
	cout << "Nhap so luong mang can sap xep: ";
	cin >> number;
	
	int *a = new int[number];
	
	srand(time(NULL));
	
	for(int i = 0; i < number; i++)
		a[i] = rand() % 1000;
		
	MergeSort(a, 0, number - 1);
	
	for(int i = 0; i < number; i++)
		cout << a[i] << " ";
	
	return 0;	
}
