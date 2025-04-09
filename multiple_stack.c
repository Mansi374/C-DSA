#include<stdio.h>
#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

void pushA(int val) {
    if (topA + 1 == topB || topA==MAX-1) {
        printf("\noverflow in StackA");
        return;
    }
    stack[++topA] = val;
}

int popA() {
    if (topA == -1) {
        printf("\nunderflow in StackA");
        return -1;
    }
    return stack[topA--];
}

void DisplayA() {
    if (topA == -1) {
        printf("\nstackA is empty");
        return;
    }
    for (int i = topA; i >= 0; i--)
        printf("   %d", stack[i]);
}

void pushB(int val) {
    if (topB - 1 == topA) {
        printf("\noverflow in StackB");
        return;
    }
    stack[--topB] = val;
}

int popB() {
    if (topB == MAX) {
        printf("\nunderflow in StackB");
        return -999;
    }
    return stack[topB++];
}

void DisplayB() {
    if (topB == MAX) {
        printf("\nstackB is empty");
        return;
    }
    for (int i = topB; i < MAX; i++)
        printf("   %d", stack[i]);
}

void main() {
    int ele, choice;
    do {
        printf("\n 1 pushA");
        printf("\n 2 popA");
        printf("\n 3 DisplayA");
        printf("\n 4 popB");
        printf("\n 5 popB");
        printf("\n 6 DisplayB");
        printf("\n 7 exit");
        printf("\n enter your Choice:");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n Enter no : ");
            scanf("%d", &ele);
            pushA(ele);
            break;
        case 2:
            ele = popA();
            if (ele!=-1)
                printf("\n % d popped ", ele);
            break;
        case 3:
            DisplayA();
            break;
        case 4:
            printf("\n Enter no : ");
            scanf("%d", &ele);
            pushB(ele);
            break;
        case 5:
            ele = popB();
            if (ele != -1)
                printf("\n % d popped ", ele);
            break;
        case 6:
            DisplayB();
            break;
        case 7:
            break;
        default:
            printf("\n invalid choice");
        }
    } while (choice != 7);
}