#include<stdio.h>
#include<stdlib.h>

struct ll_node {
	int data;
	struct ll_node* next;
};

struct ll_node *top=NULL;
void Push(struct ll_node* list){
    int ele;
    printf("Enter number to be inserted");
    scanf("%d",&ele);
    struct ll_node *pnew=(struct ll_node*)malloc(sizeof(struct ll_node));
    pnew->data=ele;
    pnew->next=top;
    top=pnew;
    display();
}
void Pop(struct ll_node* list){
    if(top==NULL){
       printf("The stack is empty");
       return;
    }
    struct ll_node* node2del=top;
    top=top->next;
    free(node2del);
    display();


}
void display(){
    if(top==NULL){
       printf("The stack is empty");
       return;
    }
    struct ll_node* hp;
    hp=top;
    while(hp!=NULL){
        printf("%d->",hp->data);
        hp=hp->next;
    }
    return;
}
int main() {
    struct ll_node* list;
	int choice,value;
	do {
		printf("\nMenu");
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			Push(list);
			break;
		case 2:
			Pop(list);
			break;
		case 3:
			display();
			break;
		case 4:
			break;
		}
	}
	while(choice!=4);
}


