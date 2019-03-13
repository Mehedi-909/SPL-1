#include<stdio.h>
int main(){
    int a = 0;
    printf("Enter a number: ");
    scanf("%d", & a );
    char c [5];
    for(int i = 0 ; i < sizeof c ; i++ ) {
        c [i] = 65 + i ;
        printf( "%c \t", c [i] );
    }
    printf("You entered : %d", a );
    return 0;
}
