#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s1[200],s2[200],fu[200],fu2[200];
int num1[200],num2[200];
int main()
{ int l1,l2,i,j,k=0,d=0,sum=0,y,n,sign;
  gets(s1);
  l1=strlen(s1);
  for(i=0;i<l1;i++)
  {if(s1[i]!=' ')
   {s2[k]=s1[i];
    k++;
   }
  }
  s2[k]='\0';
  l2=strlen(s2);
  k=0;
  n=0;
  for(i=0;i<l2;i++)
  { for(j=k;isdigit(s2[j])>0;j++)
    n=10*n+s2[j]-'0';
    k=j+1;
    num1[i]=n;
    n=0;
    fu[i]=s2[j];
  	{if(fu[i]=='=')
  	 break;
	  }
  }
  k=0;
  y=num1[0];
  for(j=0;j<=i;j++)
  { if(j>=1)
    {if(fu[j-1]=='+'||fu[j-1]=='-')
    y=num1[j];}
    if(fu[j]=='+'||fu[j]=='-'||fu[j]=='=')
	{num2[k]=y;
	 fu2[k]=fu[j];
	 k++;
     }
	if(fu[j]=='*')
	{  
	   y*=num1[j+1];	
	}
  	if(fu[j]=='/')
	{  
	   y/=num1[j+1];	
	}
  }
  sum=num2[0];
  for(j=0;j<k;j++)
  {
  	if(fu2[j]=='+')
  	sum+=num2[j+1];
  	if(fu2[j]=='-')
  	sum-=num2[j+1];
  	
  }
   printf("%d",sum);
  return 0;
}


