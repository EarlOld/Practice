#include <iostream>
#include <cmath>

#define  ROVNO =
#define PLUS +
#define MINUS -

using namespace std;

void Sum_if()
{
int y = 0, sum = 0;
	for (int x(-10); x <= 20; x++)
	{
		y = 00.1*exp(-0.5*x)+0.05*pow(x,3);
		if (y < 0 || y > 90 )
			sum += y;
	}

	cout << endl << "Sum = " << sum << endl;

}
void max()
{
	double *A;

	int n = 0;

	cout << "Input n, please:"; cin >> n; 

	A = new double[n];

	for(int i = 0; i < n; i++)
	{
		cout << "Input A[" << i << "]:";
		cin >> A[i]; 
	}


	int max = A[0];

	for(int i = 0; i < n; i++)
	{
		if(A[i] > max) max = A[i];	
	}

	cout << endl << "Max:" << max << endl;

	delete A;
}
int factorial(int n)
{
	if(n >= 0)
	{
		if(n == 0) return 1;
		return n*factorial(n-1);	
	}
	else cout << "Error!!!!";
}
int Dobutok(int a, int b)
{
	int y = 0, sum = 0;
	for (int x = -20; x <= 20; x++)
	{
			sum *= x;
	}

	cout << endl << "Sum = " << sum << endl;

	return sum;
}

int Sum(int a, int b)
{
	int y = 0, sum = 0;
	for (int x = -20; x <= 20; x++)
	{
			sum += x;
	}

	cout << endl << "Sum = " << sum << endl;

	return sum;
}

void myDefine()
{
	int c ROVNO 5 MINUS 6 PLUS 1;
	
	cout << "C:" << c << endl;
}
int main(int argc, char** argv)
{
	system("color f0");
	int a = 10;
	int b = 4;


#if ( b > 0)

	[myDefine();]
[#else
	cin >> a;
	cout << "Factorial:" << factorial(a) << endl;]
#endif 
	//cin >> a;
	//cout << "Factorial:" << factorial(a) << endl;
	//myDefine();
	//max();

	system("pause");
	return NULL;
}