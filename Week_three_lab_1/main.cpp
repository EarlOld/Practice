#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	system("color f0");
	const int a = 10;
	int b = 4;
	const float Pi = 3.13159;
	const char* ch = "Hello World!!!";
	bool sw = true;
	
	cout << "a = " << a << ",\t b = " << b << endl;
	cout << "Rezult (b+a): " << b + a << endl;					//14
	cout << "Rezult (b-a): " << b - a << endl;					//-6
	cout << "Rezult (b / Pi): " << b / Pi << endl;				//1.27324
	cout << "Rezult (b * Pi): " << b * Pi << endl;				//12.56636
	cout << "Rezult (b % 2): " << b % 2 << endl;				//0
	cout << "Rezult (b << 1): " << (b << 1) << endl;			//8 (bin = 1000)
	cout << "Rezult (b >> 2): " << (b >> 2) << endl;			//1 (bin = 1)
	cout << "Rezult (!((b>a)&&((a>1)||(a<1)))): " << !((b>a)&&((a>1)||(a<1))) << endl;  //1
	cout << "Rezult (b > a): " << ((b > a) ? b : a) << endl;	//10
	cout << "Rezult (b += a): " << (b += a) << endl;			//14
	cout << "Rezult (b -= a): " << (b -= a) << endl;			//4
	cout << "Rezult (b &= a): " << (b &= a) << endl;			//0 (0100 & 1010 = 0) побітове множення
	cout << "Rezult (b |= a): " << (b |= a) << endl;			//10 (0 | 1010 = 1010) побітове додавання
	cout << "Rezult (b ^= a): " << (b ^= a) << endl;			//0 (1010 ^ 1010 = 0) взаємне виключення
	cout << "Rezult (sizeof(b)): " << sizeof(b) << endl;		//4 byte

	int y = 0, sum = 0;
	for (int x(-20); x <= 20; x++)
	{
		y = pow(x, 5) - 5*pow(x, 3) + x + 37;
		if ((y % 13) == 5)
			sum += y;
	}

	cout << endl << "Sum = " << sum << endl;

	system("pause");
	return NULL;
}