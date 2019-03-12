#include<stdio.h>
#include<string.h>

int main(){

    int num1 ,num2,sum=0,i=0,total=0;
    printf("Enter two numbers: \n");
    scanf("%d %d",& num1 , & num2 );
    sum = num1 + num2;
    char c[5]="Test";
    printf("Sum is : %d \n", sum );
    for(i=0;i<5;i++){
    printf("%c",c[i]);
    }
    printf("\n");
    for(i = 1; i <= num1 ;i++){
        total = total + i ;
    }

    printf("Total is: %d\n", total );
    printf("Number1 is %d: ", num1 );
    return 0;
}
