#include <stdio.h>
#define MAX 5
struct stack {
	int top;
	int arr[MAX];
} s;
void Push();
void Pop();
void Display();

int main()
{
	int choice;
	s.top=-1;
	do {
		printf("\nMenu:");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			Push();
			break;
		case 2:
			Pop();
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
void Push() {
	int x;
	printf("\nEnter element to be inserted:");
	scanf("%d",&x);
	printf("\nBefore Inserting the element:");
	for (int i = s.top; i >= 0; i--) {
		printf("\n%d",s.arr[i]);
	}
	if(s.top!=MAX-1) {
		s.top++;
		s.arr[s.top]=x;
	}
	else {
		printf("\nStack is full");
		return;
	}
	printf("\nAfter Inserting the element:");
	for (int i = s.top; i >= 0; i--) {
		printf("\n%d",s.arr[i]);
	}


}
void Pop() {
	if(s.top==-1) {
		printf("\nThe stack is empty");
		return;
	}
	printf("\nBefore Deleting the element:");
	for (int i = s.top; i >= 0; i--) {
		printf("\n%d",s.arr[i]);
	}
	int ele=s.arr[s.top];
	s.top--;
	printf("\nAfter Deleting the element:");
	if(s.top==-1) {
		printf("\nThe stack is empty");
	}
	else {
		for (int i = s.top; i >= 0; i--) {
			printf("\n%d",s.arr[i]);
		}
	}



}
void Display() {
	if(s.top==-1) {
		printf("\nThe stack is empty");
		return;
	}
	else {
		printf("\nDisplaying the Stack:");
		for (int i = s.top; i >= 0; i--) {
			printf("\n%d",s.arr[i]);
		}

	}
}