#include <stdio.h>
FILE *fp;
   char buff[50];
   int count[15];

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
            printf("%c",s[j]);
        }
        printf("\n");


   return j;
}

int main() {



   fp = fopen("code1.c", "r");
   int i=1;
   while(i<=13){
    int c=countCInLine(i);
    count[i]=c;
    printf("%d characters in line %d \n",count[i],i);
    i++;
   }



   fclose(fp);
    return 0;
}
