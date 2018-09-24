#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node	//created a node structure
{
	int data;
	struct node* next;
}node;
int size(node* head)
{
	int count=0;
	while(head!=NULL)
	{
		head=head->next;
		count++;
	}
	return count;
}
//void list_equal()
//{
//	if()//check various conditions
//}
void print(node* head)
{
	int i=1;
	//head=head->next;
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		do
		{
			printf("value at node %d is %d\n",i,head->data);
			head=head->next;
			i++;
		}while(head!=NULL);
	}
}
void reverse_print(node* head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		reverse_print(head->next);
		printf("%d\n",head->data);
	}
}
node* insert(int i)
{
	node* newh=(node*)malloc(sizeof(node));
	printf("Enter the value at node %d\n",i);
	int x;
	if(scanf("%d",&x))
	{
		newh->data=x;
		newh->next=insert(++i);
	}
	else
	{
		return NULL;
	}
	return newh;
}
int main()
{
	node* h=insert(1);
	print(h);
	printf("size of linked list is %d\n",size(h));
	reverse_print(h);
	//using iteration

	free(h);
	//free(h2);
	return 0;
}
