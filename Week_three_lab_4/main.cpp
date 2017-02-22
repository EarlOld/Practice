#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void ArrOutput(const int *arr, const int n)
{
	for (int i = 0; i < n; i++)
		printf("\t%5d", arr[i]);
}

void ArrBackCopy(const int* arr1, int* arr2, const int n)
{
	for (int i = n - 1, j = 0; i >= 0 && j < n; i--, j++)
		arr2[j] = arr1[i];
}


int ArrSumMin(const int *arr, const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
			sum += arr[i];
	return sum;
}


int ArrSumDubut(const int *A, const int n)
{
	int sum = 0, j = 0;
	int *B = new int[n];

	for (int i = 0; i < n; i += 2)
	{
		if (i == n - 1) B[j] = A[i];
		else B[j] = A[i] * A[i+1];
		j++;
	}

	for (int i = 0; i < j; i++)
		sum += B[i];


	delete B;

	return sum;
}

int**& ArrCreate(const int n, const int m)
{
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	return arr;
}

void ArrDelete(int **&arr, const int n)
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}

void ArrRecordRand(int **arr, const int n, const int m)
{
	random_device random;
	uniform_int_distribution<int> rd(-10, 10);
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = rd(random);
}

void ArrOutput(int **arr, const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << '\t';
		ArrOutput(arr[i], m);
		cout << endl;
	}
}


void ArrZeroOverDiagonal(int **A, const int n, const int m)
{
	int i, S = 0, flag = 0;
	cout << endl << "Nuber string not null:";
	for (i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < m; j++)

			if (A[i][j] != 0) flag++;
		if (flag == m) cout << "\t" << i + 1 << "\t";
	}
}


void ArrSumCol(int **arr, const int n, const int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (((i + j) % 4) == 0) arr[i][j] = 0;
		
}

int main()
{

	system("color f0");

	const int arr1[] = { -1, 2, 3, -6, 7, -2};
	const int N = 6;
	int arr2[N];

	cout << "Array 2:  ";
	ArrBackCopy(arr1, arr2, N);
	ArrOutput(arr2, N);

	cout << endl << endl;
	cout << "Suma min elem: " << ArrSumMin(arr2, N) << endl;
	cout << "Suma dobutkiv elem: " << ArrSumDubut(arr2, N) << endl;
	

	int n, m;
	cout << "Enter size array [n, m]: ";
	cin >> n >> m;
	int **arr3 = ArrCreate(n, m);

	ArrRecordRand(arr3, n, m);
	cout << endl << "Array Rand:" << endl;
	ArrOutput(arr3, n, m);

	cout << endl << "Array zero over diagonal:" << endl;
	ArrZeroOverDiagonal(arr3, n, m);
	
	ArrSumCol(arr3, n, m);

	cout << endl << "Array null:" << endl;
	ArrOutput(arr3, n, m);

	ArrDelete(arr3, n);
	system("pause");
	return 0;
}