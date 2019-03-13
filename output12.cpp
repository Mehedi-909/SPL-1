#include<stdio.h>
int main(){
    int num1 , num2 , sum = 0 , i , j , total = 0;
    scanf("%d %d",& num1 , & num2 );
    sum = num1 + num2 ;
    printf("Sum is : %d \n", sum );
    for( j = 1; j <= num1 ; j++) {
        total = total + j ;

	 }
    printf("Number1 is %d: ", num1 );
    printf("Total is: %d\n", total );
	return 0 ; 
}