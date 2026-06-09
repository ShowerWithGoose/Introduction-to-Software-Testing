#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char ch[100];
char exch[100];
bool check(char a,char b)
{
	if(a>='0'&&a<='9'&&b>='0'&&b<='9') return true;
	else if(a>='a'&&a<='z'&&b>='a'&&b<='z') return true;
	else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z') return true;
	else return false;
}

int main()
{
	scanf("%s",ch);
	//int length=strlen(ch);
	int i,j;
	for(i=0,j=0;ch[i]!='\0';i++,j++)
	{
		if(ch[i]=='-'&&check(ch[i-1],ch[i+1]))
		{
			for(int k=1;k<ch[i+1]-ch[i-1];k++)
			{
				exch[j++]=ch[i-1]+k;
			}
			j--;
		}
		else exch[j]=ch[i];
	}
	
	printf("%s",exch);
}



