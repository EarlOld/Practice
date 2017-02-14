#include <iostream>

using namespace std;

void Input(int **A, int n){
	
	int i,j;
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		 cout << "Vvedite a[" << i << "][" << j << "]: " ; 
		 cin >>A[i][j]; 
	}
		
}

void Output(int **A, int n){
	
	int i,j;
	
	for(i=0;i<n;i++){
	printf("\n");	
	for(j=0;j<n;j++)
	printf("\t%5d",A[i][j]);
	}
}

int Sum(int **A, int n){
	
	int i,S=0;
	
	for(i = 0; i < n; i++)
		for(int j = 0; j < n; j++)

			if(A[i][j] == 0)
				S++;
	return S;
}
int Max(int *A, int n){
	int max = A[0], count = 0;
	for(int i = 0;i < n; i++)
		if(A[i] > max)
		{
			max = A[i];
			count = i;	
		}
	return count;
}

void Sort(int **A, int *B, int n){
	
	for(int i = 0;i < n; i++)
		for(int j = 0; j < n; j++)
			for(int l = 0; l < n; l++)
	
				if(A[j][i] == A[l][i])
					B[i]++;	
}

int main() {
	
	system("color f0");
	int **A,i,j,n, *B;
	
	cout << "Input size matrix(A[n][n]):" << endl;
	cin >> n;
	
	A=(int**)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
	A[i]=(int*)malloc(sizeof(int)*n);
	B = (int*)malloc(sizeof(int) * n);

	Input(A,n);
	cout << endl << "Matrix:" << endl;
	Output(A,n);

	Sort(A, B, n);

	cout << endl << "Count '0':" << Sum(A, n) << endl << "Number:" << Max(B,n) << endl;
	
	for(i=0; i<n; i++)
		free(A[i]);

	free(A);
	free(B);

	system("pause");
	return 0;
}
