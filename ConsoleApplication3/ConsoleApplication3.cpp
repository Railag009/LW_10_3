#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Dlist
{

	int info;
	Dlist* next, * prev;

};


int main()
{

	Dlist* head, * p, * r;
	int x, k, y;
	int max, i, a, b;
	float sr;
	head = new Dlist;
	cin >> x;
	head->info = x;
	head->next = NULL;
	head->prev = NULL;
	p = head;

	a = 0;
	k = 1;

	cin >> x;
	while (x)
	{
		r = new Dlist;
		r->info = x;
		r->next = NULL;
		r->prev = p;
		p->next = r;
		p = r;
		cin >> x;
		k++;

	}

	p = head;
	max = p->info;

	while (p != NULL)
	{

		if (max < p->info) max = p->info;
		p = p->next;

	}
		
	if (k % 2 == 0)
	{
		p = head->next;

		while (p != NULL)
		{

			if (p->prev->info % 2 == 0)
			{

				r = p;
				p->prev->next = r->next;
				p->next->prev = p->prev;
				p = p->next;
				delete r;
				p = p->next;

			}
			else
			{
				p = p->next;
			}

		}

	}
	else
	{
		p = head;

		while (p->next != NULL)
		{

			if (p->info == p->next->info)
			{

				r = new Dlist;
				r->info = pow(max, 2);
				r->next = p->next;
				r->prev = p;
				p->next = r;
				p = r;

			}

			p = p->next;

		}

	}
	
	p = head;

	while (p != NULL)
	{

		cout << p->info << setw(3);
		p = p->next;
	}

}
