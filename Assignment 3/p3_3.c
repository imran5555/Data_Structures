#include<stdio.h>
#include<stdlib.h>
typedef struct Node{          //declaring structure for making the node
	int data;
	struct Node *next;
} node;
void init_l(node **cur)      //for initialising a node with null
{
	*cur=NULL;
}
int empty_l(node *head)      //for checking whether the list is empty or not
{
	if(head==NULL) return 1;
	else return 0;	
}
int atend_l(node *cur)      //for checking whether the current node is at end of the list or not
{
	if(cur->next==NULL) return 1;
	else return 0;
}
void insert_front(node **target,node **head)  //for inserting a node in the front of the linked list
{
	//node *cur=*target;
	if(*head==NULL) *head=*target;
	else
	{
		(*target)->next=*head;
		*head=*target;
	}
}
void insert_after(node **target,node *prev)   //for inserting a node after a given node in a list
{
	if(prev->next==NULL)
	{
		prev->next=*target;
	}
	else
	{
		node *cur=NULL;
		cur=prev->next;
		prev->next=*target;
		(*target)->next=cur;
	}
}
void delete_front(node **head)            //for deleting the first node of the list
{
	node *temp=*head;
	(*head)=(*head)->next;
	temp->next=NULL;
	free(temp);
}
int delete_after(node *prev)             //for deleting a node after a given node 
{
	if(prev->next==NULL || prev==NULL) return -1;
	else if((prev->next)->next==NULL)
	{
		node *cur=prev->next;
		prev->next=NULL;
		free(cur);
		return 0;
	}
	else
	{
		node *temp1,*temp2;
		temp1=prev->next;
		temp2=temp1->next;
		temp1->next=NULL;
		prev->next=temp2;
		free(temp1);
		return 0;
	}
}
void print_l(node *head)       //for printing the list in the same order
{
	node *cur=head;
	if(head==NULL)
	{
		printf("MEMORY ERROR!!!\n");
		return;
	}
	printf("The list is:\n");
	while(cur!=NULL)
	{
		printf("%d\n",cur->data);
		cur=cur->next;
	}
}
node *unordered_search(node **head,int key)   //searching for a key in an unordered list
{
	node *temp;
	if((*head)==NULL) return (*head);
	else
	{
		temp=(*head);
		if((*head)->data==key)
		{
			(*head)=(*head)->next;
			temp->next=NULL;
			return temp;
		}
		while(temp->next!=NULL)
		{
			if((temp->next)->data==key)
			{
				node *cur=temp->next;
				temp->next=cur->next;
				cur->next=NULL;
				return cur;
			}
			else temp=temp->next;
		}
		return 0;
	}
}
node *ordered_search(node **head,int key)  //searching for a key in an ordered list
{
	node *temp;
	int tmp;
	if((*head)==NULL) return *head;
	else
	{
		temp=(*head);
		if((*head)->data==key)
		{
			(*head)=(*head)->next;
			temp->next=NULL;
			return temp;
		}
		tmp=(*head)->data;
		while(temp->next!=NULL)
		{
			if((temp->next)->data==key)
			{
				node *cur=temp->next;
				temp->next=cur->next;
				cur->next=NULL;
				return cur;
			}
			else if(tmp<key && temp->data<key)
			{
				tmp=temp->data;
				temp=temp->next;
			}
			else return 0;
		}
	}
}
int size_l(node *head)  //finding th size of the list
{
	int l=0;
	node *temp=head;
	if(head==NULL) return 0;
	else
	{
		while(temp!=NULL)
		{
			l++;
			temp=temp->next;
		}
		return l;
	}
}
int list_cmp(node *head1,node *head2)   //comparing two lists
{
	if(head1==NULL && head2== NULL)
		return 1;
	else if(size_l(head1)==size_l(head2))
	{
		node *temp1=head1,*temp2=head2;
		while(temp1!=NULL)
		{
			if(temp1->data==temp2->data)
			{
				temp1=temp1->next;
				temp2=temp2->next;
			}
			else return 0;
		}
		return 1;
	}
	else return 0;			 
}
int revprint_l(node *head)    //reverse printing a list
{
	if(head->next==NULL)
	{
		printf("%d\n",head->data);
		return 0;
	}
	else
	{
		revprint_l(head->next);
		printf("%d\n",head->data);
		return 0;
	}
}
void append_l(node **head1,node *head2)    //appending a list at the end of another
{
	node *temp=*head1;
	while(temp->next!=NULL) temp=temp->next;
	temp->next=head2;
}
/*int swap(node **head)         //not working
{
	if((*head)==NULL || (*head)->next==NULL) return 0;
	node *temp1=(*head),*temp2=(*head)->next;
	if(temp2->next==NULL)
	{
			temp2->next=temp1;
			temp1->next=NULL;
			*head=temp2;
			return 0;	
	}
	int i=0;
	while(temp1->next!=NULL && temp1!=NULL)
	{
		node *cur=NULL;
		cur=temp2->next;
		temp2->next=temp1;
		temp1->next=cur;
		temp1=temp1->next;
		if(i==0){
			*head=temp2;i++;
		}
		temp2=temp1->next;
	}
	return 0;
}*/
void delete_list(node **head)    //deleting the list
{
	node *temp=(*head);
	while((*head)!=NULL)
	{
		(*head)=(*head)->next;
		temp=(*head);
		free(temp);
	}
}
node *rem_duplicates_unordered(node *head)   //removing duplicates in an unordered list
{
	int size=size_l(head),i,j;
	int a[size];
	node *temp=head;
	for(i=0;i<size;i++)
		a[i]=0;
	a[0]=head->data;
	i=0;
	while(temp->next!=NULL)
	{
		int k=0;
		for(j=0;j<=i;j++)
		{
			if((temp->next)->data==a[j])
			{
				node *cur=temp->next;
				temp->next=cur->next;
				free(cur);
				k=1;
				break;
			}
		}
		if(k==0)
		{
			a[++i]=(temp->next)->data;
			temp=temp->next;
		}
	}
	return head;
}
node *reverseList2(node *after)			//for reversing the list using iteration method
{
	if(after==NULL || after->next==NULL) return after;
	node *prev=after,*p=NULL;
	after=after->next;
	prev->next=NULL;
	p=after;
	after=after->next;
	while(after->next!=NULL)
	{
		p->next=prev;
		prev=p;
		p=after;
		after=after->next;
	}
	p->next=prev;
	after->next=p;
	return after;
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
	node *head=insert(1);
	print_l(head);
//	ordered_search(&head,5);
//	print_l(head);
//	printf("The size of the list is %d\n",size_l(head));
//	swap(&head);
//	print_l(head);
//	delete_list(&head);
//	print_l(head);
	head=rem_duplicates_unordered(head);
	print_l(head);
	return 0;
}
