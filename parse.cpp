#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main()
{
   string str = "number1,number2";
   stringstream ss(str);

   string token;

while (getline(ss,token, ','))
{
    cout<< token <<endl;
}


   return 0;
}
