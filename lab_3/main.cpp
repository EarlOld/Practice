#include <iostream> 
#include <cmath> 

using namespace std;

void temp(int *Arr, int i)
{
	int temp = Arr[i];
	Arr[i] = Arr[i - 1];
	Arr[i - 1] = temp;
}
void sort(int *Arr, int N)
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			if(Arr[j] < 10 && Arr[j] > -10)
				if(j == 0);
				else
					 temp(Arr, j);
		}

}
void sum(int *Arr, int N, int *Arr1)
{
	int a = 0, b = 0, sum = 0;
	
	for(int i = 0; i < N; i++)
		if(Arr[i] < 0) {a = i; break;}

	for(int i = 0; i < N; i++)
		if(Arr[i] < 0 && i != a) {b = i; break;}

		if(b == 0) { Arr1[0]= 0;}
	else{
	
	for(int i = a + 1; i < b; i++)
		if(a+1 == b) {Arr1[1] = 0; Arr1[0]= 1; break;}
		else
			sum +=Arr[i];
	}
	Arr1[1]= sum;
	
}

void print(int *Arr, int N)
{
	cout << endl << "Elements array: ";
	for(int i = 0; i < N; i++)
		cout <<  Arr[i] << "\t";
	
}

void input(int *Arr, int N)
{
	cout << "Input element array:";
	for(int i = 0; i < N; i++)
		cin >> Arr[i];
	
}
int max(int Arr[], int N)
{
	int i = 0;
	int min = Arr[0], count = 0;
	while ( i != N)
	{
		if(min >  Arr[i])
		{
			min = Arr[i];
			count = i;
		}
		
		i++;
	}
	return count+1;
}
int main ()
{
	system("color f0");

	int N = 5;
	cout << "Input count array:";
	cin >> N;
	
	int *Arr, *Arr1;
	Arr1 = new int[2];
	Arr = new int[N];

	input(Arr, N);

	int n = max(Arr, N);

	cout << "Min number:" << n << endl;
	sum(Arr, N, Arr1);

	if(Arr1[0] == 0) 
		cout << "Error" << endl;
	else 
		cout << "Sum:" << Arr1[1] << endl;

	sort(Arr, N);
	print(Arr, N);
	system("pause");

	delete Arr;
	delete Arr1;
	return 0;
}