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
	long ln;
	string str;
	ofstream fout;
	ifstream fin;

	/* Âèâåñòè íà åêðàí Ï²Á, íàçâó ãðóïè òà íîìåð âàð³àíòó */
	cout << "Sapozhnyk Dmytro Olegovich, P-31, V-8." << endl << endl;

	fout.open("Text.txt", ios_base::out | ios_base::trunc);
	/* Ç÷èòàòè çíà÷åííÿ ç êëàâ³àòóðè âêàçàí³ ó âàð³àíòàõ äî ðîáîòè */
	cout << "Char: ";
	cin >> ch;
	fout << ch << endl;
	cout << "Int: ";
	cin >> integer;
	fout << integer << endl;
	cout << "Unsigned int: ";
	cin >> intPluss;
	fout << intPluss << endl;
	cout << "Short: ";
	cin >> intSmall;
	fout << intSmall << endl;
	cout << "Float: ";
	cin >> fl;
	fout << fl << endl;
	cout << "Long: ";
	cin >> ln;
	fout << ln << endl;
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
	sprintf_s(buf, "Unsigned int: %u", intPluss);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Short: %hd", intSmall);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Float: %.3f", fl);
	printf_s("%s\n", buf);
	fout << buf << endl;
	sprintf_s(buf, "Long: %ld", ln);
	printf_s("%s\n", buf);
	fout << buf << endl;
	cout << "String: " << str << endl;
	fout << "String: " << str << endl;
	fout.close();

	/* Âèâåñòè ñôîðìîâàíèé ðÿäîê íà åêðàí îáîâ’ÿçêîâî âèêîðèñòîâóþ÷è âîñüìåðè÷íå òà ø³ñíàäöÿòåðè÷íå ïðåäñòàâëåííÿ
	äëÿ ö³ëèõ ÷èñåë òà ð³çí³ ôîðìàòè äëÿ ä³éñíèõ çíà÷åíü */
	cout << endl << "\t Different number system" << endl;
	sprintf_s(buf, "Char(16): %x", ch);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Int(8): %o", integer);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Int(16): %x", integer);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Unsigned int(8): %o", intPluss);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Unsigned int(16): %x", intPluss);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Short(8): %ho", intSmall);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Short(16): %hx", intSmall);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Float(exp): %.3e", fl);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Long(8): %lo", ln);
	printf_s("%s\n", buf);
	sprintf_s(buf, "Long(16): %lx", ln);
	printf_s("%s\n", buf);

	/* Âèêîíàòè ïóíêò ¹ 6 ïåðøî¿ ëàáîðàòîðíî¿ ðîáîòè ç âèâåäåííÿì íà åêðàí âñ³õ çíà÷åíü ïîñë³äîâíîñò³ òà ðåçóëüòàòó îá÷èñëåíü */
	cout << endl << "\t Item 6" << endl;
	double y, sum = 0;
	for (int x(-20); x <= 10; x++)
	{
		y = pow(x, 4) - 10.2*pow(x, 3) - pow(x, 2) + 2.1*x + 37.7;
		cout << '\t' << y << endl;
		if (y < 2 * x)
			sum += y;
	}
	cout << "Sum = " << sum << endl;

	/* Çàïèñàòè äî ôàéëó ðÿäîê ñôîðìîâàíèé â ïóíêò³ 4, òà ç÷èòàòè éîãî ç ôàéëó â ³íøèé ðÿäîê */
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
	unsigned int _intPluss;
	fin >> _intPluss;
	short _intSmall;
	fin >> _intSmall;
	float _fl;
	fin >> _fl;
	long _ln;
	fin >> _ln;
	string _str;
	fin >> _str;
	fin.close();

	cout << "\t New var"
		<< "Char: " << _ch << endl
		<< "Int: " << _integer << endl
		<< "Unsigned int: " << _intPluss << endl
		<< "Short: " << _intSmall << endl
		<< "Float: " << _fl << endl
		<< "Long: " << _ln << endl
		<< "String: " << _str << endl;

	system("pause");
	return 0;
}