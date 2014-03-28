#include <stdio.h>
#include <stdlib.h>

typedef struct ee *list;
struct ee
{
	int val;
	list next;
};

void insert(list *e, list *top, int val, int *cnt)
{
	list temp;
	
	temp = (list)malloc(sizeof(*temp));
	temp->val = val;

	temp->next = (*top);
	(*top) = temp;

	(*cnt)++;
}


int main()
{
	list a;
	list a_top;


	int i, j;
	int val;
	int cnt = 0;
	int n, m;

	FILE * in = fopen("input.txt","r");
	FILE * out  =fopen("output.txt", "w");


	a = (list)malloc(sizeof(*a));
	

	//fscanf(in, "%d %d", &n, &m);
	a_top = a;
	a->next = NULL;



	while(!feof(in))
	{
		fscanf(in, "%d", &val);
		insert(&a, &a_top, val, &cnt);
	}

	//a = a->next;
	//bwd(&a, &a_top);

	fprintf(out,"%d ", cnt);


	fclose(in);
	fclose(out);
	free(a);


	return 0;
}