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

void del(list *top)
{
	list temp;

	temp = *top;

	temp->before->next = temp->next;
	temp->next->before = temp->before;

	free(temp);
}

int main()
{
	list a;
	list a_top;
	list pos;

	int i, j;
	int val;
	int n, m;
	int cnt = 0;
	int lc, vl;

	FILE * in = fopen("input.txt","r");
	FILE * out  =fopen("output.txt", "w");


	a = (list)malloc(sizeof(*a));

	fscanf(in, "%d", &n);
	a->next = a;
	a->before = a;
	a_top = a;



	for ( i = 0 ; i < n ; i ++)
	{
		fscanf(in, "%d", &val);
		insert(&a, &a_top, val);
	}
	fscanf(in, "%d", &lc);
	
	//bwd(&a, &a_top);

	pos = a->next;
	while(1)
	{
		cnt++;
		//fprintf(out,"%d ", a_top->val);
		if(cnt == lc)
		{
			del(&pos);
			//insert(&a, &pos);
			break;
		}
		pos= pos->next;
	}


	pos = a;
	a = a->next;

	while(1)
	{
		if(a == pos)
		{
			break;
		}
		fprintf(out,"%d ", a->val);
		a= a->next;
	}

	fclose(in);
	fclose(out);
	free(a);


	return 0;
}