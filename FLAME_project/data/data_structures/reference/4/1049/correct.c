#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 32
#define MAXSIZE 1024
char w[20];
int N;
struct Inode{
	char word[MAXWORD];
	int count;
};
int getWord(FILE *in){
	int i;
	char ch;
	i=0;
	while(!isalpha(ch=fgetc(in))){
		if(ch==EOF) return ch;
		else continue;
	}
	do{
		w[i++]=tolower(ch);
	}while(isalpha(ch=fgetc(in)));
	w[i]='\0';
	return 1;
}
int searchWord(struct Inode list[])
{
	int low=0;
	int high=N-1,mid=0;
	while(low<=high){
		mid=low+(high-low)/2;
		if(strcmp(w,list[mid].word)<0) high=mid-1;
		else if(strcmp(w,list[mid].word)>0) low=mid+1;
		else{
			list[mid].count++;
			return 0;
		}
	}
	return insertWord(list,low);
}
int insertWord(struct Inode list[],int pos)
{
	int i=0;
	if(N==MAXSIZE) return -1;
	for(i=N-1;i>=pos;i--){
		list[i+1]=list[i];
	}
	strcpy(list[pos].word,w);
	list[pos].count=1;
	N++;
	return 1;
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	struct Inode wordlist[MAXSIZE];
	int i;
	while(getWord(in)!=EOF)
	{
		if(searchWord(wordlist)==-1){
			return -1;
		}
	}
	for(i=0;i<=N-1;i++) printf("%s %d\n",wordlist[i].word,wordlist[i].count);
	fclose(in);

return 0;
}


