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

void bwd(list *a, list *top)
{
	
	list ptr1, ptr2;
	list temp1, temp2;

	temp1 = NULL;

	while(1)
	{
		ptr1 = (*a)->next;
		ptr2 = (*a)->next->next;

		ptr1 ->next = *a;
		(*a)->next = temp1;

		temp1 = ptr1;

		(*a) = ptr2;

		if((ptr2) == NULL)
		{
			(*a) = ptr1;
			break;
		}
	}

}

int main()
{
	list a;
	list a_top;
	list rev;
	list rev_top;

	int i, j;
	int val;
	int n, m;

	FILE * in = fopen("input.txt","r");
	FILE * out  =fopen("output.txt", "w");


	a = (list)malloc(sizeof(*a));
	rev = (list)malloc(sizeof(*rev));

	//fscanf(in, "%d %d", &n, &m);
	a_top = a;
	a->next = NULL;
	rev->next = NULL;
	rev_top = rev;

	while(!feof(in))
	{
		fscanf(in, "%d", &val);
		insert(&a, &a_top, val);
	}

	a = a->next;
	bwd(&a, &a_top);


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