// CPP program to count words in a string
// using stringstream.
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>
using namespace std;

int countWords(string str)
{
    // breaking input into word using string stream
    stringstream s(str); // Used for breaking words
    string word;
    string store[6]; // to store individual words

    int count = 0;
    int i=0;
    /*while (s >> store[i]){
        count++;
        i++;

    } */
    s>>store[0];
    s>>store[1];
    s>>store[2];
    //s>>store[3];
    for(int j=0;j<6;j++){
        cout<<store[j]<<endl;
    }
    return count;
}

// Driver code
int main()
{
    string s = "This is a test ";
    //cout << " Number of words are: " << countWords(s);
    countWords(s);
    return 0;
}
