#include<stdio.h>
int function (int a) {
    int i=0;
    for(i=0;i<=a;i++) {
        printf("%d\n",i);
    }
    return i;
}

int main(){
    int num1 ;
    int num2 , sum = 0 , i , j ;
    int total = 0;
    scanf("%d",& num1 );
    scanf("%d",& num2 );
    sum = num1 + num2 ;
    char c[5]="Test";
    printf("Sum is : %d \n", sum );

    for( j = 1; j <= num1 ; j++) {
        total = total + j ;
    }
    int test=function( num2 );
    int test2=function( total );

    printf("Number1 is %d: ", num1 );
    printf("Number2 is %d: ", num2 );
    printf("Total is: %d\n", total );
    return 0;
}
