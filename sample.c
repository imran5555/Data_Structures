#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node	//created a node structure
{
	int data;
	struct node* next;
}node;
int main()
{
	int p[3][5]={{2,4,6,8,10},{3,6,9,12,15},{5,10,15,20,25}};
	printf("%d\n%d\n%d\n%d\n%d\n",*(*p),*(*p+1),*(*(p+1)),*(*(p+1)+1),*(*(p+1)+1)+1);
	return 0;
}