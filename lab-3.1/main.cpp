#include <iostream> 
#include <cmath> 

using namespace std;

void print(int **Arr, int m, int n)
{
	cout << endl << "Elements array: ";
	for(int i = 0; i < n; i++)
	{
		cout << endl;
		for(int j = 0; j < m; j++)
		cout <<  Arr[i][j] << "\t";
	}
	
}

void input(int **Arr, int m, int n)
{
	cout << "Input element array:";
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		cin >> Arr[i][j];
	
}
void temp(int **Arr, int i, int m)
{
	int temp; 
	for(int j = 0; j < m; j++)
	{
		temp = Arr[i +1][j];
		Arr[i + 1][j] = Arr[i][j];
		Arr[i][j] = temp;
	
	}
}
void sort(int **Arr, int m, int n)
{
	int *Arr1 = new int[n];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(Arr[i][j] % 2 != 0 && Arr[i][j] < 0)
					Arr1[i] += Arr[i][j];

		for(int c = 0; c < n; c++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if(Arr1[i] > Arr1[i + 1])
						temp(Arr, i, m);

					
		

}
int main ()
{
	system("color f0");

	int n = 0, m = 0;
	cout << "Input count array[n][m]:";
	cin >> n >> m;
	
	int **Arr = new int* [n];
		for(int i = 0; i < n; i++)
			Arr[i] = new  int[m];

	


	

	input(Arr, m, n);
	print(Arr, m, n);
	sort(Arr, m, n);
	print(Arr, m, n);

	for(int i = 0; i < n; i++)
		delete Arr[i];
	delete Arr;

	system("pause");
	return 0;
}