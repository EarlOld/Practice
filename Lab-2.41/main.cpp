#include <iostream> 

#include <string>  

using namespace std;


bool ispunct(char str)
{
	return str == '.' || str == ',' || str == '?' || str == '!' || str == '-' || str == ':' || str == ';';  
}

int main ()
{
	system("color f0");

	int ix  = 0, ctr = 0; 
	char str[1000];

	cout << "Enter string, please!" << endl;
	cin.get(str, 1000, '\n');

	while (str[ix])                             
	{
	if ( ispunct(str[ix]) ) ctr++;            
	ix++;                                     
	}
 
	cout << "The proposal contains " << ctr << " a punctuation character" << std::endl;
	system("pause");
	return 0;
}