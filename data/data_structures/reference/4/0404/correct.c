#include<stdio.h>
#include<string.h>
#include<ctype.h>
int alpha(char a)
{
	if(a<='z'&&a>='a')
	{
		return 1;
	}
	else if(a<='Z'&&a>='A')
	{
		return 1;
	}
	else return 0;
}
void f(char s[100])
{
	int i,j;
	for(i=0;s[i]!='\0';i++)
	{
		if(isalpha(s[i])==0)
		{
			for(j=i;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
		}	
	} 
	
}
struct node{
	char cishu[100];
	int b;
} danci[1000],danci2[1000],danci1[1000],d;
///////////////////////
void paixu(int n,struct node danci2[1000],struct node d) 
{
 int i,j,flag;
 for(i=0;i<n-1;i++)
 {
  flag=0;
  for(j=0;j<n-1-i;j++)
  {
   if(strcmp(danci2[j].cishu,danci2[j+1].cishu)>0)
   {
    d=danci2[j];
    danci2[j]=danci2[j+1];
    danci2[j+1]=d;
    flag=1;
   }
  }
  if(flag==0)
   {
    break;
   }
 }
}
int main()
{
	char s[1000]={0};
	int a[1000]={0};
	int i=0,j,q=0,num,cnt,eof,flag;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(s,1000,in)!=NULL)
	{
		for(i=0;s[i]!='\0';i++)
		{
			flag=0;
			for(j=0;alpha(s[i])==1;j++,i++)
			{
				danci[q].cishu[j]=s[i];
				flag++;
			}
			if(flag!=0)
			{
				q++;
			}
		 } 
	}
	cnt=q;
	for(i=0;i<cnt;i++)
	{
		for(j=0;danci[i].cishu[j]!='\0';j++)
		{
		if(danci[i].cishu[j]<=90&&danci[i].cishu[j]>=65)
		{
			danci[i].cishu[j]=danci[i].cishu[j]+32;
		}
		}
		
	}
	for(i=0;i<cnt;i++)
	{
		
		for(j=i;j>=0;j--)
		{
			if(strcmp(danci[i].cishu,danci[j].cishu)==0)
			{
				a[j]++;
			}
			
		}	
			
			danci1[i]=danci[i];
			
	}	
	///////
	for(i=0;i<cnt;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(strcmp(danci1[i].cishu,danci1[j].cishu)==0)
			{
				a[i]=0;
				break;
			}
		}	
	}
	for(i=0,j=0;i<cnt;i++)
	{
		if(a[i]!=0)
		{
			strcpy(danci2[j].cishu,danci1[i].cishu);
			danci2[j].b=a[i];
			j++;
		}
	}
	num=j;
	paixu(num,danci2,d);
	for(i=0;i<j;i++)
	{
		printf("%s %d\n",danci2[i].cishu,danci2[i].b);
	}
	fclose(in);
}



