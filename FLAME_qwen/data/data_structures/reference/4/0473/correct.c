#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
FILE *in,*out;
struct god
{
	char word[50];
	int day;
}t[10010];
char ch[10010],sta[10010];
int cnt1=0,cnt2=0;
void cal()
{
	for(int i=1;i<=cnt2;i++)
	{
		if(strcmp(sta+1,t[i].word+1) != 0) continue;
		
		t[i].day++;
		return;
	}
	t[++cnt2].day=1;
	strcpy(t[cnt2].word+1,sta+1);
}
int cmp(const void *a,const void *b)
{
	struct god n1 = *(struct god *)a;
	struct god n2 = *(struct god *)b;
	
	if(strcmp(n1.word + 1,n2.word + 1) > 0) return 1;
	return -1;
	
}
int main()
{
	in = fopen("article.txt","r");
	while(fgets(ch+1,10000,in) != NULL)
	{
		//puts(ch+1);
		cnt1=0;
		int len=strlen(ch+1);
		for(int i=1;i<=len;i++)
		{
			if(ch[i] >= 'A' && ch[i] <= 'Z') ch[i] = ch[i] - 'A' + 'a';
			if(ch[i] < 'a' || ch[i] > 'z')
			{
				if(cnt1) sta[++cnt1]='\0',cal(),cnt1=0;
			    continue;
			}
			
			sta[++cnt1] = ch[i];
		}
	}
	qsort(t+1,cnt2,sizeof(t[0]),cmp);
	for(int i=1;i<=cnt2;i++) 
	 printf("%s %d\n",t[i].word+1,t[i].day);
	return 0;
}

