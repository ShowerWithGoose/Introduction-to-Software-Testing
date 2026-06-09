#include <stdio.h>
#include <string.h>
struct word
{
	char c[100];
	int num;
};
char ss[100];
void reset()
{
	int i;
	for(i=0;i<100;i++)
	{
		ss[i]='\000';
	}
	return;
}
int main()
{
	struct word w[100];
	int i,j=0,len,num=0,k,t=0,ll;
	char s[100],l[100];
	FILE *in;
	in=fopen("article.txt","r");
	for(;fgets(s,100,in)!=NULL;)
	{
		reset();
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]>='A' && s[i]<='Z')
			{
				s[i]=s[i]-'A'+'a';
			}
			else if(s[i]<='a' && s[i]>='z')
			{
				s[i]=' ';
			}
		}
		for(i=0;i<len;i++)
		{
			if(s[i]>='a' && s[i]<='z')
			{
				ss[j]=s[i];
				j++;
			}
			else if(strlen(ss)!=0)
			{
				for(k=0;k<num;k++)
				{
					if(strcmp(ss,w[k].c)==0)
					{
						w[k].num++;
						t=1;
					}
				}
				if(t==0)
				{
					strcpy(w[num].c,ss);
					w[num].num=1;
					num++;
				}
				j=0;
				t=0;
				reset();
			}
		}
	}
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(strcmp(w[j].c,w[j+1].c)>0)
			{
				strcpy(l,w[j].c);
				strcpy(w[j].c,w[j+1].c);
				strcpy(w[j+1].c,l);
				ll=w[j].num;
				w[j].num=w[j+1].num;
				w[j+1].num=ll;
			}
		}
	}
	for(i=0;i<num;i++)
	{
		printf("%s %d\n",w[i].c,w[i].num);
	}
	return 0;
}

