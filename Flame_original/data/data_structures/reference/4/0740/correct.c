#include<stdio.h>
#include<string.h>
#define tolower(c) (c>='A'&&c<='Z'?'a'-'A'+c:c)
struct LINE {
	char let[1000];
	int num;
}; 
struct LINE line[100000];

int cmp(const void*p,const void *q)
{
    struct LINE *w=(struct LINE*)p;
    struct LINE *e=(struct LINE*)q;
    if(strcmp(w->let,e->let)<0) return -1;
    else return 1;
}

int main()
{
	FILE *in;
	int i,j=0,n=0,l=0;
	char str[100000],ch[1000],ex[100];
	in=fopen("article.txt","r");
	while(fgets(ch,100,in)!=NULL)
	{
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]>='a'&&ch[i]<='z'||ch[i]>='A'&&ch[i]<='Z')
			{
				str[j]=tolower(ch[i]);j++;
			}
			else if((ch[i]<'A'||ch[i]>'Z'&&ch[i]<'a'||ch[i]>'z'))
			{
				str[j]=' ';j++;
			}
		}
		str[j]=' ';j++; 
	}
	for(i=0;i<j-1;i++)
	{
		if(str[i]!=' ')
		{
			n=0;
			ex[0]=str[i];i++;n++;
			while(str[i]!=' ')
			{
				ex[n]=str[i];n++;i++;
			}
			strcpy(line[l].let,ex);
			memset(ex,0,sizeof(ex));
			i--;l++;
		}
	}
	for(i=0;i<l;i++)
	line[i].num=1;
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(strcmp(line[i].let,line[j].let)==0)
			{
			for(n=j;n<l;n++)
				line[n]=line[n+1];
			line[i].num++;l--;j=i;
		    }
		}
	}
	qsort(line,l,sizeof(line[0]),cmp);
	for(i=0;i<l;i++)
	printf("%s %d\n",line[i].let,line[i].num);
}

