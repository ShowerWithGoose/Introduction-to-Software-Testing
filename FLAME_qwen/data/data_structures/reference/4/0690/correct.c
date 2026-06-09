#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct words{ 
	char word[200];
	int times;
}a[1000];
char s[1000],ch;
int i=0,j,k,cnt=0;
int cmp(const void*p1,const void*p2)
{
	struct words *a=(struct words*)p1;
	struct words *b=(struct words*)p2;
	return strcmp(a->word,b->word);
}
int main()
{	
	FILE *in = fopen("article.txt","r");
	ch=fgetc(in);
	do{
		if(ch>='A'&&ch<='Z')
		s[i]=ch+'a'-'A';
		else
		s[i]=ch;
		i++;
		ch=fgetc(in);
	}while(ch!=EOF);
	int size=i;
	for(i=0;i<size;i++)
	{
		k=0;
		if(s[i]>='a'&&s[i]<='z')
		{
			for(j=i;j<size;j++){
				if(s[j]>='a'&&s[j]<='z')
				a[cnt].word[k++]=s[j];
				else
				break;
			}
			cnt++;
			i=j;
		}
	}
	qsort(a,cnt,sizeof(struct words),cmp);
	for(i=0;i<cnt;i++) 
	a[i].times=1;
	for(i=0;i<cnt;i++){
		if(strcmp(a[i].word,a[i+1].word)==0)
		a[i+1].times+=a[i].times;
		else 
		printf("%s %d\n",a[i].word,a[i].times);
	}
	return 0;
}

