#include <stdio.h>

int Factorial(int num){
    if(num < 0){
        return -1;
    }
    if(num == 0 || num == 1){
        return 1;
    }
    return num * Factorial(num - 1);
}

int Fibonacci(int num){
    if(num == 0){
        return 0;
    }
    if(num == 1){
        return 1;
    }
    return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main(){
    int choice, num, ans = 0,f;

    do {
        printf("\n1. Factorial");
        printf("\n2. Fibonacci Series");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the number: ");
                scanf("%d", &num);
                ans = Factorial(num);
                if(ans != -1){
                    printf("\nFactorial  is %d",ans);
                } else {
                    printf("\nEnter a valid number.");
                }
                break;

            case 2:
                printf("Enter number of terms: ");
                scanf("%d", &num);
                printf("Fibonacci series:");
                for(int i = 0; i < num; i++){
                    f = Fibonacci(i);
                    printf("%d ", f);
                    ans += f;
                }
                printf("\nSum of series:%d", ans);
                ans = 0;
                break;

            case 3:
                return 0;

            default:
                printf("\nInvalid choice");
        }

    } while(choice != 3);

    return 0;
}
