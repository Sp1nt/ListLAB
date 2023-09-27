#include <iostream>
using namespace std;


struct Element
{

	char data;

	Element* Next;
};


class List
{

	Element* Head;

	Element* Tail;

	int Count;

public:

	List();

	~List();


	void Add(char data);


	void Del();

	void DelAll();


	void Print();


	int GetCount();

	void Input(char data, int position);

	void Delete(int position);

	int Find(char pos);
};

List::List()
{

	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{

	DelAll();
}

int List::GetCount()
{

	return Count;
}

void List::Input(char el, int ind)
{

	Element* temp = Head;
	while (ind > 2)
	{
		temp = temp->Next;
		ind--;
	}
	Element* NewElem = temp->Next;
	temp->Next = NewElem;
	NewElem->data = el;

}

void List::Delete(int ind)
{
	Element* rezPos = Head;

	while (ind > 1)
	{
		rezPos = rezPos->Next;
		ind--;
	}
	Element* del = rezPos->Next;
	rezPos->Next = del->Next;
	delete del;
}

int List::Find(char ind)
{
	Element* rezPos = Head;
	int pos = 0;

	while (rezPos->Next != nullptr)
	{
		if (rezPos->data == ind)
			return pos;

		rezPos = rezPos->Next;
		pos++;
	}

	return NULL;
}

void List::Add(char data)
{

	Element* temp = new Element;


	temp->data = data;

	temp->Next = NULL;

	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}

	else {
		Head = Tail = temp;
	}
}

void List::Del()
{

	Element* temp = Head;

	Head = Head->Next;

	delete temp;
}

void List::DelAll()
{

	while (Head != 0)

		Del();
}

void List::Print()
{

	Element* temp = Head;

	while (temp != 0)
	{

		cout << temp->data << " ";

		temp = temp->Next;
	}

	cout << "\n\n";
}


void main()
{

	List lst;


	char s[] = "Hello, World !!!\n";

	cout << s << "\n\n";

	int len = strlen(s);

	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	lst.Print();


	cout << endl;


	//HW 
	//1
	lst.Input('#', 1);
	lst.Print();

	cout << endl;

	//2
	lst.Delete(9);
	lst.Print();

	//3
	int position = lst.Find('r');
	if (position != -1)
		cout << "Element 'r' found at position " << position << endl;
	else
		cout << "Element 'r' not found." << endl;
	cout << endl;

}

