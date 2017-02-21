#include <iostream>
#include <cmath>

#define  ROVNO =
#define PLUS +
#define MINUS -
#define DEFINED 1
#define DILENNJA /
#define OSTACHA %
#define ZSUV_RIGHT >>

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


int MyFunction(int var, ...)
{
	int rez = var;
	va_list ptr;
	__crt_va_start(ptr, var);
	for (; var != '"'; var = __crt_va_arg(ptr, char))
	{
		if (var == '+')
			rez += __crt_va_arg(ptr, int);
		else if (var == '-')
			rez -= __crt_va_arg(ptr, int);
		else if (var == '*')
			rez *= __crt_va_arg(ptr, int);
		else if (var == '/')
			rez /= __crt_va_arg(ptr, int);
		else if (var == '>>')
			rez &= __crt_va_arg(ptr, int);
		else if (var == '%')
			rez %= __crt_va_arg(ptr, int);
	}
	__crt_va_end(ptr);
	return rez;
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
	int c ROVNO (5.5 MINUS 6.1 PLUS 1.8) DILENNJA 5 + 5 OSTACHA 2;
	
	cout << "C:" << c << endl;

	
}
#if DEFINED
	int main(int argc, char** argv)
	{

		system("color f0");
	
		int b = 4;
		cout << endl << "Rezult: " << MyFunction(2, '+', 4,  '"') << endl;

		//max();
	
	/*	cout << "8 ----"<< (8 ZSUV_RIGHT 1) << endl;
		cout << "12 ----"<< (12 ZSUV_RIGHT 2) << endl;
		int a = 0;
		cin >> a;
		cout << "Factorial:" << factorial(a) << endl;*/

	
		system("pause");
		return NULL;
	}
#else
	int main(int argc, char** argv)
	{

		system("color f0");
		int a = 10;
		int b = 4;
	 	myDefine();
		system("pause");
		return NULL;
	}
#endif 