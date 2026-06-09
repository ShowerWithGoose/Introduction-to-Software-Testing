#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(const void* ,const void*);
struct linknode
{char name[15];
int number;
};
struct linknode word[100];
int main()
{char an[15],c;
int n=0,i=0,j,op;
FILE *in;
in=fopen("article.txt","r");
while((c=fgetc(in))!=EOF)
	{if(c>='a'&&c<='z')
		{
		an[i]=c;
		i++;
		}
	else if(c>='A'&&c<='Z')
		{
		an[i]=c-'A'+'a';
		i++;
		}
	else if(i!=0)
		{an[i]='\0';
		op=0;
		for(j=0;j<n;j++)
			{if(strcmp(an,word[j].name)==0)
				{op=1;
				word[j].number++;
				break;
				}
			}
		if(op==0)
			{strcpy(word[n].name,an);
			word[n].number=1;
			n++;
			}
		i=0;
		}
	}
qsort(word,n,sizeof(word[0]),comp);
for(i=0;i<n;i++)
	{printf("%s %d\n",word[i].name,word[i].number);
	}
return 0;
}
int comp(const void *p1,const void *p2)
{struct linknode *a=(struct linknode*)p1;
struct linknode *b=(struct linknode*)p2;
return strcmp(a->name,b->name);
}

