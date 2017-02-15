#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Copy(const ifstream& fin, ofstream& fout)
{
	fout << fin.rdbuf() << endl;
}


void StrAndWord(string& str)
{
	int word = 1, nStr = 0;

	for (int i = 1; i < str.length(); i++)
	{
		if (i - 1 == 0 && str[i - 1] != ' ' && str[i] == ' ')
			word++;
		else if ((str[i] == ' ' && str[i - 1] == ' ') || (str[i] == ' ' && str[i + 1] == ',') ||
			(str[i] == ' ' && str[i + 1] == ';') || (str[i] == ' ' && str[i + 1] == ':') || 
			str[i] == ',' || str[i] == ';' || str[i] == ':')
			continue;
		else if (str[i] == ' ')
			word++;

		if (str[i] == '.' || str[i] == '!' || str[i] == '?' || i == str.length() - 1)
		{
			if (str[i - 1] == ' ' || str[i - 1] == '.' || str[i - 1] == '!' || str[i - 1] == '?')
				word--;

			nStr++;
			if (word != 0)
				cout << "String " << nStr << ": " << word << " words" << endl;
			else nStr--;

			if (str[i + 1] != ' ')
				word = 1;
			else word = 0;
		}
	}

	
}
void Print(ifstream& fin, ofstream& fout)
{
	char temp;
	string str;
	bool check = false;
	fout << "--------------------------------------------------" << endl;
	while (fin.good())
	{
		temp = fin.get();
		
		if ( temp == '\n')
			temp = ' ';
		else str += temp;     
	}

	cout << str;
	StrAndWord(str);
	fout << endl;



}

int StringOddWords(ifstream& fin, ofstream& fout)
{
	char temp;
	int word = 0;
	int str = 0;
	while (fin.good())
	{
		temp = fin.get();
		if (temp == ' ' || temp == '.')
			word++;
		if (temp == '.' && (word & 1))
		{
			str++;
			word = 0;
		}
	}
	return str;
}

void WordDelete(ifstream& fin, ofstream& fout)
{
	char temp;
	bool check = true;
	fout << "--------------------------------------------------" << endl;
	while (fin.good())
	{
		temp = fin.get();
		if (temp == '.')
			check = true;
		if (temp != ',' && check)
		{
			cout << temp;
			fout << temp;
		}
		else if (temp == ',')
			check = false;
	}
}

int main()
{
	ifstream fin;
	ofstream fout;

	fout.open("Files\\output.txt", ios_base::out | ios_base::trunc);

	fin.open("Files\\input.txt", ios_base::in);
	Copy(fin, fout);
	fin.close();

	fin.open("Files\\input.txt", ios_base::in);
	Print(fin, fout);
	fin.close();

	

	cout << endl;

	fout.close();
	system("pause");
	return NULL;
}