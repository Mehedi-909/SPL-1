#include<stdio.h>
int main(){
    int a , b , c , d ,sum1 ,sum2 ;
    printf("Enter first 2 numbers :\n");
    scanf("%d %d", & a , & b );
    printf("Enter second 2 numbers :\n");
    scanf("%d %d", & c , & d );
    sum1 = a + b ;
    sum2 = c + d ;
    printf("Sum1 : %d\n", sum1 );
    printf("Sum2 : %d", sum2 );
    return 0;
}
