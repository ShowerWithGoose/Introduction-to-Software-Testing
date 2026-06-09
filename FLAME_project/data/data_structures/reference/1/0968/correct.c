#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char arr[10];int n;
void swap(char *a,char *b)
{
	char c;
	c=*a;*a=*b;*b=c;
}
void sequence(char *s,int head,int tail)
{
	int i,j;
	for(i=head;i<tail;i++)
	{
		for(j=i+1;j<=tail;j++)
		{
			if(s[i]>s[j]) swap(&s[i],&s[j]);
		}
	}
}
void arrange(char *s,int layer,int top)
{
	if(layer==top)
	{
		int i;
		for(i=0;i<n;i++)
		{
			printf("%c ",s[i]);
		}
		printf("\n");
	}
	else 
	{
		int i;
		for(i=0;i<=top-layer;i++)
		{
			sequence(s,layer,top);
			swap(&s[layer],&s[i+layer]);
			sequence(s,layer+1,top);
			arrange(s,layer+1,top);
			swap(&s[layer],&s[i+layer]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	arr[i]=i+'0'+1;
	arr[i]='\0';
	arrange(arr,0,n-1); 
	return 0; 
} 

