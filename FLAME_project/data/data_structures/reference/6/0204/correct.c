#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
 int s1[1024],s2[1024],stack[105];
 int n=0,i=0,j=0,m=0,k=0; 
 while(scanf("%d",&s1[n++])!=EOF&&s1[n-1]!=-1);//£¨s1[n-1]=-1) 
 //for(i=0;i<n;i++)
 //printf("%d",s1[i]);
 //printf("%d",s1[n-1]);
 int k_;
 for(i=0,j=0;i<n-1;i++)
 {
  if(s1[i]==1||s1[i]==0)
  {
   s2[j++]=s1[i];
   if(i!=n-2)
   {
       for(k_=i;k_<n-1;k_++)
       s1[k_]=s1[k_+1];
       i--;
   }  
  }
  else continue;
 }
 m=j;
 s2[m]=-1;
 //for(i=0;i<=m;i++)
 //printf("%d",s2[i]);
  
 for(i=0,j=0;j<=m;j++)
 {
  if(s2[j]==1)
  {
   if(k==99)
      {
       printf("error ");
   }
    else
   {
       stack[k++]=s1[i++];
      }
  }
  if(s2[j]==0)
  {
   if(k==0)
   {
    printf("error ");
   }
   else 
   {
     k--;
       printf("%d ",stack[k]);
   }
  }
  if(s2[j]==-1)
  break;
 }

 return 0; 
}

