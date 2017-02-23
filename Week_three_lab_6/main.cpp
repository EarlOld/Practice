#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

enum days_of_week { Mon, Tue, Wed, Thu, Fri, Sat, Sun };
union MyUnion
{
	char Ch;
	int Int;
	
	short Short;
	float Float;
	
	string* String;
};

struct Date
{
	int day;
	int mount;
	int year;
};

struct Student
{
	string name;
	Date dateBirth;
	string profession;
	string group;
	int numberGradebook;
};

void StudentInput(Student& st)
{
	ofstream fout("Text.txt", ios_base::app);
	cout << "Enter name: ";
	getline(cin, st.name);
	fout << st.name << endl;
	cout << "Enter date of birth (DD MM YYYY): ";
	cin >> st.dateBirth.day >> st.dateBirth.mount >> st.dateBirth.year;
	fout << st.dateBirth.day << ' ' << st.dateBirth.mount << ' ' << st.dateBirth.year << endl;
	cin.ignore();
	cin.clear();
	cout << "Enter profession: ";
	getline(cin, st.profession);
	fout << st.profession << endl;
	cout << "Enter group: ";
	cin >> st.group;
	fout << st.group << endl;
	cout << "Enter number of Gradebook: ";
	cin >> st.numberGradebook;
	fout << st.numberGradebook << endl << endl;
	cin.ignore();
	cin.clear();
	fout.close();
}

void StudentOutput(const Student* st, const int n)
{
	for (int i = 0; i < n; i++, st++)
	{
		cout << "Name: " << st->name << endl;
		cout << "Date of birth: " << st->dateBirth.day << '/' << st->dateBirth.mount << '/' << st->dateBirth.year << endl;
		cout << "Profession: " << st->profession << endl;
		cout << "Group: " << st->group << endl;
		cout << "Number of Gradebook: " << st->numberGradebook << endl;
		cout << endl << "--------------------------------------------------------------" << endl << endl;
	}
}

Student*& StRead(const int N)
{
	Student *st = new Student[N];
	ifstream fin("Text.txt");
	for (int i = 0; i < N; i++)
	{
		getline(fin, st[i].name);
		fin >> st[i].dateBirth.day >> st[i].dateBirth.mount >> st[i].dateBirth.year;
		fin.ignore();
		fin.clear();
		getline(fin, st[i].profession);
		getline(fin, st[i].group);
		fin >> st[i].numberGradebook;
		fin.ignore();
		fin.ignore();
		fin.clear();
	}
	fin.close();
	return st;
}

int main()
{
	system("color f0");
	days_of_week day1, day2;
	day1 = Tue;
	day2 = Thu;
	int diff = day1 - day2;
	cout << "day1: Mon\tday2: Thu" << endl;
	cout << "The difference in days: " << diff << endl;
	if (day1 < day2)
		cout << "\tday1 < day2" << endl;
	else cout << "\tday1 > day2" << endl;
	cout << endl << "-------------------------------------------" << endl << endl;

	const int MAX = 15;
	MyUnion myTypes[MAX];
	random_device random;
	long long llInt = 0;
	unsigned long long ullInt = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (i == 0 || i % 3 == 0)
		{
			uniform_int_distribution<int> rd('a', 'x');
			myTypes[i].Ch = rd(random);
			cout << "Char: " << myTypes[i].Ch << endl;
		}
		else if (i == 1 || ((i - 1) % 3) == 0)
		{
			uniform_int_distribution<int> rd(-2147483647, 2147483647);
			myTypes[i].Int = rd(random);
			cout << "Int: " << myTypes[i].Int << endl;
			llInt += myTypes[i].Int;
		}
		else if (i == 2 || ((i - 2) % 3) == 0)
		{
			uniform_int_distribution<short> rd(0, 255);
			myTypes[i].Short = rd(random);
			cout << "Short: " << myTypes[i].Short << endl;
			ullInt += myTypes[i].Short;
		}
		if (i != 0 && (i + 1) % 3 == 0)
			cout << endl;
	}

	cout << "Sum Int: " << llInt << endl
		<< "Sum Short: " << ullInt << endl << endl;

	/*myTypes->Short = random();
	cout << "Short: " << myTypes->Short << endl;
*/
	myTypes->Float = random();
	cout << "Float: " << myTypes->Float << endl;
	
	myTypes->String = new string;
	*myTypes->String = "My name is Dmytro.";
	cout << "String: " << *myTypes->String << endl;
	delete myTypes->String;

	system("pause");
	system("cls");

	ofstream clear("Text.txt", ios_base::trunc);
	clear.close();

	const int STMAX = 2;
	Student st[STMAX];
	for (int i = 0; i < STMAX; i++)
	{
		StudentInput(st[i]);
		cout << endl << "--------------------------------------------------" << endl;
	}
	system("cls");
	Student *pst = st;
	StudentOutput(pst, STMAX);

	cout << "Read file:" << endl;
	Student *stFile = StRead(STMAX);
	StudentOutput(stFile, STMAX);

	delete[] stFile;
	system("pause");
	return 0;
}