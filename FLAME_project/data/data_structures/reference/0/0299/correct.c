#include<stdio.h>
#include<string.h> 
void tuozhan(char a,char b)
{
	int i;
	for(i=1;a+i<b;i++)
	printf("%c",a+i);
}
int main() 
{
char a[200];
gets(a);
int i;
for(i=0;i<=199&&a[i]!='\0';i++)
{
	if(a[i]!='-')
	printf("%c",a[i]);
	else
	{
		if('0'<=a[i-1]&&a[i-1]<='9'&&'0'<=a[i+1]&&a[i+1]<='9')
			tuozhan(a[i-1],a[i+1]);
		else if('a'<=a[i-1]&&a[i-1]<='z'&&'a'<=a[i+1]&&a[i+1]<='z')
			tuozhan(a[i-1],a[i+1]);				
		else if('A'<=a[i-1]&&a[i-1]<='Z'&&'A'<=a[i+1]&&a[i+1]<='Z')
			tuozhan(a[i-1],a[i+1]);				
		else
			printf("%c",a[i]);		
	}

}
return 0;
}



