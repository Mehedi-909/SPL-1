#include<stdio.h>
void function (int input){
    int i=0,total=0;
    for(i=0;i<input;i++) {
        total=total+i;
    }
    printf("%d\n",total);
}

void function2 (int input1,int input2) {
    int sum=input1+input2;
    printf("%d\n",sum);
}

void main(){

    int a ;
    int b ;
    int c ;
    scanf("%d",& a );
    scanf("%d",& b );
    c = a * a ;
    int i = 0;
    printf("%d", a );
    printf("%d", b );
    printf("%d", c );

    function ( a );
    function ( b );
    function ( c );
    function2 (a,c);

}
