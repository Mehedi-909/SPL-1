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
                printf("%c",s[i]);
                i++;
            }
            int j=0;
        for(j=0;s[j]!='\0';j++){

        }


   return j;
}

int main() {



   fp = fopen("test.txt", "r");
   int i=1;
   while(i<=13){
    int c=countCInLine(i);
    printf("%d characters in line %d",c,i);
    i++;
   }



   fclose(fp);
    return 0;
}
