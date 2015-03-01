#include <iostream>

using namespace std;

struct list {
	list(int value = 0) : next(NULL), val(value) {}

	struct list *next;
	int val;
};

void rm_repeat(struct list *list_head)
{
	struct list *cur, *p, *tmp;

	for (cur = list_head; cur; cur = cur->next) {
		p = cur;
		while (p && p->next) {
			if (p->next->val != cur->val) {
				p = p->next;
				continue;
			}
			tmp = p->next;
			p->next = tmp->next;
			delete tmp;
		}
	}
}

void list_destroy(struct list *list_head)
{
	struct list *cur, *q;

	for (cur = list_head; cur; cur = q) {
		q = cur->next;
		delete cur;
	}
}

int main()
{
	struct list list_head, *x;
	int val;
	
	x = &list_head;
	while (cin >> val) {
		x->next = new list(val);
		x = x->next;
	}
	rm_repeat(&list_head);
	x = list_head.next;
	while (x) {
		cout << x->val << ' ';
		x = x->next;
	}
	cout << '\n';
	list_destroy(list_head.next);
	return 0;
}
