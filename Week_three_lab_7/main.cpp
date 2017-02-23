#include <iostream>
#include <random>

using namespace std;

struct Item
{
	int data;
	Item *back, *next;
};

void InputData(int &var)
{
	cout << "Enter number: ";
	cin >> var;
}

void OutputDate(const Item *ptr)
{
	cout << ptr->data << endl;
}

inline bool EmptyListInfo(const Item *list)
{
	if (list != NULL)
		return false;
	cout << "\t List empty" << endl;
	return true;
}

Item* CreateItem()
{
	Item *ptr = new Item;
	InputData(ptr->data);
	ptr->back = NULL;
	ptr->next = NULL;
	return ptr;
}

Item* AddToTheStart(Item *first)
{
	Item *p = CreateItem();
	if (first)
		first->back = p;
	p->next = first;
	return p;
}

Item* DeleteElem(Item *ptr)
{
	Item *elem = ptr->next;
	delete ptr;
	return elem;
}

/* Очищення списку */
void DeleteList(Item *&list)
{
	if (EmptyListInfo(list))
		return;
	else cout << "\t List cleaned" << endl;
	while (list != NULL)
		list = DeleteElem(list);
}

/* Додавання елементу в кінець списку */
void AddToTheEnd(Item *ptr)
{
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = CreateItem();
	ptr->next->back = ptr;
}

/* Отримання покажчика на i–й елемент списку */
Item* PtrElementN(Item *list, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (list == NULL)
			return NULL;
		list = list->next;
	}
	return list;
}

/* Отримання номеру елементу списку за покажчиком на елемент */
int NElementPtr(const Item *list, Item *elem)
{
	int i = 0;
	while (list != elem)
	{
		list = list->next;
		i++;
	}
	return i + 1;
}

/* Видалення елементів списку починаючи з елементу a по елемент b */
Item* DeleteFew(Item *st, const int n)
{
	Item *begin = st->back;
	cout << "\t Deleted elements" << endl;
	for (int i = 0; i <= n && st != NULL; i++)
	{
		st = DeleteElem(st);
	}
	if (st)
		st->back = begin;
	if (begin)
		begin->next = st;
	else return st;
}

/* Вставка елемента в список перед визначеним елементом */
void AddElem(Item *elem)
{
	Item *el = CreateItem();
	el->back = elem->back;
	el->next = elem;
	elem->back->next = el;
	elem->back = el;
}

/* Друк вмісту елементів списку на екран */
void OutputList(Item *list)
{
	int i = 1;
	while (list != NULL)
	{
		cout << "Element " << i++ << ": ";
		OutputDate(list);
		list = list->next;
	}
}

Item* FindElem(Item *list, const int elem)
{
	while (list != NULL)
	{
		if (elem == list->data)
			return list;
		else list = list->next;
	}
	return NULL;
}

inline void OutputMenu()
{
	cout << "\t Select an action" << endl
		<< "1 - Clean the list;" << endl
		<< "2 - Adding an element to the end of the list;" << endl
		<< "4 - Getting a pointer to the i-th element of the list;" << endl
		<< "5 - Get list item number for the pointer to an item;" << endl
		<< "7 - Remove items from a list on the b;" << endl
		<< "9 - Insert item in the list before the specified element;" << endl
		<< "10 - Print the list;" << endl
		<< "0 - Exit." << endl;
}

void SwichMenu(Item *&list)
{
	int action;
	while (true)
	{
		OutputMenu();
		cout << endl << "Select an action: ";
		cin >> action;
		switch (action)
		{
			int elem;
			Item *ptr;
		case 1:
			DeleteList(list);
			break;
		case 2:
			if (list == NULL)
				list = CreateItem();
			else AddToTheEnd(list);
			break;
		case 4:
			cout << "Enter number element: ";
			cin >> elem;
			if (elem <= 0)
			{
				cerr << "\t Incorrect input" << endl;
				break;
			}
			cout << "Element " << elem << ": ";
			ptr = PtrElementN(list, elem - 1);
			if (ptr)
				OutputDate(ptr);
			else cout << "don\'t found" << endl;
			break;
		case 5:
			cout << "Enter element: ";
			cin >> elem;
			ptr = FindElem(list, elem);
			if (ptr)
				cout << "This element number: " << NElementPtr(list, ptr) << endl;
			else cout << "\t This element don\'t found" << endl;
			break;
		case 7:
		{
			int a, b;
			cout << "Enter start and finish clearing: ";
			cin >> a >> b;
			if (a <= 0 || b <= 0 || a > b)
			{
				cerr << "\t Incorrect input" << endl;
				break;
			}
			ptr = PtrElementN(list, a - 1);
			if (ptr && PtrElementN(list, b - 1))
				list = DeleteFew(ptr, b - a);
			else cout << "\t This elements don\'t found" << endl;
			break;
		}
		case 9:
			cout << "Enter number element: ";
			cin >> elem;
			if (elem <= 0)
			{
				cerr << "\t Incorrect input" << endl;
				break;
			}
			ptr = PtrElementN(list, elem - 1);
			if (elem == 1)
				list = AddToTheStart(ptr);
			else if (ptr)
				AddElem(ptr);
			else cout << "\t This element don\'t found" << endl;
			break;
		case 10:
			if (!EmptyListInfo(list))
				OutputList(list);
			break;
		case 0: return;
		default:
			cerr << "\t Incorrect input" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

/*//////////////////////////////// Array \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
void ArrRand(int *arr, const int n)
{
	random_device random;
	uniform_int<int> rd(-10, 10);
	for (int i = 0; i < n; i++)
		arr[i] = rd(random);
}

int ArrSum(const int *arr, const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

void ArrOutput(const int *arr, const int n)
{
	for (int i = 0; i < n; i++)
		cout << "  " << arr[i];
}
/*//////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

int main(int argc, char **argv)
{
	system("color f0");
	int n;
	cout << "Enter size array: ";
	cin >> n;
	int *arr = new int[n];
	ArrRand(arr, n);
	cout << "Array: ";
	ArrOutput(arr, n);
	cout << endl << "Sum array: " << ArrSum(arr, n) << endl;
	delete[] arr;
	system("pause");
	system("cls");

	Item *list = NULL;
	SwichMenu(list);

	return 0;
}