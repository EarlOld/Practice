#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct DATE
{
	int day;
	int month;
	int year;

};

struct TIME
{
	int minute;
	int hour;
};

struct TIMETABLE
{
	string name;	
	int number  ;	
	DATE date;	
	TIME time;
};

void Input(TIMETABLE*& A, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter name: ";  
		getline(cin, A[i].name);
		
		cout << "Enter number: ";
		cin >> A[i].number;
		
		cout << "Enter date of start: " <<  endl;
		cout << "\t"<< "Enter day, month, year:";
		cin >> A[i].date.day >> A[i].date.month >> A[i].date.year;

		cout << "Enter time of start: " <<  endl;
		cout << "\t"<< "Enter hour, minute:";
		cin >> A[i].time.hour >> A[i].time.minute;
		cin.ignore();
		cin.clear();
		cout << "------------------------------------------------------------------" << endl;
	}
}

void Output(const TIMETABLE* A, const int n)
{
	cout << setw(16) << "Name" << setw(10) << "Number" << setw(13) << "DATE" << setw(15) << "TIME" << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(16) << A[i].name << setw(8) << A[i].number << setw(10) << A[i].date.day << "/"<< A[i].date.month << "/"<< A[i].date.year << setw(10) << A[i].time.hour << ":"<< A[i].time.minute ;
		cout << endl;
	}
}

void Output_par(const TIMETABLE* TRAIN, const int N)
{
	string name;
	int flag = 0;
	cout << "Input name:";
	cin >> 	name;
	cout << endl;

	
	for(int i = 0; i < N; i++)
	{
		if(TRAIN[i].name == name) 
		{
			cout << setw(16) << "Name" << setw(10) << "Number" << setw(13) << "DATE" << setw(15) << "TIME" << endl;
			cout << "------------------------------------------------------------------" << endl;
	
			cout << setw(16) << TRAIN[i].name << setw(8) << TRAIN[i].number << setw(10) << TRAIN[i].date.day << "/"<< TRAIN[i].date.month << "/"<< TRAIN[i].date.year << setw(10) << TRAIN[i].time.hour << ":"<< TRAIN[i].time.minute ;
			cout << endl;
		}
	}

	for(int i = 0; i < N; i++)
	{
		if(TRAIN[i].name == name) flag++;
	}

	if (!flag) cout << "Not trains!!" << endl;
	
}

void Sort(TIMETABLE *& A, const int n)
{
	TIMETABLE temp;
	
	for (int i(0); i < n - 1; i++)
	{
		
			if(A[i].date.year > A[i+1].date.year) 
				{
					temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
				}

			if(A[i].date.year == A[i+1].date.year)
				if(A[i].date.month > A[i+1].date.month)
				{
					temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
				}
			if(A[i].date.year == A[i+1].date.year)
				if(A[i].date.month == A[i+1].date.month)
					if(A[i].date.day > A[i+1].date.day)
						{
							temp = A[i];
							A[i] = A[i + 1];
							A[i + 1] = temp;
						}
			if(A[i].date.year == A[i+1].date.year)
				if(A[i].date.month == A[i+1].date.month)
					if(A[i].date.day == A[i+1].date.day)
						if(A[i].time.hour > A[i+1].time.hour)
							{
								temp = A[i];
								A[i] = A[i + 1];
								A[i + 1] = temp;
							}
			if(A[i].date.year == A[i+1].date.year)
				if(A[i].date.month == A[i+1].date.month)
					if(A[i].date.day == A[i+1].date.day)
						if(A[i].time.hour == A[i+1].time.hour)
							if(A[i].time.minute > A[i+1].time.minute)
								{
									temp = A[i];
									A[i] = A[i + 1];
									A[i + 1] = temp;
								}
		
	}
}

int main()
{
	system("color f0");
	const int N = 2;
	TIMETABLE* TRAIN = new TIMETABLE[N];

	Input(TRAIN, N);
	Sort(TRAIN, N);

	Output(TRAIN, N);
	Output_par(TRAIN, N);

	system("pause");
	return 0;
}