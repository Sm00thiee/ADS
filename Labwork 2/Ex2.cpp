#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

struct node
{
	int constant, degree;
	node *pNext;
};
struct polynomial
{
	int size;
	node *pHead;
};
void init(polynomial *x)
{
	x->size = 0;
	x->pHead = NULL;
}
node *initNode(int c, int d)
{
	node *n = new(node);
	n->constant = c;
	n->degree = d;
	n->pNext = NULL;
	return n;
}
bool isEmpty(polynomial *x)
{
	return x->size == 0;
}
bool isEmpty(node *n)
{
	return n->constant == 0;
}
void insert(node *nNew, polynomial *x, node *nOld = NULL)
{
	if (isEmpty(x))
	{
		x->pHead = nNew;
	}
	else
	{
		nNew->pNext = nOld->pNext;
		nOld->pNext = nNew;
	}
	x->size++;
}
void add(polynomial *x, int c, int d)
{
	node *n = x->pHead;
	for (int i = 0; i< x->size -1;i++)
	{
		if (n->degree == d)
		{
			n->constant += c;
			return;
		}
		n = n->pNext;
	}
	node *temp = initNode(c, d);
	insert(temp, x, n);
}
void removeNode(polynomial *x, int d)
{
	node *n = x->pHead;
	if (n->degree == d)
	{
		x->pHead = n->pNext;
		free(n);
		x->size--;
		return;
	}
	node *a = n->pNext;
	for (int i{}; i < x->size; i++)
	{
		if (n->degree == d)
		{
			a->pNext = n->pNext;
			x->size--;
			free(n);
			break;
		}
		a = n;
		n = n->pNext;
	}
}
int calculate(int a, polynomial *x)
{
	node *n = x->pHead;
	int sum{};
	for (int i{}; i < x->size; i++)
	{
		sum += ((n->constant)*pow(a, n->degree));
		n = n->pNext;
	}
	return sum;
}
void display(polynomial *x)
{
	node *n = x->pHead;
	cout << "Your polynomial function is: " << endl;
	for (int i{}; i < x->size - 1; i++)
	{
		cout << n->constant << "*x^" << n->degree << " + ";
		n = n->pNext;
	
	}
	cout << n->constant << "*x^" << n->degree << endl;
}
int main()
{
	int size, c, d;
	polynomial x;
	init(&x);
	cout << "Number of terms in function: " << endl;
	cin >> size;
	for (int i{}; i < size; i++)
	{
		cout << "a*x^b"<<endl;
		cout << "Enter a :"<<endl;
		cout << "      b :"<<endl;
		cin >> c >> d;
		add(&x, c, d);
	}
	cout << "Do you want to add another term? " << endl;
	cout << "1: Yes" <<endl;
	cout <<"2: No"<<endl;
	cin >> c;
	if (c == 1)
	{
		cout << "a*x^b"<<endl;
		cout << "Enter a :"<<endl;
		cout << "      b :"<<endl;
		cin >> c >> d;
		add(&x, c, d);
	}
	display(&x);
	cout << "Do you want to remove any term? " << endl;
	cout << "1: Yes" <<endl;
	cout <<"2: No"<<endl;
	cin >> c;
	if (c == 1)
	{
		cout << "Enter b :" << endl;
		cin >> d;
		removeNode(&x,d);
		display(&x);
	}
	cout << "Enter x : " << endl;
	cin >> c;
	cout << "Result:  " << calculate(c, &x) << endl;
	return 0;
}
