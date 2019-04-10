//this is testing
#include<iostream>
#include<string>

using namespace std;

int main(){
    char c[15];
    string s;
    for(int i=0;i<15;i++){
        c[i]=65+i;
        cout<<c[i];
    }
    cout<<endl;
    s=c;
    if(s.compare(c)==0){
        cout<<"OK"<<endl;
    }
    cout<<"s : "<<s<<endl;

}
