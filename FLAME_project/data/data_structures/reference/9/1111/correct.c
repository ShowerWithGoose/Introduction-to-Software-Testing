#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 int n;
 int Line[100][5];
void sort(int s[][5],int n);
void bind(int s[][5],int n);
int main()
{
int i,k=0;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {scanf("%d%d%d%d",&Line[i][0],&Line[i][1],&Line[i][2],&Line[i][3]);}
 sort(Line,n);
 bind(Line,n);
for(i=0;i<n;i++)
 {
  if(Line[i][4]>Line[k][4])k=i; //printf("%d %d %d %d %d\n",Line[i][4],Line[i][0],Line[i][1],Line[i][2],Line[i][3]);
 }
 printf("%d %d %d",Line[k][4],Line[k][0],Line[k][1]);
 return 0;
}
void sort(int s[][5],int n)
{
 int i,j,k,tmp;
  for(i=0;i<n;i++)
  {
    for(j=i;j<n;j++)
    {
     if(s[j][0]<s[i][0])
     {
      for(k=0;k<5;k++)
      {tmp=s[j][k];s[j][k]=s[i][k];s[i][k]=tmp;}
     }
    }
  }
}
void bind(int s[][5],int n)
{
 int i,j,k;
 for(i=0;i<n;i++)
 {
  k=1;
  for(j=i;j<n;j++)
  {
    if((s[i][2]==s[j][0])&&(s[i][3]==s[j][1]))
    {s[i][2]=s[j][2];s[i][3]=s[j][3];k++;}
  s[i][4]=k;
  }
 }
}

