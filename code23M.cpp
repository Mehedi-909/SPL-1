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

    fscanf(fp,"%s",s);
    dependent.push(s);
    int count3=0;
    var[count3]=s;
    cout<<"New variable: "<<dependent.top()<<endl;
    cout<<"New variable stored in string: "<<var[count3]<<endl;

    string store3[200];
    while(fgets ( getLine, sizeof getLine, fp )){
        stringstream ss(getLine);
        int i=0;
         while (ss >> store3[i]){
           if((store3[i].compare(variable))==0 || (store3[i].compare(var[count3]))==0){
                for(int j=0;j<strlen(getLine);j++){
                    printf("%c",getLine[j]);
                }
                //cout<<"Entering"<<endl;
               // cout<<"Found "<<store3[i]<<endl;
               printf("\n");
            }

        i++;

    }

    }


    fclose(fp);

}


