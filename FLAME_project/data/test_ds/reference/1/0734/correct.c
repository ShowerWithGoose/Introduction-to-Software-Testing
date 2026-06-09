#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(type,a,b) {type t=a;a=b;b=t;}
char a[1005],b[1005];
int i,j;
int len;
char temp;
int examin(int x)
 {	int flag=0;
 	if(a[x-1]<='9'&&a[x-1]>='0'&&a[x+1]<='9'&&a[x+1]>='0'&&a[i+1]>a[i-1])
 	flag=1;
 	else if(a[x-1]<='Z'&&a[x-1]>='A'&&a[x+1]<='Z'&&a[x+1]>='A'&&a[i+1]>a[i-1])
 	flag=1;
 	else if(a[x-1]<='z'&&a[x-1]>='a'&&a[x+1]<='z'&&a[x+1]>='a'&&a[i+1]>a[i-1])
 	flag=1;
 	if(flag==0)
 	return 0;
 	
 	len=a[i+1]-a[i-1]-1;
 	return 1;
	 
 	
 }
int main()
{	int k=0;
	gets(a);
	for(i=0,j=0;a[i]!='\0';i++){
	if(a[i]!='-') 
		{b[j]=a[i];j++;
		}
	else {
		if(examin(i)==1)//前后字符在同一维度里 
		{
		temp=a[i-1]+1;
		for(k=0;k<len;k++,j++)//len长度为a[i+1]-a[i-1]-1 
		b[j]=temp+k;
		}
		else {b[j]=a[i];j++;
		}
	}
	 }	 
	puts(b);
	return 0;	
	 
	 
	 	
	
	}
	


