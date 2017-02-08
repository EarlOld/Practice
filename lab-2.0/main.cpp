#include <iostream> 
#include <string>  
#include <iomanip>

using namespace std;


bool isfunc(int a, int b, int c)
{
	
	return ((a%2 == b) && !(a || b)) != 0;

}

int main ()
{
	system("color f0");
	
	double  a = 0, b = 0, c = 0,
			h = 0, xStart = 0, xFinish = 0, rez = 0;

	cout << "Enter a, b, c." << endl;

	cin >> a >> b >> c;

	cout << "Enter Start, Finish, Step" << endl;
	cin >> xStart >> xFinish >> h;

	cout << "------------The table--------------------------"<< endl;
	cout << "|" << setw(5) << "x" << "|" << setw(5) << "rez" << "|" << endl;
	cout << "-----------------------------------------" << endl;
	for(double x = xStart; x <= xFinish; x += h)
	{
		if(isfunc(a, b, c))
		{
			if(c < 0 && a != 0){
				
				rez = (-a * x * x);}
			else 
				if(c > 0 && a == 0){
					if(a - x == 0) rez = 0;
					else
						rez = ((a - x)/(c * x));}
				else {rez = (x/c); }
			
		}
		else 
		{
			if(c < 0 && a != 0)
				rez = int(-a * x * x);
			else 
				if(c > 0 && a == 0)
					if(a - x == 0) rez = 0;
					else
					rez = int((a - x)/(c * x));
				else rez = int(x/c);
		
		}
		cout << "|" << setw(5) << x << "|" << setw(5) << rez << "|" << endl;	
	}
	
	system("pause");
	return 0;
}