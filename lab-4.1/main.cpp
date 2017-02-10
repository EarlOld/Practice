#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct TIMETABLE
{
	string NAZV;	
	int NUMR  ;	
	string DATE;	
	string TIME;
};

void Input(TIMETABLE*& A, const int n)
{
	for (int i(0); i < n; i++)
	{
		cout << "Enter nazu: ";  
		getline(cin, A[i].NAZV);
		cout << "Enter number: ";
		cin >> A[i].NUMR;
		cin.ignore();
		cout << "Enter date of start: ";
		getline(cin, A[i].DATE);
		cout << "Enter time of start: " << endl;
		getline(cin, A[i].TIME);
		cin.ignore();
	}
}

void Output(const TIMETABLE* A, const int n)
{
	cout << setw(10) << "NAZV" << setw(16) << "NUMR" << setw(16) << "DATE" << setw(13) << "TIME" << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(16) << A[i].NAZV << setw(8) << A[i].NUMR << setw(20) << A[i].DATE << setw(20) << A[i].TIME;
		cout << endl;
}

void Sort(TIMETABLE*& A, const int n)
{
	for (int i(0); i < n; i++)
	{
		TIMETABLE temp = A[i];
		int j;
		for (j = i - 1; j >= 0 && A[j].NAME > temp.NAME; j--)
			A[j + 1] = A[j];
		A[j + 1] = temp;
	}
}

int main()
{
	const int N = 1;
	TIMETABLE* TRAIN = new TIMETABLE[N];
	Input(TRAIN, N);
	Sort(ABIT, N);

	cout << endl << endl;

	Output(ABIT, N);

	system("pause");
	return NULL;
}