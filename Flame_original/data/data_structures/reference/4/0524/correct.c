#include<stdio.h>
#include<string.h>
struct list
{
	int num;
	char a[105];
}
list[105],e;
int main()
{
	int i=0,j=0,k=0,len=0,b=0;
	char c,d[105]={0};
	FILE *fp;
	fp=fopen("article.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			d[i]=c+32;
			i++;
		}
		else if(c>='a'&&c<='z')
		{
			d[i]=c;
			i++;
		}
		else if(i!=0)
		{
			for(j=0;j<len;j++)
			{
				if(strcmp(d,list[j].a)==0)
				{
					list[j].num++;
					b=1;
					break;
				}
		    }
		    if(b==0)
			{
				strcpy(list[len].a,d);
				list[len].num=1;
				len++;
		    }
			for(k=0;k<105;k++)
			d[k]='\0';
			b=0;
			i=0;
		}
	}
	for(i=0;i<len;i++)
	{
		for(j=i;j<len;j++)
		{
			if(strcmp(list[i].a,list[j].a)>0)
			{
				e=list[i];
				list[i]=list[j];
				list[j]=e;
			}
		}
	}
	for(i=0;i<len;i++)
	printf("%s %d\n",list[i].a,list[i].num);
	fclose(fp);
	return 0;
}

