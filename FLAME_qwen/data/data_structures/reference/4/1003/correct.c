#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define tolower(c)((c)>='A'&&(c)<='Z'?'a'-'A'+(c):(c))
int compare(const void *a,const void *b)
{

	return (strcmp(a,b));

}
char name[300][55];
int nam[300];

struct tip1{
	char name[55];
	
	int cnt;
};
struct tip1 data1[300];



int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	//out=fopen("ordered.txt","w");
	int i=0;
	while((fscanf(in,"%s",name[i]))!=EOF)
	{
		int flag=0;
		for(int y=0;name[i][y]!='\0';y++)
		{
			name[i][y]=tolower(name[i][y]);
			if(name[i][y]>='a'&&name[i][y]<='z')
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			continue;
		}
		for(int y=0;name[i][y]!='\0';y++)//循环找单词 
		{
			
			if(name[i][y]<'a'||name[i][y]>'z')//遇到符号 
			{
				if(y-1>=0&&name[i][y-1]>='a'&&name[i][y-1]<='z'&&name[i][y+1]>='a'&&name[i][y+1]<='z')//遇到了前后都是单词的符号
				{
					i++;
					y++;
					int m=y-1;
					for(int x=0;name[i-1][y]!='\0';x++)
					{
						name[i][x]=name[i-1][y];
						y++;
					} 
					for(int x=m;name[i-1][x]!='\0';x++)
					{
						name[i-1][x]='\0';
					}
					y=-1;
					continue;
				} 
				else if(name[i][y+1]=='\0')//末尾符号 
				{
					name[i][y]='\0';
				}
				else//开头的符号 
				{
					for(int x=y;name[i][x+1]!='\0';x++)
					{
						name[i][x]=name[i][x+1];
						if(name[i][x+2]=='\0')
						{
							name[i][x+1]='\0';
						}
					}
					y=-1;
					continue;	
				}

			}
			

			
		}
		i++;
	} 
	fclose(in);
	int sum=i;
	int z=0;

	char s[300][55];
	memset(s,'\0',sizeof(s));
	for(int j=0;j<sum;j++)
	{
		for(int x=0;name[j][x]!='\0';x++)
		{
			s[j][x]=name[j][x];
		}
	}
	
	for(int j=0;j<sum;j++)
	{
		if(nam[j]!=1)
		{
			strcpy(data1[z].name,s[j]);
		}
		else{
			continue;
		}
		for(int x=0;x<sum;x++)
		{
			if(strstr(s[j],name[x])!=NULL&&strlen(s[j])==strlen(name[x])&&nam[x]!=1)
			{
				nam[x]=1;
				data1[z].cnt++;
			}
		}
		z++;
	}
	qsort(data1,z,sizeof(data1[0]) ,compare);
	int x=0;
	while(x<z)
	{	
		
		printf("%s %d\n",data1[x].name,data1[x].cnt);
		x++;
	}
	return 0;
}

