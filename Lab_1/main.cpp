#include <iostream>


using namespace std;


double sq_rec(double a, double b)
{
	
	return 0.5 * a * b;
}

double sq_ger(double a, double b, double c)
{
	double p = (a + b +c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main ()
{
	system("color f0");
	bool flag = true;
	double a = 0, b = 0, c = 0;
	
//------------------------------Squere-----------------------
	while(flag)
	{
		cout << "Please enter tree sides of the triangle" << endl;
		cin >> a >> b >> c;
		if(a + b > c && a + c > b && b + c > a)
		{
			flag = false;
			cout << endl << "Squere of the triangle:" << sq_ger(a, b, c) << endl;
	

			if(sq_ger(a, b, c) == sq_rec(a, b))
				cout << "This triangle is rectangular" << endl;

			if(sq_ger(a, b, c) == sq_rec(b, c))
				cout << "This triangle is rectangular" << endl;

			if(sq_ger(a, b, c) == sq_rec(a, c))
				cout << "This triangle is rectangular" << endl;
		}
		else cout << "Error of imput!!!" << endl << endl;
	}
	system("pause");

	return 0;

}