#include <stdio.h>
#include <stdlib.h>

typedef struct ee *list;
struct ee
{
	int val;
	list before;
	list next;
};

void insert(list *e, list *top, int val)
{
	list temp;
	
	temp = (list)malloc(sizeof(*temp));
	temp->val = val;
	temp->next = (*top)->next;
	temp->before = (*top);
	((*top)->next)->before = temp;
	(*top)->next = temp;
	(*top) = temp;


}


int main()
{
	list a;
	list a_top;


	int i, j;
	int val;
	int n, m;

	FILE * in = fopen("input.txt","r");
	FILE * out  =fopen("output.txt", "w");


	a = (list)malloc(sizeof(*a));

	//fscanf(in, "%d %d", &n, &m);
	a->next = a;
	a->before = a;
	a_top = a;

	while(!feof(in))
	{
		fscanf(in, "%d", &val);
		insert(&a, &a_top, val);
	}

	
	//bwd(&a, &a_top);


	while(1)
	{
		if(a_top == a)
		{
			break;
		}
		fprintf(out,"%d ", a_top->val);
		a_top= a_top->before;
	}

	fclose(in);
	fclose(out);
	free(a);


	return 0;
}