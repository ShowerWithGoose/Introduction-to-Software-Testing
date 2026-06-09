#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char ci[103];
	int zhi;
	int ge;
}a[1003];
char s[10007];
char t[10007];
int lens,n=0,pt;
int pdzm(char c)
{
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))return 1;
	else return 0;
}
int cmp(const void*s,const void*t)
{
	struct node*pt=(struct node*)(s),*ps=(struct node*)(t);
	return strcmp(((struct node*)pt)->ci,((struct node*)ps)->ci);
}
int main()
{
	FILE *fp=NULL;
	fp=fopen("article.txt","r");
	while(fgets(s,10007,fp)!=NULL)
	{
		int i;
		lens=strlen(s);
		for(i=0;i<lens;i++)
		{
			if(!pdzm(s[i]))continue;
			if(!pdzm(s[i-1])){pt=0;memset(t,0,sizeof(t));}
			if(s[i]>='A'&&s[i]<='Z')s[i]+=32;
			t[pt]=s[i];pt++;
			if(!pdzm(s[i+1]))
			{
				t[pt]='\0';
				int j,pd=0,k=atoi(t);
				for(j=1;j<=n;j++)
			        if(strcmp(t,a[j].ci)==0)
					{
						pd=1;a[j].ge++;break;
					}
				if(!pd)
				{
					n++;strcpy(a[n].ci,t);
					a[n].zhi=k;
					a[n].ge=1;
					qsort(a+1,n,sizeof(a[1]),cmp);
				}
			}
		}
	}
	int i;
	for(i=1;i<=n;i++)printf("%s %d\n",a[i].ci,a[i].ge);
	return 0;
} 

