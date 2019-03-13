#include<stdio.h>
int main(){
    char c [5];
    for(int i = 0 ; i < sizeof c ; i++ ) {
        c [i] = 65 + i ;
        printf( "%c \t", c [i] );

	 }
	return 0 ; 
}