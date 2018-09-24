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
	node* h1=(node*)malloc(sizeof(node));
	node* h2=(node*)malloc(sizeof(node));
	node* h3=(node*)malloc(sizeof(node));
	node* h4=(node*)malloc(sizeof(node));
	h1->data=1;
	h2->data=2;
	h3->data=3;
	h4->data=4;
	h1->next=h2;
	h2->next=h3;
	h3->next=h4;
	h4->next=h1;
	h4=h4->next;
	printf("%d\n",h4->data);
	return 0;
}