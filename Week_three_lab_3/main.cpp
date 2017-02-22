#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <stdio.h>

using namespace std;

int main()
{
	char ch;
	int integer;
	short intSmall;
	float fl;
	
	string str;
	ofstream fout;
	ifstream fin;

	/*Вивід прирізвища та варіанту на екран */
	cout << "Sapozhnyk Dmytro Olegovich, P-31, V-8." << endl << endl;

	fout.open("Text.txt", ios_base::out | ios_base::trunc);
	/*Зчитуємо значення у змінні відповідно до таблиці */
	cout << "Char: ";
	cin >> ch;
	fout << ch << endl;
	cout << "Int: ";
	cin >> integer;
	fout << integer << endl;
	
	cout << "Short: ";
	cin >> intSmall;
	fout << intSmall << endl;
	cout << "Float: ";
	cin >> fl;
	fout << fl << endl;

	cout << "String: ";
	cin >> str;
	fout << str << endl;
	fout << endl << "----------------------------------" << endl << endl;
	fout.close();

	fout.open("Text.txt", ios_base::out | ios_base::app);
	/* Âèâåñòè âñ³ ç÷èòàí³ äàí³ ó òåêñòîâèé ðÿäîê çà äîïîìîãîþ ôóíêö³¿ sprintf */
	cout << endl << "\t Output" << endl;
	char buf[50];
	sprintf_s(buf, "Char: %c", ch);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Int: %d", integer);
	printf_s("%s\n", buf);
	fout << buf << endl;

	sprintf_s(buf, "Short: %hd", intSmall);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Float: %.3f", fl);
	printf_s("%s\n", buf);
	fout << buf << endl;
	
	cout << "String: " << str << endl;
	fout << "String: " << str << endl;
	fout.close();

	/* Числа в різни форматах */
	cout << endl << "\t Different number system" << endl;
	sprintf_s(buf, "Char(16): %x", ch);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Int(8): %o", integer);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Int(16): %x", integer);
	printf_s("%s\n", buf);
	
	
	sprintf_s(buf, "Short(8): %ho", intSmall);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Short(16): %hx", intSmall);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Float(exp): %.3e", fl);
	printf_s("%s\n", buf);
	

	/*ЗАвдання з попередньої лаби */
	cout << endl << "\t Item 6" << endl;
	int y = 0, sum = 0;
	for (int x(-20); x <= 20; x++)
	{
		y = pow(x, 5) - 5*pow(x, 3) + x + 37;
		cout << "\t" << y << endl;
		if ((y % 13) == 5)
			sum += y;
	}

	cout << "Sum = " << sum << endl;

	/* зчитуємо зз файлу в змінні */
	string strFile;
	fin.open("Text.txt", ios_base::in);
	int i = 0;
	while (fin.good())
	{
		fin.getline(buf, 50);
		if (i++ > 9)
		{
			strFile += buf;
			strFile += '\n';
		}
	}
	fin.close();
	cout << endl << "\t Read file" << endl << strFile << endl;

	
	fin.open("Text.txt", ios_base::in);
	char _ch;
	fin.get(_ch);
	int _integer;
	fin >> _integer;
	
	short _intSmall;
	fin >> _intSmall;

	float _fl;
	fin >> _fl;
	
	string _str;
	fin >> _str;
	fin.close();

	cout << " New var"
		<< "Char: " << _ch << endl
		<< "Int: " << _integer << endl
		
		<< "Short: " << _intSmall << endl
		<< "Float: " << _fl << endl
		<< "String: " << _str << endl;

	system("pause");
	return 0;
}