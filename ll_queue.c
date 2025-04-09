#include <stdio.h>
#include<stdlib.h>
struct ll_node {
 int data;
 struct ll_node *next;
 struct ll_node *front;
  struct ll_node *rear;
};
struct ll_node *front=NULL;
struct ll_node *rear=NULL;
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
printf("\n1.Enqueue");
printf("\n2.Deqeue");
printf("\n3.Display");
printf("\n4.Exit");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice) {
case 1:
printf("\nEnter val to be enqueued:");
scanf("%d",&value);
myList=Insert(myList,value);
break;
case 2:
myList=del(myList,front->data);
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
struct ll_node *pnew;
pnew=(struct ll_node*)malloc(sizeof(struct ll_node));
pnew->data=value;
pnew->next=NULL;
if(front==NULL) {
front=pnew;
rear=pnew;
return;
}
if(front!=NULL) {
rear->next=pnew;
rear=pnew;
display(list);
return;
}
}
struct ll_node *del(struct ll_node *list,int target) {
struct ll_node *help_ptr, *node2delete;
if(front==NULL){
    printf("Underflow");
    return;
}
node2delete=front;
front=front->next;
display(list);
return;
}


void display(struct ll_node *list) {
struct ll_node *hp;
if(front==NULL){
    printf("Underflow");
    return;
}
hp=front;
while(hp!=NULL){
    printf("%d->",hp->data);
    hp=hp->next;
}
return;


}