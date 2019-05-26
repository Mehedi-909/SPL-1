#include <iostream>
using namespace std;

int main()
{
    string s1="This is ", result;
    char s2[10];
    for(int i=0;i<9;i++){
        s2[i]='a';
    }
    s2[9]='\n';



    result = s1 + s2;

    cout << "Resultant String = "<< result;

    return 0;
}
