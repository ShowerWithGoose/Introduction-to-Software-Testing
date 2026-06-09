#include<stdio.h>
#include<string.h>
int head=1,tail=1,cnt=1;

struct node{
	char word[110];
	int next,before,sum;
}a[20000];
void stick(int x)
{
	int i;
	if(strcmp(a[x].word,a[head].word)<0){
		a[x].sum=1;
		a[x].next=head;
		a[head].before=x;
		a[x].before=-1;	
		head=x;
	}
	else if(strcmp(a[x].word,a[tail].word)>0){
		a[x].sum=1;
		a[x].next=-1;
		a[x].before=tail;
		a[tail].next=x;
		tail=x;	
	}
	else if(strcmp(a[x].word,a[head].word)==0){
		a[head].sum++;
	}
	else {
		for(i=a[head].next;i!=-1;i=a[i].next){
			if(strcmp(a[x].word,a[i].word)==0){
				a[i].sum++;
				break;
			}
			else if(strcmp(a[x].word,a[i].word)<0){
				a[x].before=a[i].before;
				a[a[i].before].next=x;
				a[x].next=i;
				a[i].before=x;
				a[x].sum=1;
				break;
			}
		}
	}
}
				

int main()
{
	int i,len;
	FILE *in;
	in=fopen("article.txt","r");
	fscanf(in,"%*[^a-zA-Z]");
	fscanf(in,"%[a-zA-Z]",a[1].word);
	len=strlen(a[cnt].word);
	for(i=0;i<len;i++)
		if(a[cnt].word[i]>='A'&&a[cnt].word[i]<='Z')a[cnt].word[i]+='a'-'A';
	a[1].next=-1;
	a[1].before=-1;
	a[1].sum=1;
	
	while(fscanf(in,"%[a-zA-Z]",a[++cnt].word)!=EOF)
	{
		fscanf(in,"%*[^a-zA-Z]");
//		printf("%s\n",a[cnt].word);
		len=strlen(a[cnt].word);
		for(i=0;i<len;i++)
			if(a[cnt].word[i]>='A'&&a[cnt].word[i]<='Z')a[cnt].word[i]+='a'-'A';
		stick(cnt);
	}
//	printf("\n\nfuck");
	for(i=a[head].next;i!=-1;i=a[i].next)
		printf("%s %d\n",a[i].word,a[i].sum);
	return 0;
}



