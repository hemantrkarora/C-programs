/*
*Program to count the number of times each distinct integer is repeated in a linked list.
*For example,
*1->3->7->2->6->3->2->5->1
*Distinct Integers	Count
*1			2
*2			2
*3			2
*5			1
*6			1
*7			1

*/

//By Hemant Arora

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	int count;
}node;

void insert(node **cond_ref,int x){
	if(!(*cond_ref)->data){
		(*cond_ref)->data=x;
		return;
	}

	(*cond_ref)->next=(node *)malloc(sizeof(node));
	(*cond_ref)->next->data=x;
	(*cond_ref)->next->next=NULL;
	(*cond_ref)->next->count=1;
	(*cond_ref)=(*cond_ref)->next;
}

void display(node **root_ref){
	node *temp=*root_ref;
	while(temp->next!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}

void displayCount(node **root_ref){
	node *temp=*root_ref;
	printf("Data\tCount\t\n");
	while(temp!=NULL){
		printf("%d\t%d\n",temp->data,temp->count);
		temp=temp->next;
	}
}

node *copy(node **root_ref){
	node *temp=*root_ref;
	node *new_root=(node *)malloc(sizeof(node));
	node *new_cond=(node *)malloc(sizeof(node));

	new_cond=new_root;

	while(temp!=NULL){
		insert(&new_cond,temp->data);
		temp=temp->next;
	}

	return new_root;
}

void deleteNode(node **cond_ref,node **root_ref){
	node *temp=*root_ref;
	while(temp->next!=*cond_ref){
		temp=temp->next;
	}
	temp->next=(*cond_ref)->next;
	printf("Deleted element %d\n",(*cond_ref)->data);
}

void deleteDuplicate(node **root_ref){
	node *cond=*root_ref;
	node *temp=cond;
	while(cond!=NULL){
		temp=cond->next;
		while(temp!=NULL){
			if(cond->data==temp->data){
				(cond->count)++;
				deleteNode(&temp,root_ref);
			}
			temp=temp->next;
		}
		cond=cond->next;
	}
}

int main(){
	node *root=(node *)malloc(sizeof(node));
	node *conductor=(node *)malloc(sizeof(node));

	root->count=1;
	conductor=root;

	printf("Enter elements,-1 to exit\n");
	int n;
	scanf("%d",&n);
	while(n!=-1){
		insert(&conductor,n);
		scanf("%d",&n);
	}

	printf("\nOriginal List:  ");	
	display(&root);
	
	//make new copy	
	node *new_root=copy(&root);
	printf("\nNew copy of list : ");
	display(&new_root);

	printf("\nDeleting duplicate elements ...\n");
	deleteDuplicate(&new_root);
	printf("\nDistinct integers:  ");
	display(&new_root);

	printf("\n----------------\n");
	displayCount(&new_root);

return 0;
}
