#include <stdio.h>
#include <stdlib.h>

typedef struct ee *list;
struct ee
{
	int val;
	list next;
};

void insert(list *e, list *top, int val)
{
	list temp;
	
	temp = (list)malloc(sizeof(*temp));
	temp->val = val;
	temp->next = (*top)->next;
	(*top)->next = temp;
	(*top) = temp;


}

void del(list *e, list *top, list *bef)
{

	list temp = (*top);
	(*bef)->next = temp->next;
	(*top) = temp->next;
	free(temp);
}


int main()
{
	list a;
	list a_top;
	list pos;
	list pos_bef;

	int i, j;
	int val;
	int n, m;
	int i_v, i_s;

	FILE * in = fopen("input.txt","r");
	FILE * out  =fopen("output.txt", "w");


	a = (list)malloc(sizeof(*a));


	fscanf(in, "%d", &n);
	a_top = a;
	a->next = NULL;

	
	for ( i = 0 ; i < n ; i ++ )
	{
		fscanf(in, "%d", &val);
		insert(&a, &a_top, val);
	}


	fscanf(in, "%d", &i_v);


	pos_bef = a;
	pos = a->next;
	j = 0;
	
	while(1)
	{
		j++;
		if(j == i_v)
		{
			del(&a, &(pos), &pos_bef);
			break;
		}
		pos_bef = pos;
		pos = pos->next;
	}


	a = a->next;

	while(1)
	{
		fprintf(out,"%d ", a->val);
		if(a->next == NULL)
		{
			break;
		}
		a = a->next;
	}
	fclose(in);
	fclose(out);
	free(a);


	return 0;
}