#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
// BY: JAIMIN SHAH
int main()
{
 char a[20],a2[20]="",a3[20]="",a4[20]="",a5[20]="",a6[20]="";
 int i,j,len_min,len_max;
 printf("Enter Grammer");
 scanf("%s",a);
 i=0;
 while(a[i]!='/')
 {
 a2[i]=a[i];
 i++;
 }
 a2[i]='\0';
 i++;
 printf("a=%d\n",strlen(a));
 for(j=0;i!=strlen(a);i++,j++)
 {
 a3[j]=a[i];
 }
 len_min=((strlen(a2)<=strlen(a3))?strlen(a2):strlen(a3));
 len_max=((strlen(a2)>strlen(a3))?strlen(a2):strlen(a3));
 for(i=0;i<=len_min;i++)
 {
 if(a2[i]==a3[i])
 {
 a4[i]=a2[i];
 }
 else
 {
 a4[i]='X';
 break;
 }
 }
 j=0;
 if(i!=len_max)
 {
 if(a2[i]!='\0')
 a5[j]=a2[i];
 else
a5[j]='@';
 if(a3[i]!='\0')
 a6[j]=a3[i];
 else
a6[j]='@';
 }
 printf("\nA=%s\n",a4);
 printf("X=%s / %s",a5,a6);
 //getch();
}
