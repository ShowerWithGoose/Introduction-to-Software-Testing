#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define e 2.718281
#define pi 3.14159265

char c,dan[1000][100];int flag,i,j,k[1000],s;char temp[100];
int main()
{
	FILE *in, *out; // 为读写文件定义文件指针
	in = fopen("article.txt","r");

	if(NULL == in) 
	{
		printf ("Failed to open the file !\n");
		exit(0);
	}
	while ((c = fgetc(in)) != EOF) 
	{
		if(c>='A'&&c<='Z')c+='a'-'A'; 
		if(c>='a'&&c<='z')
		{
			dan[i][j++]=c;
			flag=1;
		}
		if(flag==1&&(c<'a'||c>'z'))i++,flag=0,j=0;
	}
	int max=i;
	for(i=0;i<max;i++)k[i]++;
	for(i=0;i<max-1;i++)
	{
		for(j=0;j<max-1-i;j++)
		{
			if(strcmp(dan[j],dan[j+1])>0)
			{
				strcpy(temp,dan[j]);
				strcpy(dan[j],dan[j+1]);
				strcpy(dan[j+1],temp);
			}
		}
	}
	for(i=0;i<max;i++)
	{
		if(k[i]==0)continue;
		for(j=i+1;j<max;j++)
		{
			if(strcmp(dan[i],dan[j])==0)
			{
				memset(dan[j],'z',strlen(dan[j]));
				k[i]++;
				flag++;
				k[j]=0;
			}
		}
	}
	for(i=0;i<max-1;i++)
	{
		for(j=0;j<max-1-i;j++)
		{
			if(strcmp(dan[j],dan[j+1])>0)
			{
				strcpy(temp,dan[j]);
				strcpy(dan[j],dan[j+1]);
				strcpy(dan[j+1],temp);
			}
		}
	}
	for(i=0,j=0;i<max-flag;i++)
	{
		printf("%s",dan[i]);
		while(k[j]==0)j++;
		printf(" %d\n",k[j++]);
	}
	fclose(in);


	return 0;
}



