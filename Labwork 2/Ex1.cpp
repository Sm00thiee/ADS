#include <iostream>
#include <stdlib.h>
using namespace std;

int charLength(char *x)
{
	int n = 0;
	while (*(x + n - 1) != '\0')
	{
		n++;
	}
	return n;
}
struct car
{
	int passengers;
	char name;
	car *pNext;
};
struct train
{
	int N;
	car *pHead;
};
void init(train *x)
{
	x->N = 0;
	x->pHead = NULL;
}
car *initCar(int p, char n)
{
	car *c = new(car);
	c->passengers = p;
	c->name = n;
	c->pNext = NULL;
	return c;
}
bool isEmpty(train *x)
{
	return(x->N == 0);
}
bool isEmpty(car *n)
{
	return(n->passengers == 0);
}
void add(car *cNew, train *x, car *cOld = NULL)
{
	if (isEmpty(x))
	{
		x->pHead = cNew;
	}
	else
	{
		cNew->pNext = cOld->pNext;
		cOld->pNext = cNew;
	}
	x->N++;
}
int length(train *x)
{
	return x->N;
}
void remove(train *x, char n)
{
	car *c = x->pHead;
	if (c->name == n)
	{
		x->pHead = c->pNext;
		free(c);
		x->N--;
		return;
	}
	car *a = c->pNext;
	for (int i{}; i < length(x); i++)
	{
		if (c->name == n)
		{ 
			a->pNext = c->pNext;
			x->N--;
			free(c);
			break; 
		}
		a = c;
		c = c->pNext;
	}
}
void check(train *x)
{
	car *c = x->pHead, *temp = NULL;
	for (int i{}; i < length(x); i++)
	{
		if (isEmpty(c)) 
		{
			remove(x, c->name);
			c = temp;
		}
		temp = c;
		c = c->pNext;
	}
	cout << "   " <<endl;
	cout << "Your train: "<<endl;
}
void info(train *x)
{

	car *c = x->pHead;
	for (int i{}; i < length(x); i++)
	{
		cout << "Car " << c->name << " has " << c->passengers << " passenger(s) "<< endl;
		c = c->pNext;
	}
}
int main()
{
	int N, pas;
	char name;
	train x;
	car *c, *temp = NULL;
	init(&x);
	cout << "Enter number of cars: " << endl;
	cin >> N;
	for (int i{}; i < N; i++)
	{
		cout << "Enter the number of passengers in car number " << i+1 << endl;
		cin >> pas;
		cout << "Name the car number " << i+1 << " (1 character)" << endl;
		cin >> name;
		c = initCar(pas, name);
		if (i == 0){ add(c, &x); }
		else{ add(c, &x, temp); }
		temp = c;
	}
	cout << "Do you want to add another car? " << endl;
	cout << "1: Yes" <<endl;
	cout <<"2: No"<<endl;
	cin >> N;
	if (N == 1)
	{
		cout << "Enter number passengers for this car: ";
		cin >>pas;
		cout << "Name this car: ";
		cin >> name;
		c = initCar(pas, name);
		add(c, &x, temp);
	}
	cout << "Do you want to remove any car?  " << endl;
	cout << "1: Yes" <<endl;
	cout <<"2: No"<<endl;
	cin >> N;
	if (N == 1)
	{
		cout << "Enter name of car that you want to remove: " << endl;
		cin >> name;
		remove(&x, name);			
	}
	check(&x);
	info(&x);
	return 0;	
}
