#include <iostream>
#include<string>
using namespace std;

struct node
{
	node *parent;
	string data;
	int degree;
	node *left, *right;

};

node *root;

void createTree(void)
{
	root= NULL;
}

node* createNode(string input){
	node *temp;
	temp = new node[1];
	temp[0].parent = NULL;
	temp[0].data = input;
	temp[0].degree = 0;
	temp[0].left = NULL;
	temp[0].right = NULL;

	return temp;
}

void insertNode(node *newNode){


    if(root == NULL)
	{
		root = newNode;
		return;
	}

	else{
        node * current = root;
		bool flag = false;

        while(1){
            if(current[0].right != NULL)
				{
					current = current[0].right;
				}
				else
				{
					flag = true;
					break;
				}
        }

        if(flag)
		{
			current[0].right = newNode;
			newNode[0].parent = current;
			newNode[0].parent[0].degree++;

        }

    }

}

void printData(node *current)
{
	if(current != NULL)
	{

		cout << current[0].data << endl;
		printData(current[0].right);
	}
}

int main(){
    string s="This is a test";
    node *newNode = createNode(s);
    insertNode(newNode);
   // cout<<newNode[0].data<<endl;
    string s2="This is another test";
    node *newNode2 = createNode(s2);
    insertNode(newNode2);

    s2="This is another one";
    newNode2 = createNode(s2);
    insertNode(newNode2);

    printData(newNode);
return 0;
}
