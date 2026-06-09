#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int n=0;//单词个数 
struct node{
	char word[32];
	int num;
};//单词表;
int get(FILE *fp, char *w)//从文件中读单词 
{
	int c;
	while(!isalpha(c=fgetc(fp)))
	{
		if(c==EOF) return c;
		else 
		continue;
	}
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}
int search(struct node words[], char *w)
{
	int low=0,high=n-1,mid=0;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(strcmp(w,words[mid].word)<0)//往前走
		high=mid-1;
		else if (strcmp(w,words[mid].word)>0)
		low=mid+1;
		else //找到 
		{
			words[mid].num++;
			return 0; 
		 } 
	}
	return insert(words,low,w);
} 
int insert(struct node words[], int position,char *w)
{
	int i;
	for(i=n-1;i>=position;i--)
	{
		strcpy(words[i+1].word,words[i].word);//单词往后移 
		words[i+1].num=words[i].num;//次数往后移 
	}
	strcpy(words[position].word,w);
	words[position].num=1;
	n++;
	return 1;
}
int main()
{
	struct node words[1005];
	int i;
	char word[1005];
	FILE *fp;
    fp=fopen("article.txt","r");
	while(get(fp,word)!=EOF) 
	if(search(words,word)==-1)
	{
		fprintf(stderr,"Wordlist is full\n");
		return -1;
	 } 
	 for(i=0;i<=n-1;i++)
	 {
	 	printf("%s %d\n",words[i].word,words[i].num);
	 }
	 return 0;
}

