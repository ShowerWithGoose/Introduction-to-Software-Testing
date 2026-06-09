#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct COUNT{
    char word[1000];
    int num;
};
typedef struct COUNT count;
count a[1000];
int cmp(const void*a,const void*b) 
{
	struct COUNT *c=(struct COUNT*)a;
	struct COUNT *d=(struct COUNT*)b;
    return strcmp(c->word,d->word);
}
int main()
{
	char s;
    char str[1000],str2[1000];
    int i=0,j=0,k=0,tmp=0;
    FILE *fp1=fopen("article.txt","r");
   	s=fgetc(fp1);
    while(s!=EOF)
    {
        str[i]=s;
        i++;
        s=fgetc(fp1);
    }
    for(i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i])!=0)
        {
            str[i]=tolower(str[i]);
        }
	}
    for(i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i])!=0)
        {
            for(j=i;j<strlen(str);j++)
			{
				if(isalpha(str[j])==0)
				{
					break;
				}
			}
			memset(str2,0,sizeof(str2));
			for(k=0;k<j-i;k++)
			{
				str2[k]=str[i+k];
			}
			strcpy(a[tmp].word,str2);
			tmp++;
			i=j;
        }
	}
	qsort(a,tmp,sizeof(count),cmp);
	for(i=0;i<tmp;i++)
	{
		a[i].num=1;
	}
	for(i=0;i<tmp;i++)
    {
        if(strcmp(a[i].word,a[i+1].word)==0)
        {
            a[i+1].num=a[i+1].num+a[i].num;
			a[i].num=0;
        }
    }
    for(i=0;i<tmp;i++)
	{
		if(a[i].num!=0)
		{
			printf("%s %d\n",a[i].word,a[i].num);
		}
	}
	fclose(fp1);
    return 0;
}


