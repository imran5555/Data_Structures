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
/*void list_equal()
{
	if()//check various conditions
}*/
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
void delete_nth_first_last_node(node** head,int n)
{
	if((*head)==NULL)
	{
		printf("Empty list!\n");
		return;
	}
	
	if(size((*head))==1)
	{
		if(n==1)
		{
			node* temp=(*head)->next;
			(*head)->next=NULL;
			(*head)=temp;
		}
		else
		{
			printf("Wrong input of n\n");
		}
	}
	else if(size((*head))==n)
	{
		node* temp=(*head)->next;
		(*head)->next=NULL;
		(*head)=temp;
		//delete last node
		int count=1;
		node* h=(*head);
		while(count!=n-2)
		{
			(*head)=(*head)->next;
			count++;
		}
		//printf("%d\n",(*head)->data);
		temp=(*head)->next;
		(*head)->next=temp->next;
		temp->next=NULL;
	}
	else
	{
		if(n>size((*head)) || n==0)
			printf("Wrong input of n\n");
		else
		{
			int s=size(*head);
			node* temp=(*head)->next;
			(*head)->next=NULL;
			(*head)=temp;
			//nth
			//last
			int count=1;
			node* h=(*head);
			while(count!=n-2)
			{
				(*head)=(*head)->next;
				count++;
			}
				printf("%d\n",(*head)->data);
			temp=(*head)->next;
			(*head)->next=temp->next;
			temp->next=NULL;
			//(*head)=h;
			if(s-n!=1)//error inside this
			{
				(*head)=(*head)->next;
				while(count!=s-1)
				{
					(*head)=(*head)->next;
					count++;
				}	
			}
				printf("%d\n",(*head)->data);
			(*head)->next=NULL;
			(*head)=h;
		}
	}
	
}
void ordered(node* head)
{
	node* ptr=head->next;
	int count=1,eq=1;
	// if head is NULL
	if(head==NULL)
	{
		printf("List is empty!\n");
	}
	else if(head->next==NULL)
	{
		printf("List is ordered\n");
	}
	else
	{
		while(head->next!=NULL)
		{
			if(head->data>ptr->data)
				count--;
			else if(head->data<ptr->data)
				count++;
			else
				eq++;
		}
		if(eq==size(head) || count==size(head) || count==-size(head) || count+eq==size(head) || eq-count==size(head))
			printf("List is ordered\n");
		else
			printf("List is not ordered\n");
	}
}
/*void merge(node* head1,node* head2)
{
	
}*/
void movelast(node** head)
{
	node* temp=*head;
	while(((*head)->next)->next!=NULL)
	{
		*head=(*head)->next;
	}
	node* ptr=(*head);
	(*head)=(*head)->next;
	ptr->next=NULL;
	(*head)->next=temp;
}
void sort(node** head)
{
	//if u want descending order then reverse the list
	int temp;
	node* ptr1;
	node* ptr2;
	for(ptr1=*head;ptr1!=NULL;ptr1=ptr1->next)
	{
		for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
		{
			if(ptr1->data>ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
		}
	}
}
void swap(node **head)
{
	//if((*head)==NULL || (*head)->next==NULL) return 0;
	node *temp1=(*head);//,*temp2=(*head)->next;
	
	int val=0;
	while(temp1!=NULL && temp1->next!=NULL)
	{
		val=temp1->data;
		temp1->data=(temp1->next)->data;
		(temp1->next)->data=val;
		temp1=(temp1->next)->next;
		//temp2=(temp2->next)->next;
	}
}
void rotate(node** head)
{
	int i,n;
	printf("Enter the no of times list has to be rotated\n");
	scanf("%d",&n);
	for (i = 1; i <n; ++i)
	{
		movelast(head);
	}
}
void delete_alter(node** head)
{
	node *ptr,*ptr1;
	int n=size(*head);
	for(ptr=*head;ptr!=NULL;ptr=ptr->next)
	{
		ptr1=ptr->next;
		ptr->next=ptr1->next;
		ptr1->next=NULL;
		if(n%2==1 && ptr->next->next==NULL)
			break;
	}
}
//node* merge(node* h,node* h1)

int main()
{
	//int n;
	node* h=insert(1);
	//getchar();
	//node* h1=insert(1);
	if(h==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	getchar();
	//sort(&h);
	//printf("Enter the nth position to be deleted\n");
	//scanf("%d",&n);
	//delete_nth_first_last_node(&h,n);
	//swap(&h);
	//rotate(&h);
	//delete_alter(&h);
	//node *hh=merge(h,h1);
	//movelast(&h);
	print(h);
	printf("size of linked list is %d\n",size(h));
	//reverse_print(h);
	//using iteration
	free(h);
	//free(h2);
	return 0;
}