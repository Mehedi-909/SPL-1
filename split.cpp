#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "This is(a Test)";
    char c = '(';
    char c2 = ')';

    // Find first occurrence of 'g'
    size_t found = str.find(c);
    if (found != string::npos)
        cout << "First occurrence is " << found << endl;

    // Find next occurrence of 'g'
    size_t found2 = str.find(c2,found+1);
    if (found != string::npos)
        cout << "Next occurrence is " << found2 << endl;
        string r = str.substr(found+1, found2-found-1);

    // prints the result
    cout << "String is: " << r;

    return 0;
}
