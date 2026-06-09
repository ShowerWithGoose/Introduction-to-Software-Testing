#include<stdio.h>
#include<string.h>
char a[100][100];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j=0,n=0;
	char c=fgetc(in);
	while(c!=EOF)
	{
		
		while((c>96&&c<123)||(c>64&&c<91))
		{
			if(c>64&&c<91)
			{
				c=c+32; 
			}
			a[i][j]=c;
			j++;
			c=fgetc(in);
		}
		i++;
		j=0;
		while(!((c>64&&c<91)||(c>96&&c<123)))
		{
			c=fgetc(in);
			if(c==EOF)
			{
				break;
			}
		}
		if(c==EOF)
		{
			break;
		}
	}
	int num=i,k=0;
	char b[100];
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<=num;j++)
		{
			if(strcmp(a[i],a[j])>0)
			{
				strcpy(b,a[j]);
				strcpy(a[j],a[i]);
				strcpy(a[i],b);
			}
		}
	}
	int jishu=1;
	for(i=0;i<=num;i++)
	{
		if(a[i][0]!=0)
		{
			for(j=i+1;j<=num;j++)
			{
				if(strcmp(a[i],a[j])==0)
				{
					a[j][0]=0;
					jishu++;
				}
			}
			printf("%s %d\n",a[i],jishu);
			jishu=1;
		}
	}
	
}



