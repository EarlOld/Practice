#include <iostream>
#include <string>

using namespace std;

void erase( char * str)
{
	
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == ' ' || str[i] == '!' || str[i] == '?' || str[i] == ',' || str[i] == '.' || str[i] == ':' || str[i] == ';') continue; 

		for(int j = i; j < strlen(str); j++)
		{
			if(str[j] == ' ' || str[j] == '!' || str[j] == '?' || str[j] == ',' || str[j] == '.' || str[j] == ':' || str[j] == ';') continue; 
			if(str[j + 1] == ' ' || str[j + 1] == '\0' || str[j + 1] == '!' || str[j + 1] == '?' || str[j + 1] == ',' || str[j + 1] == '.' || str[j + 1] == ':' || str[j + 1] == ';')
			{
				if(str[i] == str[j]) 
				{
					for(int l = i; l < strlen(str); l++)
					{
						str[l] = str[l + (j - i) + 1];
					}
				//cout << endl << "TEST string:" << str << endl;
				i = j = 0;
				break;
				}
				else
					{ 
						i = j + 1; 
						break;
					}
				
			}
		}
	}
}

bool is_it(char* str) 
{
	return str[0] == 'q' || str[0] =='Q' || str[0] == 'w' || str[0] == 'W' || str[0] == 'r' || str[0] == 'R' || str[0] == 't' ||  str[0] == 'T' || str[0] == 'p' || str[0] == 'P' || str[0] == 's' || str[0] == 'S' || str[0] == 'd' || str[0] == 'D' || str[0] == 'f' || str[0] == 'F' || str[0] == 'g' || str[0] == 'G' || str[0] == 'h' || str[0] == 'H' || str[0] == 'l' || str[0] == 'L' || str[0] == 'k' || str[0] == 'K' || str[0] == 'z' || str[0] == 'Z' || str[0] == 'x' || str[0] == 'X' || str[0] == 'c' || str[0] == 'C' || str[0] == 'v' || str[0] == 'V' || str[0] == 'b' || str[0] == 'B' || str[0] == 'n' || str[0] == 'N' || str[0] == 'm' || str[0] == 'M'; 
}
 
int NumOfDigits(char* str)
{
    int count = 0;
	cout << endl << "Len string:" << strlen(str)<< endl;
	for(int i = 0; i < strlen(str); i++)
    {
       if(isdigit(str[i]))
            count++;
    }
    return count;
}

int main()
{
	char numbers[999];
	char numbers1[999];

	
	cout << "Input string: ";
	cin.get(numbers, 1000, '\n');

	for( int i = 0; i < 999; i++)
		numbers1[i] = numbers[i];


	
	cout << endl << "New string:" << numbers1 << endl;

	erase(numbers1);
	
	cout << endl << "Erases string:" << numbers1 << endl;
    cout << "Numbers in string: " << NumOfDigits(numbers) << endl;
	cout << "Word: ";
	for(char *p = strtok(numbers, " "); p; p = strtok(0, " ")) 
   
    {
        if(is_it(p))
        {
            cout <<  p << " ";
        }
    }

	//cout << endl << "New string:" << str << endl;*/
	
	system("pause");
    return 0;
}