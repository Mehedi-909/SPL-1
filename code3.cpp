include<iostream>
#include<cstdio>
#using namespace std;

int Static_Slice(string p,char ch)
{
int l;
string s1=‖ ‖;
 //Open program P in read mode
    FILE *fp ;
    fp=fopen(p,"r");
     if (fp == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    else  printf("File opened succesfully. \n");
 //Fetch the input variable Ch
 //Find l i.e. length of program P
 while(!EOF)
{
 for(i=0;i<=l;i++)
{
 if(ch==getc(p))
 {
 //Delete the variable;

 }
 else
 {
 s1=s1+Ch;
 }
 }
 }
