/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 5
void Enqueue(int x);
void Display();
void Dequeue();
struct queue {
	int a[MAX];
	int front;
	int rear;
} q;

int main()
{
	q.front=-1,q.rear=-1;
	int choice,x;
	do {
		printf("\nMenu:");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display the Queue");
		printf("\n4.Exit");
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
			break;
		default:
			printf("\nInvalid input");
			break;
		}
	} while(choice!=4);

}
void Enqueue(int x) {
	if ((q.rear + 1) % MAX == q.front) {
		printf("Overflow");
		return;
	}
	if(q.front==-1 && q.rear==-1) {
		q.front=0;
		q.rear=0;
		q.a[q.rear]=x;
		return;
	}
	q.rear=(q.rear+1)%MAX;
	q.a[q.rear]=x;
	return;
}
void Dequeue() {
	if(q.front==-1) {
		printf("Underflow");

		return;
	}
	if(q.front==q.rear) {
		q.front=-1;
		q.rear=-1;
	}
	else {
		q.front=(q.front+1)%MAX;
		return;
	}
}
void Display() {
	int i=q.front;;
	do {
		printf("%d -> ", q.a[i]);
		if (i == q.rear)
		{
			break;
		}
		else {
			i = (i + 1) % MAX;
		}
	} while(i != q.rear+1);
}
