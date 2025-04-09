/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct ll_node {
	int data;
	struct ll_node *next;
	struct ll_node *prev;
};
struct ll_node *Insert(struct ll_node *list,int value);
struct ll_node *del(struct ll_node *list,int target);
void display(struct ll_node *list);

int main()
{
	struct ll_node *myList;
	myList=NULL;
	int choice,value;
	do {
		printf("\nMenu");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			printf("\nEnter val to be inserted:");
			scanf("%d",&value);
			myList=Insert(myList,value);
			break;
		case 2:
			printf("\nEnter val to be deleted:");
			scanf("%d",&value);
			myList=del(myList,value);
			break;
		case 3:
			display(myList);
			break;
		case 4:
			break;
		}
	}
	while(choice!=4);

}
struct ll_node *Insert(struct ll_node *list,int value) {
	struct ll_node *pnew,*hp,succ;
	pnew=(struct ll_node*)malloc(sizeof(struct ll_node));
	pnew->data=value;
	pnew->next=NULL;
	pnew->prev=NULL;
	if(list==NULL || list->data<value) {
		pnew->next=list;
		if(list!=NULL)
			list->prev=pnew;
		list=pnew;
		return list;
	}
	hp=list;
	while(hp->next!=NULL && hp->next->data>value) {
		hp=hp->next;
		succ=hp->next;
		hp->next=pnew;
		pnew->prev=hp;
		pnew->next=succ;
		if(succ!=null) {
			succ->prev=pnew;
			return list;
		}

	}

}
struct ll_node *del(struct ll_node *list,int target) {
	struct ll_node *help_ptr, *node2delete;
	help_ptr = list;
	if (help_ptr != NULL) {
		if (help_ptr->data == target) {
			list = help_ptr->next;
			help_ptr->next->prev=NULL;
			free(help_ptr);
			return list;
		}
		while (help_ptr->next != NULL) {
			if (help_ptr->next->data == target) {
				node2delete = help_ptr->next;
				help_ptr->next = node2delete->next;
				if(node2delete->next!=NULL) {
					node2delete->next->prev=help_ptr;
				}
				free(node2delete);
				return list;
			}
			help_ptr = help_ptr->next;
		}
		printf("\nElement not found");
		return list;
	}
	printf("\nList Empty");
	return list;
}
void display(struct ll_node *list) {
	struct ll_node *hp;
	hp=list;
	printf("\n");
	while(hp!=NULL) {
		printf("%d->",hp->data);
		hp=hp->next;
	}
	return;
}
