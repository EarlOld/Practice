#include <iostream>

using namespace std;
void Input(int **A, int n, int m){
	
	int i,j;
	
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		 cout << "Vvedite a[" << i << "][" << j << "]: " ; 
		cin >>A[i][j]; 
	}
	
	
}

void Output(int **A, int n,int m){
	
	int i,j;
	
	for(i=0;i<n;i++){
	printf("\n");	
	for(j=0;j<m;j++)
	printf("\t%5d",A[i][j]);
	}
}

int Sum(int **A, int n, int j){
	
	int i,S=0;
	
	for(i=0;i<n;i++)
	{
		if(A[i][j]<0 && A[i][j]%2!=0)
		{
			S+=abs(A[i][j]);
		}
	}
	
	return S;
}

void Sort(int **A, int n, int m){
	
	int i,l,j,S1,S2,a;
	
	for(l=0;l<n;l++)
	for(j=1;j<m;j++)
	{
		S1=Sum(A,n,j);
		S2=Sum(A,n,j-1);
		
		for(i=0;i<n;i++)
		if(S1<S2)
		{
			a=A[i][j];
			A[i][j]=A[i][j-1];
			A[i][j-1]=a;
		}
	}
	
	
}

int main() {
	
	system("color f0");
	int **A,i,j,n,m;
	
	cout << "Input size matrix A[n][m]:" << endl;
	cin >> n >> m;
	
	A=(int**)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
	A[i]=(int*)malloc(sizeof(int)*m);
	
	Input(A,n,m);
	cout << endl << "Matrix:" << endl;
	Output(A,n,m);
	

	cout << endl << "Result:" << endl;
	Sort(A,n,m);
	Output(A,n,m);
	
	for(i=0; i<n; i++)
	free(A[i]);
	free(A);

	cout << endl;
	system("pause");
	return 0;
}
