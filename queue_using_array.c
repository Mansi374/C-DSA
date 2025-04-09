/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 5
struct queue{
    int a[MAX];
    int front;
    int rear;
}q;
void Enqueue(int x);
void Dequeue();
void Display();

int main()
{
    int choice,x;
	q.front=-1,q.rear=-1;
	do {
		printf("\nMenu:");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display the Queue");
		printf("\n7.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			printf("Enter element to be enqueued:");
			scanf("%d",&x);
			Enqueue(x);
			break;
		case 2:
			Dequeue();
			break;
		case 3:
			Display();
			break;
		case 4:
			return 0;
		default:
			printf("\nInvalid input");
			break;
		}
	} while(choice!=4);
    
}
void Enqueue(int x){
    if(q.rear==MAX-1){
        printf("\nThe queue is full");
        return;
    }
    q.front++;
    q.rear++;
    q.a[q.rear]=x;
    printf("\nThe queue after enqueue is:");
    for(int i=0;i<=q.rear;i++){
        printf("\n%d",q.a[i]);
    }
}
void Dequeue(){
    if(q.front==-1 || q.rear==-1){
        printf("\nThe array is empty");
    }
    for(int i=1;i<MAX;i++){
        q.a[i-1]=q.a[i];
    }
    q.rear-=1;
    if(q.front==-1 || q.rear==-1){
        printf("\nThe array is empty");
        return;
    }
    printf("\nThe dequeue after denqueue is:");
    for(int i=0;i<=q.rear;i++){
        printf("\n%d",q.a[i]);
    }
    
}
void Display(){
    for(int i=0;i<=q.rear;i++){
        printf("%d\n",q.a[i]);
    }
}