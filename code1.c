#include<stdio.h>

int main(){

    int num1,num2,sum,i=0;
    printf("Enter two numbers: \n");
    scanf("%d %d",& num1 , & num2 );
    sum = num1 + num2;
    char c[5]="Test";
    printf("Sum is : %d \n", sum );
    for(i=0;i<5;i++){
    printf("%c",c[i]);
    }
    printf("Number1 is : ", num1 );
    return 0;
}
