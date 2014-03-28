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

void archon(list *a, list *b, list *a_top, list *b_top)
{
	list temp;
	(*a) = (*a)->next;//val값이 null인 a의 헤더 부분과
	(*b) = (*b)->next;//b의 헤더 부분을 제거.
	(*a_top)->next = (*b);

}

int main()
{
	list a;
	list b;
	list a_top, b_top;

	int i, j;
	int val;
	int n, m;

	FILE * in = fopen("input.txt","r");
	FILE * out  =fopen("output.txt", "w");


	a = (list)malloc(sizeof(*a));
	b = (list)malloc(sizeof(*b));

	

	fscanf(in, "%d %d", &n, &m);

	
	b->next = NULL;

	a_top = a;
	b_top = b;

	a->next = NULL;
	for ( i = 0 ; i < n ; i ++ )
	{
		fscanf(in, "%d", &val);
		insert(&a, &a_top, val);
	}

	b->next = NULL;
	for ( i = 0; i < m ; i ++ )
	{
		fscanf(in, "%d", &val);
		insert(&b, &b_top, val);
	}

	archon(&a, &b, &a_top, &b_top);//a와 b를 합침.

	while(1)
	{
		fprintf(out, "%d ", a->val);
		if(a->next == NULL)
		{
			break;
		}
		a = a->next;
	}


	fclose(in);
	fclose(out);
	free(a);
	free(b);


	return 0;
}