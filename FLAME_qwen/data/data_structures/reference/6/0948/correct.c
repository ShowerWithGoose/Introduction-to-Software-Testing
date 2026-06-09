#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

struct output{
	int flag;//Êý×ÖÎª0×Ö·û´®Îª1 
	union{
		int num;
		char s[6];
	};
}; 
int main()
{
	int top=-1;
	int n;
	int stack[MAXSIZE];
	struct output tmp[100];
	int i=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)break;
		
		
		else if(n==1)
			{
				scanf("%d",&n);
				if(top==MAXSIZE-1)
				{
					tmp[i].flag=1;
					strcpy(tmp[i].s,"error");
					i++;
				}
				else 
				{
					stack[++top]=n;
				}
			}
		else if(n==0)
			{
				if(top==-1)
				{
					tmp[i].flag=1;
					strcpy(tmp[i].s,"error");
					i++;
				}
				else 
				{
					tmp[i].flag=0;
					tmp[i].num=stack[top--];
					i++;
				}
			}
		
	}
	for(int j=0;j<i;j++)
	{
		if(tmp[j].flag==0)
			printf("%d ",tmp[j].num);
		else if(tmp[j].flag==1)
			printf("%s ",tmp[j].s);
	}
	return 0;
}

