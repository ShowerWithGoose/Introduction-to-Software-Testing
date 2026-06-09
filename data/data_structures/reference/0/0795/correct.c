#include<stdio.h>
int main()
{
	char a[200]={'\0'},b[200]={'\0'};
	gets(a);
	char *p1;
	char*p2;
	int i=0,j=0,c;
	while(a[i]!='\0')
	{
	if(a[i]!='-') b[j]=a[i],i++,j++;
	else
	{
   	p1=&a[i-1];
	p2=&a[i+1];
	if(jiancha(p1,p2)!=0)
   	{
   	b[j]=a[i-1]+1;
   	while(b[j]<a[i+1])
   	{
      b[j+1]=b[j]+1;
      j++;
    }
      i=i+2;
      j++;
    }
    else
   	{
    b[j]=a[i],i++,j++;
   	}
  	}
    }
    puts(b);
 	return 0;
} 
int jiancha(char *p1,char *p2)
 {
 	if(isdigit(*p1)!=0 &&isdigit(*p2)!=0&&(*p2-*p1)>0)
 	return 1;
 	else if(islower(*p1)!=0&&islower(*p2)!=0&&(*p2-*p1)>0)
 	return 2;
 	else if(isupper(*p1)&&isupper(*p2)&&(*p2-*p1)>0)
 	return 3;
 	else
 	return 0;
 }

