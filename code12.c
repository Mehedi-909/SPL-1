#include<stdio.h>
int main(){
    int num1 , num2 , sum = 0 , i , j , total = 0;
    printf("Enter two numbers: \n");
    scanf("%d %d",& num1 , & num2 );
    sum = num1 + num2 ;
    char c[5]="Test";
    printf("Sum is : %d \n", sum );
    for( i = 0 ; i < 5 ; i ++ ) {
    printf("%c",c[i]);
    }
    printf("\n");
    for( j = 1; j <= num1 ; j++) {
        total = total + j ;
    }
    printf("Number1 is %d: ", num1 );
    printf("Total is: %d\n", total );
    return 0;
}
