#include <string>
#include <iostream>
using namespace std;

template<class T>
class Stack
{
public:
	Stack() :tail(0), head(0), size(0)
	{

	}

	~Stack()
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}

	void push(T val)
	{
		Node* Temp;
		Temp = new Node;
		Temp->elem = val;
		if (tail == 0)
		{
			tail = Temp;
		}
		else
		{
			Temp->next = tail;
			tail = Temp;
		}
		size++;
	}

	T top()
	{
		if (tail == 0)
		{
			cout << endl <<"Stack is empty!"<< endl;
			return 0;
		}
		return tail->elem;
	}

	void clear()
	{
		while (tail != NULL)
		{
			Node* delptr = tail;
			tail = tail->next;
			delete delptr;
		}
		
		cout << endl <<"Stack is empty!"<< endl;
	}
	T pop()
	{
		
		if (tail == 0)
		{  cout << endl <<"Stack is empty!"<< endl;
		return 0; }
		Node* delptr = tail;
		cout << endl << tail->elem << endl;
		tail = tail->next;

		delete delptr;
		
		//return tail->elem;
	}
	void print()
	{
		if (tail == 0)
		{
			cout << endl <<"Stack is empty!"<< endl;
		}
		for (Node* ptr = tail; ptr != 0; ptr = ptr->next)
		{
			std::cout << ptr->elem << ' ';
		}
		std::cout << '\n';
	}
	void getIndex(int q)
	{
		if (q > size)
		{
			cout << endl << "Error!" << endl;
			return;
		}
		if (tail == 0)
		{
			cout << endl <<"Stack is empty!"<< endl;
			return;
		}
		int flag = 0;
		for (Node* ptr = tail; ptr != 0; ptr = ptr->next)
		{
			flag++;
			if(flag == q) cout << "Elem index " << q << " : " << ptr->elem << endl;
		}
		
	}
	void SwichMenu();
	inline void OutputMenu()
	{
		cout << "\t Select an action" << endl
			<< "1 - Clean the stack;" << endl
			<< "2 - Adding an element to the end of the stack;" << endl
			<< "4 - Getting a pointer to the i-th element of the stack;" << endl
			<< "5 - Get stack item ;" << endl
			<< "6 - Print the list;" << endl
			<< "7 - Pop the list;" << endl
			<< "0 - Exit." << endl;
	}

private:
	struct Node
	{
		Node() :elem(0), next(0)
		{
		}
		Node* next;
		T elem;
	};
	Node* head;
	Node* tail;
	int size;
};
template <typename T>
void Stack<T>::SwichMenu()
{
	int action;
	while (true)
	{
		OutputMenu();
		cout << endl << "Select an action: ";
		cin >> action;
		switch (action)
		{
			;
			
		case 1:
			clear();
			break;
		case 2:
			T a;
			cout << "INtput element: ";
			cin >> a;
			push(a);
			break;
		case 4:
			cout << "Enter number element: ";
			int elem;
			cin >> elem;
			if (elem <= 0)
			{
				cerr << "\t Incorrect input" << endl;
				break;
			}
			getIndex(elem);
			break;
		case 5:
			cout << "Element: " << top() << endl;
			
			break;
		case 6:
		{
			print();
			break;
		}
		case 7:
		{
			pop();
			break;
		}
		case 0: return;
		default:
			cerr << "\t Incorrect input" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}
