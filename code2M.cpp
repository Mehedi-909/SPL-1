#include<stdio.h>
#include<string.h>
int main(){
    char file[10];
    char storeVariable[10][15];
    int line=0,variableCounter=0;
    printf("Enter filename with extension: \n");
    scanf("%s",file);
    printf("Enter variable name & line with a space: \n");
    scanf("%s %d",storeVariable,&line);
    variableCounter++;
    FILE *fp ;
    fp=fopen(file,"r");
     if (fp == NULL)
    {
        printf("File does not exist \n");
        return 0;
    }
    else  printf("File opened succesfully. \n");
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
    int i=0;
    while(fgets ( getLine,23 , fp ) != NULL ){
            //getCharacter=fgetc(fp);
            //printf("%c",getCharacter);
            //lineBuffer=getLine;
            while(getLine[i]!='\0'){
                s[i]=getLine[i];
                printf("%c",s[i]);
                i++;
            }
            if(getCharacter=='\n'){
            currentLine++;
        }

        //if(ch=='\n')
        //fgets ( getLine, sizeof getLine, fp );
        //getCharacter=fgetc(fp);
       // printf("%c",getCharacter);
        /*
        if(getCharacter=='='){
                char store[15];
                //int flag=0;
                getCharacter=fgetc(fp);
          /*  while(getCharacter != '+' || getCharacter != '-' || getCharacter != '*' || getCharacter != '/' || getCharacter != ';'){

            //if((getCharacter=fgetc(fp)) != '+' || getCharacter != '-' || getCharacter != '*' || getCharacter != '/' || getCharacter != ';'){
                int i=0;
                store[i]=getCharacter;
                i++;
                printf("Storing %c",store[i]);
                //getCharacter=fgetc(fp);
                getCharacter=fgetc(fp);
            //flag=1;
            //}
           // else flag=0;
            } */
            /*
            int k;
            printf("Expected variable is: ");
            for(k=0;k<strlen(store);k++){
                printf("%c",store[k]);
            }
                printf("\n");
            if((strcmp(store,storeVariable))==0){
                //fseek( fp, line, SEEK_SET );
                printf("Variable found ");
                while(fgets ( getLine, sizeof getLine, fp ) != NULL ){

            count2++;
            if(count2==line-1) break;

                }


                while(1){
            if((getCharacter=fgetc(fp)) != '='){
                int i=0;
                store[i]=getCharacter;
                i++;
            }
            else break;
            }
            }
            int j;
            for(j=0;j<strlen(store)-1;j++){
                printf("%c",store[j]);
            }

        }

           // if(count==line)
           */


    }

    //printf("Total line : %d ",count);
    fclose(fp);
}

