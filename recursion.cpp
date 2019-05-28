#include<iostream>
using namespace std;

int add (int n ) {
    int sum=0;
    if( n != 0){
       n = add( n - 1);
       sum = sum + n ;
    }
    return n  ;
}

int main(){
    int n ;
    int result = 0;
    cout << "Enter a positive integer: ";
    cin >> n ;
    result = add( n );
    cout << "Sum =  " << result <<endl ;

    return 0;
}


