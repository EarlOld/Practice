#include <iostream>
using namespace std;

int main()
{
   system("color f0");
    int a, b, c; 

    cout << "Enter the numbers(3):";
    cin >> a >> b >> c;

    int min = a;


    
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
     cout << "Min: " << min << endl;
	system("pause");
    return 0;
 }