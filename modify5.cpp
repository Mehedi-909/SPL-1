#include<iostream>
#include<stack>
#include<string>
#include<cstdio>
#include<cstring>
#include <sstream>
using namespace std;

FILE *fp;
   char buff[60];
   int countChar[15];

   int countCInLine(int line){
    fgets(buff,sizeof buff,fp);
    char s[255];
    int i=0;
     while(buff[i]!='\0'){
                s[i]=buff[i];
                //printf("%c",s[i]);
                i++;
            }
            int j=0;
        for(j=0;s[j]!='\0';j++){
            //printf("%c",s[j]);
        }
        //printf("\n");


   return j;
}

int main(){
    char file[10];
    string variable;
    int line=0,variableCounter=0;
    printf("Enter filename with extension: \n");
    scanf("%s",file);
    printf("Enter variable name & line with a space: \n");
    cin>>variable;
    cin>>line;
    cout<<"Entered variable is : "<<variable<<endl;
    variableCounter++;
    fp=fopen(file,"r");
     if (fp == NULL)
    {
        printf("File does not exist \n");
        return 0;
    }
    else  printf("File opened succesfully. \n");
    int i=1;

    int count=0;
    long countToLine=0;
    char getLine[200];

    while(fgets ( getLine, sizeof getLine, fp ) != NULL ){

            count++;
           if(count==line-1) countToLine=ftell(fp);

    }

    printf("Total line : %d \n",count);
    long totalByte=ftell(fp);
    printf("Total byte : %ld \n",totalByte);
    printf(" byte upto line : %ld \n",countToLine);

    rewind(fp);

    int j=1;
   while(j<=count){
    int c=countCInLine(j);
    countChar[j]=c;
    //printf("%d characters in line %d \n",count[i],i);
    j++;
   }

    rewind(fp);
    int count2=0;

    //char getLine2[totalByte-countToLine+100];
    while(fgets ( getLine,countToLine , fp ) ){

            count2++;
        if(count2==line-1) break;

    }
    printf("line read: %d \n",count2);

    //int byteToEnteredLine=ftell(fp);
    //printf("Total byte : %d ",byteToEnteredLine);
    //count2++;

    char getCharacter;
    int currentLine=line-1;
     fseek( fp, countToLine, SEEK_SET );

    //char lineBuffer[20][100];
    char s[255];
    int itr=0;
    stack <string> dependent;
    string var[5];
    int varCount=0;


    //store2 = new string[200];

    while(fgets ( getLine, sizeof getLine, fp )){
            string store1[200];
        //cout<<"OK1"<<endl;
        //cout<<getLine<<endl;
        stringstream ss1(getLine);
        int i=0;
        while(ss1>>store1[i]){
            i++;
        }
        int length = sizeof(store1)/sizeof(store1[0]);
        //cout<<"Length of store2: "<<length<<endl;
        for(i=0;i<length;i++){
                //cout<<"OK2"<<endl;
            if((store1[i].compare("="))==0 || (store1[i].compare("!="))==0 || (store1[i].compare("<="))==0 || (store1[i].compare(">="))==0 ){
                //cout<<"OK3"<<endl;
                    i++;
                ss1>>store1[i];

                if( (store1[i].compare(variable))==0 ){

                        var[varCount]=store1[i-2];
                    cout<<"Stored variable : " << var[varCount]<<endl;
                    varCount++;


                }

                else i--;
            }

            else if((store1[i].compare("+"))==0 || (store1[i].compare("-"))==0 || (store1[i].compare("*"))==0 || (store1[i].compare("/"))==0){

                i++;
                ss1>>store1[i];
                if( (store1[i].compare(variable))==0){

                        var[varCount]=store1[0];
                    cout<<"Stored variable : " << var[varCount]<<endl;
                    varCount++;
            }
        }
    }

    }

    rewind(fp);
    //delete(store2);

    //store2 = new string[200];
    while(fgets ( getLine, sizeof getLine, fp )){
            string store2[200];
        //cout<<"OK1"<<endl;
       // cout<<"This line is culprit : "<<getLine<<endl;
        stringstream ss1(getLine);
        int i=0;
        while(ss1>>store2[i]){

            //cout<<"Hi "<<store2[i]<<"  i= "<<i<<endl;
            i++;
        }
        int length = sizeof(store2)/sizeof(store2[0]);
        //cout<<"store2[1] : "<<store2[1]<<endl;
        for(i=0;i<length;i++){
                //cout<<"OK2"<<endl;

            if((store2[i].compare("="))==0 || (store2[i].compare("!="))==0 || (store2[i].compare("<="))==0 || (store2[i].compare(">="))==0 ){
                //cout<<"Entering with "<<store2[i]<<endl;
                    i++;
                ss1>>store2[i];

                for(int j=0;j<(sizeof(var)/sizeof(var[0]));j++){
                if( (store2[i].compare(var[j]))==0 ){

                        var[varCount]=store2[i-2];
                        //cout<<"Checking : "<<store2[i]<<"  "<<store2[i-1]<<" "<<store2[i-2]<<" "<<var[j]<<endl;
                    cout<<"Stored variable : " << var[varCount]<<endl;
                    varCount++;


                }

                //else i--;
            }

        }

            else if((store2[i].compare("+"))==0 || (store2[i].compare("-"))==0 || (store2[i].compare("*"))==0 || (store2[i].compare("/"))==0){

                 //cout<<"Entering with "<<store2[i]<<endl;
                i++;
                ss1>>store2[i];
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
    cout<<"Stored variables are : "<<endl;
    for(int k=0;k<5;k++){
        cout<<var[k]<<endl;
    }

    rewind(fp);
    FILE *fp2=fopen("output.txt","w");
    int r=0;
     while(fscanf ( fp, "%c", getLine ) != EOF ){
            //cout<<" testing : "<< getLine[0]<<endl;
            if(getLine[0] == '#'){
                fprintf(fp2,"%c",'#');
                char remaining[50];
                fgets(remaining, sizeof remaining, fp);
                fputs(remaining,fp2);

            }
     }


     fseek( fp, countToLine, SEEK_SET );
    //fscanf(fp,"%s",s);
    //dependent.push(s);
    int count3=0;
    //var[count3]=s;
    //cout<<"New variable: "<<dependent.top()<<endl;
   // cout<<"New variable stored in string: "<<var[count3]<<endl;



    while(fgets ( getLine, sizeof getLine, fp )){
            string store3[200];
        stringstream ss(getLine);
        int i=0;
         while (ss >> store3[i]){
           if((store3[i].compare(variable))==0 || (store3[i].compare(var[count3]))==0 || (store3[i].compare(var[count3+1]))==0 || (store3[i].compare(var[count3+2]))==0 || (store3[i].compare(var[count3+3]))==0){
                for(int j=0;j<strlen(getLine);j++){
                    //printf("%c",getLine[j]);
                    fprintf(fp2,"%c",getLine[j]);
                }
                //cout<<"Entering"<<endl;
               // cout<<"Found "<<store3[i]<<endl;
               printf("\n");
            }

        i++;

    }

    }
    fclose(fp2);


    fclose(fp);

}


