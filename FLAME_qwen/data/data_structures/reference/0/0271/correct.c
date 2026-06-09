#include<stdio.h>
#include<string.h>
#include<ctype.h>
char c[1000];
char b[1000];
int Cmp(char a,char b)
{
	if(islower(a)&&islower(b)) return 1;
	else if(isupper(a)&&isupper(b)) return 1;
	else if(isdigit(a)&&isdigit(b)) return 1;
	else return 0;
}
void KZ(char x,char y)
{
	int dis=y-x;
	int z;
	for(z=1;z<dis;z++)
	printf("%c",x+z);
}
int main()
{
	int i,j,len;
	scanf("%s",c);
	len=strlen(c);
	for(i=0;i<len;i++)
	{
		if(c[i]=='-')
		{
			if(!Cmp(c[i-1],c[i+1])) 
			{
				printf("-");
				continue;
			}
			else 
			{
				KZ(c[i-1],c[i+1]);
				i++;
			}
		}
		printf("%c",c[i]);
	}
	
}



