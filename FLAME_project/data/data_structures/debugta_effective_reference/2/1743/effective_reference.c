#include<stdio.h>
#include<math.h>
#include<string.h>


int f(char x[],int n)
{
char y[10][50]={0};
int num[10]={0}; 	
int sum=0;
int i=0,j=1,k=0,p=0,q=0; 	
for(k=0;k<n;k++)	
 {
 if(x[k]=='*')
  {
  p++;y[p][0]='*';
  for(i=i;i<k;i++)
   {
   y[p][j]=x[i];
   j++;  	
   }
  i++;
  j=1; 	
  } 
 if(x[k]=='/')
  {
  p++;y[p][0]='/';
  for(i=i;i<k;i++)
   {
   y[p][j]=x[i];
   j++;  	
   }
  i++;
  j=1; 	
  }   	
 }  
p++;
y[p][0]='0';
for(i=i;i<k;i++) 
 {
 y[p][j]=x[i];	
 j++;
 }
i=1;
for(i=1;i<=p;i++) 
 {
 num[i]=0;	
 j=1;	
 for(j=1;j<strlen(y[i]);j++)
 num[i]=num[i]*10+y[i][j]-'0';	
 } 
i=1;
sum=num[1];
for(i=1;i<p;i++)
 {
 if(y[i][0]=='*')
 sum=sum*num[i+1];
 else
 sum=sum/num[i+1];	
 } 
return sum;   	
}





int main()
{
int i,j,k,p,q;
int sum=0;
char op[10];	
char b[100],c[100]={0};
char x[10][50]={0};	
gets(b);
i=0;
j=0;
for(i=0;i<strlen(b)-1;i++)	
 {
 if(b[i]!=' ')
  {
  c[j]=b[i];
  j++;  	
  }	
 }	
k=0;p=0;q=0;i=0;j=0;
for(k=0;k<strlen(c);k++)	
 {
 if(c[k]=='+')
  {
  p++;op[p]='+';
  for(i=i;i<k;i++)
   {
   x[p][j]=c[i];
   j++;  	
   }
  i++;
  j=0; 	
  } 
 if(c[k]=='-')
  {
  p++;op[p]='-';
  for(i=i;i<k;i++)
   {
   x[p][j]=c[i];
   j++;  	
   }
  i++;
  j=0; 	
  }   	
 }
p++;
for(i=i;i<k;i++) 
 {
 x[p][j]=c[i];
 j++;	
 }
i=1;
sum=f(x[1],strlen(x[1]));	
for(i=1;i<p;i++)
 {
 if(op[i]=='+')
 sum=sum+f(x[i+1],strlen(x[i+1]));
 else
 sum=sum-f(x[i+1],strlen(x[i+1]));	
 } 
printf("%d",sum); 
return 0; 
}


