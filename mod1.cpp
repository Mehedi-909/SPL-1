#include<iostream>
#include<string>
#include<cstdio>
#include <algorithm>
#include<cstring>
#include <sstream>
#include<fstream>
#include <iostream>

using namespace std;

    FILE *fp,fp2;
    char buff[100];
    int countChar[15];

int countCharacterInLine(int line){

        fgets(buff,sizeof buff,fp);
        int i=0;
        while(buff[i]!='\0'){
                i++;
            }

        return i;
    }

int contains(string s,string* arr,int count){
    for(int i=0;i<count;i++){
        if(arr[i].compare(s)==0){
            return 1;
        }
    }
    return -1;
}

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string removeEnter(string str)
{
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    return str;
}

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
	root = NULL;
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

void deleteNode(node *anyNode)
{
	delete [] anyNode;
}

void printData(node *current,ofstream &out)
{
	if(current != NULL)
	{
		//cout << current[0].data << endl;
		out<<current[0].data<<endl;
		printData(current[0].right,out);
	}
}

int main(){

    createTree();

    char inputFile[15],outputFile[15];
    string variable;
    int line=0,variableCounter=0,countCurlyBraceInFunction=0;

    printf("Enter input filename with extension: \n");
    scanf("%s",inputFile);

    printf("Enter output filename with .cpp extension: \n");
    scanf("%s",outputFile);

    printf("Enter statement number & variable with a space: \n");
    scanf("%d",&line);
    cin>>variable;

    variableCounter++;
    fp=fopen(inputFile,"r");
     if (fp == NULL){

        printf("File does not exist \n");
        return 0;
     }

    else  printf("File opened succesfully. \n");
    int i=1;

    int numberOfLine=0;
    long countToLine=0;
    char getLine[200];

    while(fgets ( getLine, sizeof getLine, fp ) != NULL ){

            numberOfLine++;
           if(numberOfLine==line-1) countToLine=ftell(fp);

    }

    printf("Total line : %d \n",numberOfLine);
    long totalByte=ftell(fp);
    printf("Total size of file : %ld  byte\n",totalByte);
    printf(" byte upto line %d : %ld \n",line,countToLine);

    rewind(fp);

    int j=1;
    while(j<=numberOfLine){

    int c=countCharacterInLine(j);
    countChar[j]=c;
    //printf("%d characters in line %d \n",count[i],i);
    j++;

    }

    rewind(fp);
    int count2=0;

    while(fgets ( getLine,countToLine , fp ) ){

        count2++;
        if(count2==line-1) break;

    }
    //printf("line read: %d \n",count2);

    //printf("Total byte : %d ",byteToEnteredLine);

    char getCharacter;
    int currentLine=line-1;
    char s[255];
    string var[10];
    string function[10];
    int varCount=0;

    fseek( fp, countToLine, SEEK_SET );

    while(fgets ( getLine, sizeof getLine, fp ) != NULL ){
            string store1[200];
        //cout<<"OK1"<<endl;
        //cout<<getLine<<endl;
        stringstream ss1(getLine);
        int i=0;

        while(ss1>>store1[i]){
            i++;
        }

        int length = sizeof(store1)/sizeof(store1[0]);

        for(i=0;i<length;i++){

            if((store1[i].compare("="))==0 || (store1[i].compare("!="))==0 || (store1[i].compare("<="))==0 || (store1[i].compare(">="))==0 || (store1[i].compare(">"))==0 || (store1[i].compare("<"))==0){
                    i++;
                //ss1>>store1[i];

                if( (store1[i].compare(variable))==0 ){

                    var[varCount]=store1[i-2];
                    //cout<<"Stored variable : " << var[varCount]<<endl;
                    varCount++;


                }

                else i--;
            }

            else if((store1[i].compare("+"))==0 || (store1[i].compare("-"))==0 || (store1[i].compare("*"))==0 || (store1[i].compare("/"))==0 || (store1[i].compare("%"))==0 || (store1[i].compare("+="))==0 || (store1[i].compare("-="))==0 || (store1[i].compare("*="))==0 || (store1[i].compare("/="))==0){

                i++;
                //ss1>>store1[i];
                if( (store1[i].compare(variable))==0){

                        var[varCount]=store1[0];
                    //cout<<"Stored variable : " << var[varCount]<<endl;
                    varCount++;
            }
        }
    }

    }

    rewind(fp);

    while(fgets ( getLine, sizeof getLine, fp )){

        string store2[200];
        //cout<<"OK1"<<endl;
        stringstream ss1(getLine);
        int i=0;
        while(ss1>>store2[i]){

            i++;
        }

        int length = sizeof(store2)/sizeof(store2[0]);

        for(i=0;i<length;i++){

            if((store2[i].compare("="))==0 || (store2[i].compare("!="))==0 || (store2[i].compare("<="))==0 || (store2[i].compare(">="))==0 ){
                //cout<<"Entering with "<<store2[i]<<endl;
                    i++;
                //ss1>>store2[i];

                for(int j=0;j<(sizeof(var)/sizeof(var[0]));j++){
                    if( (store2[i].compare(var[j]))==0 ){

                        var[varCount]=store2[i-2];
                        //cout<<"Checking : "<<store2[i]<<"  "<<store2[i-1]<<" "<<store2[i-2]<<" "<<var[j]<<endl;
                       // cout<<"Stored variable : " << var[varCount]<<endl;
                        varCount++;


                }

                //else i--;
            }

        }

            else if((store2[i].compare("+"))==0 || (store2[i].compare("-"))==0 || (store2[i].compare("*"))==0 || (store2[i].compare("/"))==0 || (store2[i].compare("%"))==0){

                 //cout<<"Entering with "<<store2[i]<<endl;
                i++;
                //ss1>>store2[i];
                 for(int j=0;j<sizeof(var)/sizeof(var[0]);j++){

                 if( (store2[i].compare(var[j]))==0){

                        var[varCount]=store2[0];
                        cout<<"Stored variable : " << var[varCount]<<endl;
                        varCount++;
                    }
                 }
            }
        }

    }

    //cout<<"Stored variables are : "<<endl;

    for(int k=0;k<(sizeof var/sizeof var[0]);k++){
        //cout<<var[k]<<endl;
    }

    rewind(fp);
    int countFunction=0;
    while(fgets ( getLine, sizeof getLine, fp ) ){

        string str=getLine;


        char c = '(';
        char c2 = ')';
        char c3 = '=';
        char c4 = ',';

    // Find first occurrence of '('
        size_t found = str.find(c);


        size_t found2 = str.find(c2,found+1);
        size_t found3 = str.find(c3);
        //if (found != string::npos)
            //cout << "Next occurrence is " << found2 << endl;
        string r = str.substr(found+1, found2-found-1);
        r=removeSpaces(r);

         stringstream separateByComma(r);

        string separatedVariables[10];
        string sp;
        int l=0;
        while (getline(separateByComma,sp, ',')){
            separatedVariables[l]=sp;
            l++;
        }
        for(int i=0;i<l;i++){
            if(separatedVariables[i].compare(variable)==0 || contains(separatedVariables[i],var,varCount)==1){

                string f=str.substr(found3+1,found-found3-1);
                f=removeSpaces(f);
                function[countFunction]=f;
            //cout<<function[countFunction]<<endl;
                countFunction++;
            }

        }

     }


     //printing into output file


    rewind(fp);
    //FILE *fp2=fopen(outputFile,"w");
    int r=0;

    createTree();

     while(fscanf ( fp, "%c", getLine ) != EOF ){
            //cout<<" testing : "<< getLine[0]<<endl;
            if(getLine[0] == '#'){

                //fprintf(fp2,"%c",'#');
                char remaining[50];

                fgets(remaining, sizeof remaining, fp);

                string temp1=getLine;
                string temp2=remaining;
                string storeInTree=temp1+temp2;
                storeInTree=removeEnter(storeInTree);

                //cout<<storeInTree<<endl;
                 //cout<<"Test1"<<endl;

               node *newNode = createNode(storeInTree);
               insertNode(newNode);
               //deleteNode(newNode);
                //cout<<"This is stored : "<<storeInTree<<endl;
                //fputs(remaining,fp2);

            }
     }

     // function call
     rewind(fp);
     while(fgets ( getLine, sizeof getLine, fp )){

        string store4[200];
        stringstream ss(getLine);
        int i=0;
        while(ss>>store4[i]){
        if(contains(store4[i],function,countFunction)==1){
                //cout<<store4[i]<<" is entering"<<endl;
                countCurlyBraceInFunction++;
                for(int j=0;j<strlen(getLine);j++){
                    //fprintf(fp2,"%c",getLine[j]);
                }
                //cout<<"Test1"<<endl;

                string storeInTree=getLine;
                storeInTree=removeEnter(storeInTree);
                //cout<<storeInTree<<endl;

                node *newNode = createNode(storeInTree);
                insertNode(newNode);
                //deleteNode(newNode);


                while(countCurlyBraceInFunction>0){
                    fgets ( getLine, sizeof getLine, fp );


                    storeInTree=getLine;
                    storeInTree=removeEnter(storeInTree);
                    //cout<<storeInTree<<endl;

                    node *newNode = createNode(storeInTree);
                    insertNode(newNode);
                    //deleteNode(newNode);

                    for(int j=0;j<strlen(getLine);j++){
                    //printf("%c",getLine[j]);

                        //fprintf(fp2,"%c",getLine[j]);
                        if(getLine[j]=='{'){
                            countCurlyBraceInFunction++;
                        }
                        else if(getLine[j]=='}'){
                            countCurlyBraceInFunction--;

                        }
                    //if(countCurlyBraceInFunction==0) break;

                    }
                }
            }
            i++;
        }
     }

    //fseek( fp, countToLine, SEEK_SET );
    rewind(fp);
    int count3=0,countCurlyBrace=0;

    char check2[100];
    while(fgets ( getLine, sizeof getLine, fp )){
            for(int n=0;n<100;n++){
                check2[n]='\0';
            }

            string store3[200];
            string check;
            //char check2[50];
        stringstream ss(getLine);
        int i=0;
         while (ss >> store3[i]){
                if((store3[i].compare("main(){"))==0 ){

                    string storeInTree=getLine;
                    storeInTree=removeEnter(storeInTree);
                    //cout<<storeInTree<<endl;

                    node *newNode = createNode(storeInTree);
                    insertNode(newNode);
                    //deleteNode(newNode);

                    for(int j=0;j<strlen(getLine);j++){
                        //fprintf(fp2,"%c",getLine[j]);
                    }
                }
                else if( (store3[i].compare("main()"))==0){

                     string storeInTree=getLine;
                     storeInTree=removeEnter(storeInTree);
                     storeInTree=storeInTree+"{";
                     //cout<<storeInTree<<endl;

                     node *newNode = createNode(storeInTree);
                     insertNode(newNode);
                     //deleteNode(newNode);


                     for(int j=0;j<strlen(getLine);j++){
                        //fprintf(fp2,"%c",getLine[j]);
                    }
                    //fprintf(fp2,"%c \n",'{');
                }


                if( store3[i].compare(variable)==0 || contains(store3[i],var,varCount)==1 ){

                check=getLine;
                //fgets ( check2,100, fp2 );
                //cout<<"Check : "<< check<<endl;
                if((check.compare(check2))!=0){

                     string storeInTree=getLine;
                     storeInTree=removeEnter(storeInTree);
                     //cout<<storeInTree<<endl;

                     node *newNode = createNode(storeInTree);
                     insertNode(newNode);
                     //deleteNode(newNode);

                     for(int j=0;j<strlen(getLine);j++){
                    //printf("%c",getLine[j]);
                     //fprintf(fp2,"%c",getLine[j]);
                     check2[j]=getLine[j];
                        if(getLine[j]=='{'){
                            countCurlyBrace++;
                        }
                     }
                }

            }


            if((store3[i].compare("}"))==0 && countCurlyBrace>0){

                string storeInTree="\t }";
                //cout<<storeInTree<<endl;
                //storeInTree=removeEnter(storeInTree);

                node *newNode = createNode(storeInTree);
                insertNode(newNode);

                countCurlyBrace--;
            }

        i++;

    }

    }

    string storeInTree="return 0;\n }";
    //cout<<storeInTree<<endl;
    //storeInTree=removeEnter(storeInTree);

    node *newNode = createNode(storeInTree);
    insertNode(newNode);
    //deleteNode(newNode);

    ofstream outF(outputFile);

    printData(root,outF);

    //fprintf(fp2,"%c%s %c \n",'\t',"return 0",';');
    //fprintf(fp2,"%c",'}');
    //fclose(fp2);
    fclose(fp);
    outF.close();

}
