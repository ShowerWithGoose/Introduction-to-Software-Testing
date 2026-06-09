#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct word{
	char word[30];
	int num;
};
int cmp(const void *a, const void *b);
int main()
{
	FILE *in;
	in = fopen("article.txt","r");
	struct word a[120];
	
	char ch;
	ch = fgetc(in);
	int i=0,j=0;
	while(ch != EOF)
	{
		
		if(isalpha(ch))
		{
			ch = tolower(ch);          //转小写 
			a[i].word[j] = ch;
			j++;
		
		}
		else if(ispunct(ch) || isspace(ch) )
		{
			a[i].word[j] = '\0';             //手动给字符串关闭 
			i++;
			j=0; 
			
		}
		ch = fgetc(in);
	}                                  //保存单词
	
	 int cnt = i;
	 int l;
	 for(l=0;l<cnt;l++)
	 	a[l].num = 1;
	 int k;
	 for(k=0;k<cnt;k++)
	 {
	 	int p;
	 	for(p=k+1;p<cnt;p++)
	 	{
	 		if(0 == strcmp(a[k].word,a[p].word))
	 		{
	 			a[k].num = a[k].num+1;
	 			a[p].word[0] = '\0';
			 }
		 }
	 	
	 }
	qsort(a,cnt,sizeof(a[0]),cmp);
	int y;
	for(y=0;y<cnt;y++)
	{
		if(a[y].word[0] != '\0')
		{
			int m=0;
			while(a[y].word[m] != '\0')
				printf("%c",a[y].word[m++]);
			printf(" ");
			printf("%d",a[y].num);
			printf("\n");
		}
	}
	
	fclose(in);
	return 0;
}

int cmp(const void *a, const void *b){
	struct word *aa = (struct word *)a;
	struct word *bb = (struct word *)b;
	if(strcmp(aa->word,bb->word) > 0 )
		return 1;
	return -1;
}


