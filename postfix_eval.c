
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100


struct stack {
    int top;
    int arr[MAX];
}s;


int pop() {
    if (s.top != -1){
        return s.arr[s.top--];
    }
    return 0;
}

void push(int op) {
    s.top=s.top+1;
    s.arr[s.top] = op;
}


int evaluate(char* exp) {
    s.top = -1;

    
    for (int i = 0; exp[i]; ++i){
    if (isdigit(exp[i])){
        push(exp[i] - '0');
    }
    else
    {
        int val1 = pop();
        int val2 = pop();
        switch (exp[i])
        {
            case '+': 
            {
                push(val2 + val1); 
                break;
            }
            case '-': 
            {
                push(val2 - val1);
                break;
            }
            case '*': 
            {
            push(val2 * val1); 
            break;
            }
            case '/': 
            {
            push(val2 / val1); 
            break;
            }
            case '%': 
            {
            push(val2 % val1); 
            break;
            }
        }
    }
}
return pop();
}


int main()
{
    char exp[MAX];
    printf("Enter the expression: ");
    scanf("%s", exp);
    printf("postfix evaluation: %d", evaluate(exp));
    return 0;
}

    
